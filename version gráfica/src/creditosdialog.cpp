#include "creditosdialog.h"
#include "ui_creditosdialog.h"
#include <QVBoxLayout>
#include <QLabel>

CreditosDialog::CreditosDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreditosDialog)
{
    setWindowTitle("Creditos");

    setStyleSheet(R"(
        QDialog { background-color: #1a192b; }
        QLabel { color: #27245a; font-size: 14px; }
        QLabel#titulo { color: #463d8e; font-size: 22px; font-weight: bold; }
        QLabel#nombre { color: #3a26a7; font-size: 15px; font-weight: bold; }
    )");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(12);
    layout->setContentsMargins(30, 30, 30, 30);

    QLabel *titulo = new QLabel("CREDITOS", this);
    titulo->setObjectName("titulo");
    titulo->setAlignment(Qt::AlignCenter);

    QFrame *linea = new QFrame(this);
    linea->setFrameShape(QFrame::HLine);
    linea->setStyleSheet("background-color: #3a26a7;");

    QLabel *rol     = new QLabel("Desarrollador:", this);
    rol->setAlignment(Qt::AlignCenter);

    QLabel *nombre  = new QLabel("Marcelo Romero", this);
    nombre->setObjectName("nombre");
    nombre->setAlignment(Qt::AlignCenter);

    QLabel *materia = new QLabel("Simulador de Ecosistema - LP2 - 2026", this);
    materia->setAlignment(Qt::AlignCenter);

    QPushButton *btnCerrar = new QPushButton("Cerrar", this);

    layout->addWidget(titulo);
    layout->addWidget(linea);
    layout->addSpacing(8);
    layout->addWidget(rol);
    layout->addWidget(nombre);
    layout->addWidget(materia);
    layout->addSpacing(12);
    layout->addWidget(btnCerrar, 0, Qt::AlignCenter);
    ui->setupUi(this);
}

void CreditosDialog::on_btnCerrar_clicked()
{
    close();
}

CreditosDialog::~CreditosDialog()
{
    delete ui;
}
