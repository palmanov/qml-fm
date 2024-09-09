#include <QCoreApplication>
#include "FileHelperService.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    FileHelperService service;

    return app.exec();
}