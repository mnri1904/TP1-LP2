#include "ventanaprincipal.h"
#include "ventanasimulacion.h"
#include "ajustesdialog.h"
#include "creditosdialog.h"

#include <QApplication>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(static_cast<unsigned>(time(nullptr)));

    VentanaPrincipal menu;
    VentanaSimulacion simulacion;
    AjustesDialog ajustes;
    CreditosDialog creditos;

    QObject::connect(&menu, &VentanaPrincipal::abrirSimulacion, [&]() {
        simulacion.aplicarConfiguracionActual();
        simulacion.show();
        menu.hide();
    });

    QObject::connect(&menu, &VentanaPrincipal::abrirAjustes, [&]() {
        ajustes.exec();
    });

    QObject::connect(&menu, &VentanaPrincipal::abrirCreditos, [&]() {
        creditos.exec();
    });

    QObject::connect(&menu, &VentanaPrincipal::salirAplicacion, &a, &QApplication::quit);

    QObject::connect(&simulacion, &VentanaSimulacion::volverAlMenu, [&]() {
        simulacion.hide();
        menu.show();
    });

    menu.show();
    return a.exec();
}
