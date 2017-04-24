#ifndef BASEUI_GLOBAL_H
#define BASEUI_GLOBAL_H


#include <QWidget>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "const.h"


#if defined(BASEUI_LIBRARY)
#  define BASEUISHARED_EXPORT Q_DECL_EXPORT
#else
#  define BASEUISHARED_EXPORT Q_DECL_IMPORT
#endif


#endif // BASEUI_GLOBAL_H
