#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class VentanaPrincipal;
}
QT_END_NAMESPACE

/*
 * Clase VentanaPrincipal
 *
 * Representa el menú principal del programa.
 * Se encarga de mostrar la interfaz inicial y emitir señales
 * cuando el usuario interactúa con los botones.
 *
 * NO contiene lógica del juego ni navegación directa.
 */
class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    //constructor que inicializa la ventana principal junto a su interfaz grafica
    explicit VentanaPrincipal(QWidget *parent = nullptr);
    //destructor
    ~VentanaPrincipal() override;

//señales emitidas por el usuario cuando quiere iniciar la simulacion, cuando quiere abrir ajustes, cuando quiere ver los creditos, y cuando quiere salir del programa
signals:
    void abrirSimulacion();
    void abrirAjustes();
    void abrirCreditos();
    void salirAplicacion();

//funciones que reaccionan a eventos. ne este caso todas reaccionan a clicks.
private slots:
    void on_btnJugar_clicked();
    void on_btnAjustes_clicked();
    void on_btnCreditos_clicked();
    void on_btnSalir_clicked();

private:
    /*
     * Puntero a la interfaz generada por Qt Designer.
     *
     * Permite acceder a los widgets definidos en el archivo .ui.
     */
    Ui::VentanaPrincipal *ui;
};

#endif // VENTANAPRINCIPAL_H
