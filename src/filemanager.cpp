#include "filemanager.h"

FileManager::FileManager(QObject* parent) : QObject(parent) {
  dbus_interface_ = new QDBusInterface("com.example.filehelper", "/",
                                       "com.example.filehelper",
                                       QDBusConnection::sessionBus(), this);
}

void FileManager::copyFile(const QString& src) {
  clipboard_ = src;
  is_cut_act_ = false;
}

void FileManager::cutFile(const QString& src) {
  clipboard_ = src;
  is_cut_act_ = true;
}

void FileManager::pasteFile(const QString& dst) {
  if (!clipboard_.isEmpty()) {
    QDBusMessage msg = dbus_interface_->call(
        "PasteFile", clipboard_,
        QString("%1/%2").arg(dst, QFileInfo(clipboard_).fileName()));
    if (is_cut_act_)
      deleteFile(clipboard_);
    clipboard_.clear();
  }

  is_cut_act_ = false;
}

void FileManager::deleteFile(const QString& filepath) {
  QDBusMessage msg = dbus_interface_->call("DeleteFile", filepath);
}
