#include "ajustesdialog.h"
#include "gameconfig.h"
#include "ui_ajustesdialog.h"

/*
 * Constructor del dialog de ajustes.
 *
 * Inicializa la interfaz gráfica, configura rangos de valores
 * y carga las opciones disponibles (plantas, herbívoros, carnívoros).
 * También carga los valores actuales desde gSettings.
 */
AjustesDialog::AjustesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjustesDialog)
{
    ui->setupUi(this);

    //rango de la magtriz
    ui->sbFilas->setRange(3, 10);
    ui->sbColumnas->setRange(3, 10);

    //opciones de plantas
    ui->cbPlanta->clear();
    ui->cbPlanta->addItem("Honeyfruit");
    ui->cbPlanta->addItem("Bloodroses");

    //opciones de herbivoros
    ui->cbHerbivoro->clear();
    ui->cbHerbivoro->addItem("Teemo");
    ui->cbHerbivoro->addItem("Fizz");

    //opciones de carnivoros
    ui->cbCarnivoro->clear();
    ui->cbCarnivoro->addItem("Warwick");
    ui->cbCarnivoro->addItem("Naafiri");

    //carga los valores actuales desde la config
    ui->sbFilas->setValue(gSettings.filas);
    ui->sbColumnas->setValue(gSettings.columnas);
    ui->cbPlanta->setCurrentIndex(gSettings.plantaVariante);
    ui->cbHerbivoro->setCurrentIndex(gSettings.herbivoroVariante);
    ui->cbCarnivoro->setCurrentIndex(gSettings.carnivoroVariante);
}

/*
 * Se ejecuta cuando el usuario presiona "Aceptar".
 *
 * Guarda todos los valores seleccionados en la configuración global
 * (gSettings) y cierra el diálogo con estado "aceptado".
 */
void AjustesDialog::on_btnAceptar_clicked()
{
    gSettings.filas = ui->sbFilas->value();
    gSettings.columnas = ui->sbColumnas->value();
    gSettings.plantaVariante = ui->cbPlanta->currentIndex();
    gSettings.carnivoroVariante = ui->cbCarnivoro->currentIndex();
    gSettings.herbivoroVariante = ui->cbHerbivoro->currentIndex();

    accept();
}

/*
 * Se ejecuta cuando el usuario presiona "Cancelar".
 *
 * No guarda cambios y cierra el diálogo.
 */
void AjustesDialog::on_btnCancelar_clicked()
{
    reject();
}

//destructor
AjustesDialog::~AjustesDialog()
{
    delete ui;
}
