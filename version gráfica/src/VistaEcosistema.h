#ifndef VISTAECOSISTEMA_H
#define VISTAECOSISTEMA_H

#include <QWidget>
#include <QPixmap>
#include "Ecosistema.h"

class VistaEcosistema : public QWidget
{
    Q_OBJECT

public:
    explicit VistaEcosistema(QWidget *parent = nullptr);

    void setEcosistema(Ecosistema *e);
    void actualizarIconos();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ecosistema *eco;

    QPixmap planta;
    QPixmap herbivoro;
    QPixmap carnivoro;
};

#endif