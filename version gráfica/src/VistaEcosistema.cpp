#include "VistaEcosistema.h"
#include "gameconfig.h"
#include <QPainter>

/*
 * Constructor de la vista del ecosistema.
 *
 * Inicializa el widget gráfico y deja el puntero al ecosistema en nullptr.
 * También carga los iconos iniciales según la configuración global.
 */
VistaEcosistema::VistaEcosistema(QWidget *parent)
    : QWidget(parent), eco(nullptr)
{
    actualizarIconos();
}

/*
 * Asigna el ecosistema que se va a dibujar.
 *
 * Recibe un puntero al modelo (Ecosistema) y lo guarda.
 * Luego llama a update() para forzar un repintado.
 */
void VistaEcosistema::setEcosistema(Ecosistema *e)
{
    eco = e;
    update(); // fuerza que Qt llame a paintEvent
}

/*
 * Carga los iconos según la configuración elegida por el usuario.
 *
 * Usa la variable global gSettings para decidir qué imagen usar
 * para plantas, herbívoros y carnívoros.
 *
 * Se decidió usar QPixmap porque soporta transparencia. 
 */
void VistaEcosistema::actualizarIconos()
{
    // plantas
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

/*
 * Función principal de renderizado.
 *
 * Qt llama automáticamente a esta función cada vez que el widget
 * necesita redibujarse (por ejemplo al hacer update()).
 *
 * Recorre toda la matriz del ecosistema y dibuja cada celda
 * usando imágenes escaladas dinámicamente.
 */
void VistaEcosistema::paintEvent(QPaintEvent *)
{
    // Si no hay ecosistema, no dibuja nada
    if (!eco) return;

    QPainter p(this);

    int filas = eco->getFilas();
    int columnas = eco->getColumnas();
    
    // Calcula el tamaño de cada celda dinámicamente
    int w = width() / columnas;
    int h = height() / filas;

    const auto &tab = eco->getTablero();

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            // Mejora visual al escalar imágenes
            p.setRenderHint(QPainter::SmoothPixmapTransform, true);
            // Rectángulo donde se dibuja la celda
            QRect r(j*w, i*h, w, h);

            char c = tab[i][j];

            // Dibuja según tipo de entidad
            if(c=='P') p.drawPixmap(r, planta);
            else if(c=='H') p.drawPixmap(r, herbivoro);
            else if(c=='C') p.drawPixmap(r, carnivoro);
        }
    }
}
