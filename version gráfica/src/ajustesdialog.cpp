#include "ajustesdialog.h"
#include "gameconfig.h"
#include "ui_ajustesdialog.h"

AjustesDialog::AjustesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjustesDialog)
{
    ui->setupUi(this);

    ui->sbFilas->setRange(3, 10);
    ui->sbColumnas->setRange(3, 10);

    ui->cbPlanta->clear();
    ui->cbPlanta->addItem("Honeyfruit");
    ui->cbPlanta->addItem("Bloodroses");

    ui->cbHerbivoro->clear();
    ui->cbHerbivoro->addItem("Teemo");
    ui->cbHerbivoro->addItem("Fizz");

    ui->cbCarnivoro->clear();
    ui->cbCarnivoro->addItem("Warwick");
    ui->cbCarnivoro->addItem("Naafiri");


    ui->sbFilas->setValue(gSettings.filas);
    ui->sbColumnas->setValue(gSettings.columnas);
    ui->cbCarnivoro->setCurrentIndex(gSettings.carnivoroVariante);
}

void AjustesDialog::on_btnAceptar_clicked()
{
    gSettings.filas = ui->sbFilas->value();
    gSettings.columnas = ui->sbColumnas->value();
    gSettings.plantaVariante = ui->cbPlanta->currentIndex();
    gSettings.carnivoroVariante = ui->cbCarnivoro->currentIndex();
    gSettings.herbivoroVariante = ui->cbHerbivoro->currentIndex();

    accept();
}

void AjustesDialog::on_btnCancelar_clicked()
{
    reject();
}

AjustesDialog::~AjustesDialog()
{
    delete ui;
}