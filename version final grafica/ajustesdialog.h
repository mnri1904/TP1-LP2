#ifndef AJUSTESDIALOG_H
#define AJUSTESDIALOG_H

#include <QDialog>

class VentanaPrincipal;
class VentanaSimulacion;
class QButtonGroup;

namespace Ui {
class AjustesDialog;
}

class AjustesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjustesDialog(QWidget *parent);
    ~AjustesDialog() override;

private slots:
    void on_btnAceptar_clicked();
    void on_btnCancelar_clicked();

signals:
    void temaCambiado(QString imagen);

private:
    Ui::AjustesDialog *ui;

    QButtonGroup *group;
};

#endif // AJUSTESDIALOG_H