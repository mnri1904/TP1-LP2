#ifndef CREDITOSDIALOG_H
#define CREDITOSDIALOG_H

#include <QDialog>

namespace Ui {
class CreditosDialog;
}

class CreditosDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreditosDialog(QWidget *parent = nullptr);
    ~CreditosDialog() override;

private slots:
    void on_btnCerrar_clicked();

private:
    Ui::CreditosDialog *ui;
};

#endif // CREDITOSDIALOG_H