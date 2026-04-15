#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

void VentanaPrincipal::on_btnJugar_clicked()
{
    emit abrirSimulacion();
}

void VentanaPrincipal::on_btnAjustes_clicked()
{
    emit abrirAjustes();
}

void VentanaPrincipal::on_btnCreditos_clicked()
{
    emit abrirCreditos();
}

void VentanaPrincipal::on_btnSalir_clicked()
{
    emit salirAplicacion();
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}
