#include "VistaEcosistema.h"
#include "gameconfig.h"
#include <QPainter>

VistaEcosistema::VistaEcosistema(QWidget *parent)
    : QWidget(parent), eco(nullptr)
{
    actualizarIconos();
}

void VistaEcosistema::setEcosistema(Ecosistema *e)
{
    eco = e;
    update();
}

void VistaEcosistema::actualizarIconos()
{
    //planta = QPixmap(":/imagenes/planta.png");
    if (gSettings.plantaVariante == 0)
        planta = QPixmap(":/imagenes/honeyfruit.png");
    else
        planta = QPixmap(":/imagenes/bloodroses.png");

    // herbívoros
    if (gSettings.herbivoroVariante == 0)
        herbivoro = QPixmap(":/imagenes/teemo.png");
    else
        herbivoro = QPixmap(":/imagenes/fizz.png");

    // carnívoros
    if (gSettings.carnivoroVariante == 0)
        carnivoro = QPixmap(":/imagenes/warwick.png");
    else
        carnivoro = QPixmap(":/imagenes/naafiri.png");
}

void VistaEcosistema::paintEvent(QPaintEvent *)
{
    if (!eco) return;

    QPainter p(this);

    int filas = eco->getFilas();
    int columnas = eco->getColumnas();

    int w = width() / columnas;
    int h = height() / filas;

    const auto &tab = eco->getTablero();

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){

            p.setRenderHint(QPainter::SmoothPixmapTransform, true);
            QRect r(j*w, i*h, w, h);

            char c = tab[i][j];

            if(c=='P') p.drawPixmap(r, planta);
            else if(c=='H') p.drawPixmap(r, herbivoro);
            else if(c=='C') p.drawPixmap(r, carnivoro);
            //else p.fillRect(r, Qt::black);
        }
    }
}
