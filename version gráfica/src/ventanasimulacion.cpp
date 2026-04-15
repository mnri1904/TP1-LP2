#include "ventanasimulacion.h"
#include "ui_ventanasimulacion.h"
#include "gameconfig.h"

#include <QLayoutItem>

VentanaSimulacion::VentanaSimulacion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaSimulacion)
    , timer(new QTimer(this))
    , filas(3)
    , columnas(3)
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &VentanaSimulacion::tickSimulacion);

    eco = std::make_unique<Ecosistema>(filas, columnas);
    eco->inicializarEstado();

    vista = new VistaEcosistema(this);
    //vista->setEcosistema(&eco);
    if (!ui->tableTablero->layout())
        ui->tableTablero->setLayout(new QVBoxLayout());

    ui->tableTablero->layout()->addWidget(vista); // o directamente setCentralWidget si quieres full screen

    vista->update();
}

VentanaSimulacion::~VentanaSimulacion()
{
    delete ui;
}

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

void VentanaSimulacion::aplicarConfiguracionActual()
{
    timer->stop();
    configurarDesdeEcosistema();
}

/*
void VentanaSimulacion::construirTableroVisual()
{
    vaciarLayout(layoutTablero);

    layoutTablero->setSpacing(0);
    layoutTablero->setContentsMargins(0,0,0,0);

    //labelsTablero.resize(filas);
    labelsTablero.assign(filas, std::vector<QLabel*>(columnas, nullptr));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            auto *label = new QLabel();
            label->setFixedSize(48, 48);
            label->setAlignment(Qt::AlignCenter);
            label->setScaledContents(true);
            label->setStyleSheet(R"(
                border: none;
                margin: 0px;
                padding: 0px;
            )");

            layoutTablero->addWidget(label, i, j);
            labelsTablero[i][j] = label;
        }
    }
}
*/
/*
void VentanaSimulacion::actualizarVista()
{
    const auto &tablero = eco->getTablero();

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {

            QLabel *lbl = labelsTablero[i][j];
            char c = tablero[i][j];

            if(c == 'P') {
                lbl->setPixmap(iconoPlanta.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            }
            else if(c == 'H') {
                lbl->setPixmap(iconoHerbivoro.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            }
            else if(c == 'C') {
                lbl->setPixmap(iconoCarnivoro.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            }
            else {
                lbl->clear();
            }
        }
    }
}
*/

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

void VentanaSimulacion::tickSimulacion()
{
    eco->avanzarCiclo();

    ui->lblCiclo->setText(QString::number(eco->getCiclo()));

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