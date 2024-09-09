#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QDBusInterface>
#include <QFileInfo>
#include <QObject>

class FileManager : public QObject {
  Q_OBJECT
 public:
  explicit FileManager(QObject* parent = nullptr);

  Q_INVOKABLE bool isFile(const QString& path) const {
    return QFileInfo(path).isFile();
  }

  Q_INVOKABLE void copyFile(const QString& src);
  Q_INVOKABLE void cutFile(const QString& src);
  Q_INVOKABLE void pasteFile(const QString& dst);
  Q_INVOKABLE void deleteFile(const QString& filepath);

 private:
  QDBusInterface* dbus_interface_;
  QString clipboard_;
  bool is_cut_act_ = false;
};

#endif  // FILEMANAGER_H