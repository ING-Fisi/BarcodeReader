#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(const QString &strMAC, const QString &strQR, QWidget *parent = nullptr);
    ~EditDialog();

signals:
    void saveClicked(const QString &strMAC, const QString &strQR, const QString &editedStr);

private slots:
    void onSaveClicked();

private:
    Ui::EditDialog *ui;
    QString m_strMAC;
    QString m_strQR;
};

#endif // EDITDIALOG_H
