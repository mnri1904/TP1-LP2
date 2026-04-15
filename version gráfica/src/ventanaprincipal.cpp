#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

//construcotr de la ventana principal
VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    /*
     * crea todos los widgets (botones, labels, etc.)
     * los posiciona según el diseñador
     * los conecta con ui->btnAlgo
     * aplica layouts
     * conecta señales automáticas (on_btnX_clicked)
     */
    ui->setupUi(this);
}

//emite una señal para abrir la ventana de simluacion cuando el botonJugar es cliqueado 
void VentanaPrincipal::on_btnJugar_clicked()
{
    emit abrirSimulacion();
}

//emite una señal para abrir el dialog de ajustes cuando el botonAjustes es cliqueado 
void VentanaPrincipal::on_btnAjustes_clicked()
{
    emit abrirAjustes();
}

//emite una señal para abrir el dialig de creditos cuando el botonCreditos es cliqueado 
void VentanaPrincipal::on_btnCreditos_clicked()
{
    emit abrirCreditos();
}

//emite una señal para cerrar la aplicacion cuando se presione el boton salir
void VentanaPrincipal::on_btnSalir_clicked()
{
    emit salirAplicacion();
}

//destructor de la ventana principal
VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}
