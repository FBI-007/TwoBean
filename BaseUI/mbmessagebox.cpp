#include "MBMessageBox.h"
#include "messagebox.h"
#include <QMessageBox>
#include <QCheckBox>

QMessageBox::StandardButton MbMessageBox::showInformation(QWidget *parent, const QString &title,
                                            const QString &text, QMessageBox::StandardButtons buttons,
                                            QMessageBox::StandardButton defaultButton)
{
    MessageBox msgBox(parent, title, text, buttons, defaultButton);
    msgBox.setIcon(":/Images/information");
    if (msgBox.exec() == -1)
        return QMessageBox::Cancel;
    return msgBox.standardButton(msgBox.clickedButton());
}

QMessageBox::StandardButton MbMessageBox::showError(QWidget *parent, const QString &title,
                                      const QString &text, QMessageBox::StandardButtons buttons,
                                      QMessageBox::StandardButton defaultButton)
{
    MessageBox msgBox(parent, title, text, buttons, defaultButton);
    msgBox.setIcon(":/Images/error");
    if (msgBox.exec() == -1)
        return QMessageBox::Cancel;
    return msgBox.standardButton(msgBox.clickedButton());
}

QMessageBox::StandardButton MbMessageBox::showSuccess(QWidget *parent, const QString &title,
                                        const QString &text, QMessageBox::StandardButtons buttons,
                                        QMessageBox::StandardButton defaultButton)
{
    MessageBox msgBox(parent, title, text, buttons, defaultButton);
    msgBox.setIcon(":/Images/success");
    if (msgBox.exec() == -1)
        return QMessageBox::Cancel;
    return msgBox.standardButton(msgBox.clickedButton());
}

QMessageBox::StandardButton MbMessageBox::showQuestion(QWidget *parent, const QString &title,
                                         const QString &text, QMessageBox::StandardButtons buttons,
                                         QMessageBox::StandardButton defaultButton)
{
    MessageBox msgBox(parent, title, text, buttons, defaultButton);
    msgBox.setIcon(":/Images/question");
    if (msgBox.exec() == -1)
        return QMessageBox::Cancel;
    return msgBox.standardButton(msgBox.clickedButton());
}

QMessageBox::StandardButton MbMessageBox::showWarning(QWidget *parent, const QString &title,
                                        const QString &text, QMessageBox::StandardButtons buttons,
                                        QMessageBox::StandardButton defaultButton)
{
    MessageBox msgBox(parent, title, text, buttons, defaultButton);
    msgBox.setIcon(":/images/warning");
    if (msgBox.exec() == -1)
        return QMessageBox::Cancel;
    return msgBox.standardButton(msgBox.clickedButton());
}

QMessageBox::StandardButton MbMessageBox::showCritical(QWidget *parent, const QString &title,
                                         const QString &text, QMessageBox::StandardButtons buttons,
                                         QMessageBox::StandardButton defaultButton)
{
    MessageBox msgBox(parent, title, text, buttons, defaultButton);
    msgBox.setIcon(":/Images/warning");
    if (msgBox.exec() == -1)
        return QMessageBox::Cancel;
    return msgBox.standardButton(msgBox.clickedButton());
}

QMessageBox::StandardButton MbMessageBox::showCheckBoxQuestion(QWidget *parent, const QString &title,
                                         const QString &text, QMessageBox::StandardButtons buttons,
                                         QMessageBox::StandardButton defaultButton)
{
    MessageBox msgBox(parent, title, text, buttons, defaultButton);
    msgBox.setIcon(":/Images/question");

    QCheckBox *pCheckBox = new QCheckBox(&msgBox);
    pCheckBox->setText(text);
    msgBox.addWidget(pCheckBox);
    if (msgBox.exec() == -1)
        return QMessageBox::Cancel;

    QMessageBox::StandardButton standardButton = msgBox.standardButton(msgBox.clickedButton());
    if (standardButton == QMessageBox::Yes)
    {
        return pCheckBox->isChecked() ? QMessageBox::Yes : QMessageBox::No;
    }
    return QMessageBox::Cancel;
}
