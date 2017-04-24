#include <QApplication>
#include <QFile>
#include "TBDownloadPage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TBDownloadPage dp;
    dp.show();

    return a.exec();
}
