#ifndef MBMESSAGEBOX_H
#define MBMESSAGEBOX_H

#include "baseui_global.h"
#include <QMessageBox>

class BASEUISHARED_EXPORT MbMessageBox
{
public:
    static QMessageBox::StandardButton showInformation(QWidget *parent, const QString &title, const QString &text,
                                                 QMessageBox::StandardButtons buttons = QMessageBox::StandardButton::Ok,
                                                 QMessageBox::StandardButton defaultButton = QMessageBox::StandardButton::NoButton);
    static QMessageBox::StandardButton showError(QWidget *parent, const QString &title, const QString &text,
                                                 QMessageBox::StandardButtons buttons = QMessageBox::StandardButton::Ok,
                                                 QMessageBox::StandardButton defaultButton = QMessageBox::StandardButton::NoButton);
    static QMessageBox::StandardButton showSuccess(QWidget *parent, const QString &title, const QString &text,
                                                 QMessageBox::StandardButtons buttons = QMessageBox::StandardButton::Ok,
                                                 QMessageBox::StandardButton defaultButton = QMessageBox::StandardButton::NoButton);
    static QMessageBox::StandardButton showQuestion(QWidget *parent, const QString &title, const QString &text,
                                                 QMessageBox::StandardButtons buttons = QMessageBox::StandardButton::Ok,
                                                 QMessageBox::StandardButton defaultButton = QMessageBox::StandardButton::NoButton);
    static QMessageBox::StandardButton showWarning(QWidget *parent, const QString &title, const QString &text,
                                                 QMessageBox::StandardButtons buttons = QMessageBox::StandardButton::Ok,
                                                 QMessageBox::StandardButton defaultButton = QMessageBox::StandardButton::NoButton);
    static QMessageBox::StandardButton showCritical(QWidget *parent, const QString &title, const QString &text,
                                                 QMessageBox::StandardButtons buttons = QMessageBox::StandardButton::Ok,
                                                 QMessageBox::StandardButton defaultButton = QMessageBox::StandardButton::NoButton);
    static QMessageBox::StandardButton showCheckBoxQuestion(QWidget *parent, const QString &title, const QString &text,
                                                 QMessageBox::StandardButtons buttons = QMessageBox::StandardButton::Ok,
                                                 QMessageBox::StandardButton defaultButton = QMessageBox::StandardButton::NoButton);
};

#endif // MBMESSAGEBOX_H
