#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "filemanager.h"
#include "filesystemmodel.h"
#include "iconprovider.h"

int main(int argc, char* argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);

  QQmlApplicationEngine engine;
  qmlRegisterType<FileSystemModel>("com.example.filemanager", 1, 0,
                                   "FileSystemModel");
  qmlRegisterType<FileManager>("com.example.filemanager", 1, 0, "FileManager");

  FileSystemModel* filesystem_model = new FileSystemModel(&engine);
  engine.rootContext()->setContextProperty("fileSystemModel", filesystem_model);

  IconProvider* icon_provider = new IconProvider(filesystem_model);
  engine.addImageProvider(QLatin1String("provider"), icon_provider);

  IconProvider* list_icon_provider = new IconProvider(filesystem_model);
  list_icon_provider->setSize({24, 24});
  engine.addImageProvider(QLatin1String("list_provider"), list_icon_provider);

  const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
  engine.load(url);

  return app.exec();
}
