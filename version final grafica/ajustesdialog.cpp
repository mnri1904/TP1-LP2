#include "ajustesdialog.h"
#include "ui_ajustesdialog.h"
#include "gameconfig.h"
#include <QButtonGroup>

AjustesDialog::AjustesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjustesDialog)
{
    ui->setupUi(this);

    ui->sbFilas->setRange(3, 10);
    ui->sbColumnas->setRange(3, 10);

    ui->btnLight->setCheckable(true);
    ui->btnDark->setCheckable(true);

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

    ui->btnLight->setCheckable(true);
    ui->btnDark->setCheckable(true);

    group = new QButtonGroup(this);
    group->addButton(ui->btnLight);
    group->addButton(ui->btnDark);
    group->setExclusive(true);

    ui->btnLight->setChecked(true);

    connect(ui->btnLight, &QPushButton::clicked, this, [=]() {
        emit temaCambiado(":/imagenes/forestlight.jpg");
    });

    connect(ui->btnDark, &QPushButton::clicked, this, [=]() {
        emit temaCambiado(":/imagenes/forestdark.jpg");
    });
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