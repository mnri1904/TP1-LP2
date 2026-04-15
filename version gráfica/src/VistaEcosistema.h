#ifndef VISTAECOSISTEMA_H
#define VISTAECOSISTEMA_H

#include <QWidget>
#include <QPixmap>
#include "Ecosistema.h"

/*
 * Clase VistaEcosistema
 *
 * Representa el componente visual encargado de dibujar el ecosistema.
 * Hereda de QWidget y utiliza QPainter para renderizar las entidades
 * (plantas, herbívoros y carnívoros) en forma de imágenes.
 *
 * Esta clase NO contiene lógica del juego, solo visualización.
 */
class VistaEcosistema : public QWidget
{
    Q_OBJECT

public:
    // constructor de la vista
    explicit VistaEcosistema(QWidget *parent = nullptr);
    /*
     * Asigna el ecosistema a renderizar.
     *
     * Recibe un puntero al modelo (Ecosistema) y lo guarda
     * para ser utilizado en el renderizado.
     */
    void setEcosistema(Ecosistema *e);
    /*
     * Actualiza los iconos según la configuración actual del usuario.
     *
     * Carga las imágenes correspondientes a plantas, herbívoros
     * y carnívoros desde los recursos del proyecto.
     */
    void actualizarIconos();

protected:
    /*
     * Evento de pintado.
     *
     * Es llamado automáticamente por Qt cuando el widget necesita
     * ser redibujado. Aquí se dibuja toda la matriz del ecosistema.
     */
    void paintEvent(QPaintEvent *) override;

private:
    /*
     * Puntero al ecosistema (modelo).
     *
     * Contiene toda la lógica y estado del juego.
     */
    Ecosistema *eco;

    /*
     * Imágenes utilizadas para representar cada tipo de entidad.
     */
    QPixmap planta;
    QPixmap herbivoro;
    QPixmap carnivoro;
};

#endif
