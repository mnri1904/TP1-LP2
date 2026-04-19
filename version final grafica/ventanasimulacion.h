#ifndef VENTANASIMULACION_H
#define VENTANASIMULACION_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QGridLayout>
#include <QLayout>
#include <QPixmap>
#include <vector>
#include <memory>
#include "Ecosistema.h"
#include "VistaEcosistema.h"

namespace Ui {
class VentanaSimulacion;
}

class VentanaSimulacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaSimulacion(QWidget *parent = nullptr);
    ~VentanaSimulacion() override;

    void setBackground(const QString &image);
    void aplicarConfiguracionActual();

signals:
    void volverAlMenu();

private slots:
    void tickSimulacion();
    void on_btnIniciar_clicked();
    void on_btnPausar_clicked();
    void on_btnReiniciar_clicked();
    void on_btnMenu_clicked();

private:
    Ui::VentanaSimulacion *ui;

    QTimer *timer;
    VistaEcosistema *vista;

    int filas;
    int columnas;

    std::unique_ptr<Ecosistema> eco;

    /*
    QPixmap iconoPlanta;
    QPixmap iconoHerbivoro;
    QPixmap iconoCarnivoro;

    void vaciarLayout(QLayout *layout);
    void construirTableroVisual();
    void actualizarVista();
    */

    void actualizarContadores();
    void configurarDesdeEcosistema();
};

#endif // VENTANASIMULACION_H