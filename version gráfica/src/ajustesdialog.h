#ifndef AJUSTESDIALOG_H
#define AJUSTESDIALOG_H

#include <QDialog>

namespace Ui {
class AjustesDialog;
}

class AjustesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjustesDialog(QWidget *parent = nullptr);
    ~AjustesDialog() override;

private slots:
    void on_btnAceptar_clicked();
    void on_btnCancelar_clicked();

private:
    Ui::AjustesDialog *ui;
};

#endif // AJUSTESDIALOG_H