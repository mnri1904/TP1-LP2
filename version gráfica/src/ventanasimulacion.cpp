#include "ventanasimulacion.h"
#include "ui_ventanasimulacion.h"
#include "gameconfig.h"

#include <QLayoutItem>

/*
 * Constructor de la ventana de simulación.
 *
 * Se encarga de:
 * - Inicializar la interfaz gráfica (setupUi)
 * - Crear el timer que controla los ciclos de simulación
 * - Crear el ecosistema inicial
 * - Crear la vista gráfica (VistaEcosistema)
 * - Insertar la vista dentro del layout del UI
 */
VentanaSimulacion::VentanaSimulacion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaSimulacion)
    , timer(new QTimer(this))
    , filas(3)
    , columnas(3)
{
    ui->setupUi(this);
    
    // Conecta el timer con la función que avanza la simulación
    connect(timer, &QTimer::timeout, this, &VentanaSimulacion::tickSimulacion);

    // Se crea el ecosistema inicial
    eco = std::make_unique<Ecosistema>(filas, columnas);
    eco->inicializarEstado();

    // Se crea la vista gráfica del ecosistema
    vista = new VistaEcosistema(this);

    // Si el contenedor no tiene layout, se crea uno
    if (!ui->tableTablero->layout())
        ui->tableTablero->setLayout(new QVBoxLayout());

    // Se agrega la vista al layout
    ui->tableTablero->layout()->addWidget(vista); // o directamente setCentralWidget si quieres full screen

    // Redibuja la vista
    vista->update();
}

//destructor (eco se libera automáticamente por unique_ptr)
VentanaSimulacion::~VentanaSimulacion()
{
    delete ui;
}

/*
 * Configura el ecosistema usando los valores actuales de configuración global (gSettings).
 *
 * Se encarga de:
 * - Leer filas y columnas
 * - Crear un nuevo ecosistema
 * - Asociarlo a la vista
 * - Actualizar iconos
 * - Mostrar ciclo actual
 */
void VentanaSimulacion::configurarDesdeEcosistema()
{
    filas = gSettings.filas;
    columnas = gSettings.columnas;

    eco = std::make_unique<Ecosistema>(filas, columnas);
    eco->inicializarEstado();

    vista->setEcosistema(eco.get());
    vista->actualizarIconos();
    vista->update();

    ui->lblCiclo->setText(QString::number(eco->getCiclo()));
}

/*
 * Aplica la configuración actual del usuario.
 *
 * Detiene la simulación y reconstruye todo el ecosistema
 * con los nuevos parámetros.
 */
void VentanaSimulacion::aplicarConfiguracionActual()
{
    timer->stop();
    configurarDesdeEcosistema();
}

// Calcula y actualiza los contadores de entidades en la UI.
void VentanaSimulacion::actualizarContadores()
{
    int P = 0, H = 0, C = 0;

    const auto &tablero = eco->getTablero();

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(tablero[i][j] == 'P') P++;
            else if(tablero[i][j] == 'H') H++;
            else if(tablero[i][j] == 'C') C++;
        }
    }

    ui->lblPlantas->setText(QString::number(P));
    ui->lblHerbivoros->setText(QString::number(H));
    ui->lblCarnivoros->setText(QString::number(C));
}

/*
 * Función que se ejecuta en cada "tick" del timer.
 *
 * Representa un ciclo de simulación:
 * - Avanza el ecosistema
 * - Actualiza el número de ciclo
 * - Redibuja la vista
 */
void VentanaSimulacion::tickSimulacion()
{
    eco->avanzarCiclo();

    ui->lblCiclo->setText(QString::number(eco->getCiclo()));

    actualizarContadores();

    vista->update();
}

void VentanaSimulacion::on_btnIniciar_clicked()
{
    if (!timer->isActive()) {
        timer->start(3000);
    }
}

void VentanaSimulacion::on_btnPausar_clicked()
{
    timer->stop();
}

/*
 * Botón "Reiniciar".
 *
 * Reinicia completamente el ecosistema:
 * - Detiene la simulación
 * - Crea un nuevo ecosistema
 * - Lo vuelve a vincular a la vista
 * - Reinicia el contador de ciclos
 */
void VentanaSimulacion::on_btnReiniciar_clicked()
{
    timer->stop();

    eco = std::make_unique<Ecosistema>(filas, columnas);
    eco->inicializarEstado();

    vista->setEcosistema(eco.get());  // importante
    vista->update();

    ui->lblCiclo->setText(QString::number(eco->getCiclo()));
}

void VentanaSimulacion::on_btnMenu_clicked()
{
    timer->stop();
    emit volverAlMenu();
}
