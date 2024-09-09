#include "FileHelperService.h"

constexpr int kServiceTimeout = 10000;

FileHelperService::FileHelperService(QObject* parent) : QObject(parent) {
  new FileHelper(this);

  QDBusConnection dbus = QDBusConnection::sessionBus();
  dbus.registerService("com.example.filehelper");
  dbus.registerObject("/", this);

  timer_.start(kServiceTimeout);

  QObject::connect(&timer_, &QTimer::timeout, qApp, &QCoreApplication::quit);
}

void FileHelperService::DeleteFile(const QString& filePath) {
  QFileInfo file_info(filePath);
  if (!file_info.exists())
    return;

  if (file_info.isDir())
    QDir(filePath).removeRecursively();
  else if (file_info.isFile())
    QFile::remove(filePath);
}

void FileHelperService::PasteFile(const QString& source,
                                  const QString& destination) {
  QFile::copy(source, destination);
}