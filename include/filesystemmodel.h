#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H

#include <QAbstractItemModel>
#include <QDir>
#include <QFileIconProvider>
#include <QPixmap>
#include <QtQml>

class FileSystemModel : public QAbstractListModel {
  Q_OBJECT
  QML_ELEMENT

 public:
  enum InfoRoles { NameRole, TypeRole, SizeRole, DateModifedRole, PathRole };
  Q_ENUM(InfoRoles)

  Q_PROPERTY(QString currentPath READ currentPath)

  FileSystemModel(QObject* parent = nullptr);

  int rowCount(const QModelIndex& parent = QModelIndex()) const override {
    return file_info_list_.count();
  }

  QString currentPath() const { return current_dir_.path(); }

  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  Q_INVOKABLE bool up();
  Q_INVOKABLE bool cd(const QString& path);
  Q_INVOKABLE void refresh();

  Q_INVOKABLE QIcon icon(const QModelIndex& index);

 private:
  QDir current_dir_;
  QFileInfoList file_info_list_;
  QFileIconProvider icon_provider_;
  QMimeDatabase db_;
};

#endif  // FILESYSTEMMODEL_H
