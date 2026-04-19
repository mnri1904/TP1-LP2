#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    ui->btnFiddle->setCheckable(true);

    connect(ui->btnFiddle, &QPushButton::toggled, this, [=](bool checked) {
        if (checked) {
            //QCursor cursor(QPixmap(":/imagenes/fiddlecursor.png"));
            QPixmap pix(":/imagenes/fiddlecursor.png");
            QCursor cursor(pix, 15, 15);
            QApplication::setOverrideCursor(cursor);
        } else {
            QApplication::restoreOverrideCursor();
        }
    });
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

void VentanaPrincipal::on_btnFiddle_toggled(bool checked)
{
    //emit cambiarIconoCursor();
}

void VentanaPrincipal::setBackground(const QString &image)
{
    this->setStyleSheet(QString(
        "QMainWindow {"
            "border-image: url(%1) 0 0 0 0 stretch stretch;"
        "}"
    ).arg(image));
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

