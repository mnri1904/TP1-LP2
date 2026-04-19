#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class VentanaPrincipal;
}
QT_END_NAMESPACE

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = nullptr);
    ~VentanaPrincipal() override;
    void setBackground(const QString &image);

signals:
    void abrirSimulacion();
    void abrirAjustes();
    void abrirCreditos();
    void salirAplicacion();

private slots:
    void on_btnJugar_clicked();
    void on_btnAjustes_clicked();
    void on_btnCreditos_clicked();
    void on_btnSalir_clicked();

    void on_btnFiddle_toggled(bool checked);

private:
    Ui::VentanaPrincipal *ui;
};

#endif // VENTANAPRINCIPAL_H