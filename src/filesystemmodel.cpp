#include "filesystemmodel.h"

#include <QDateTime>

static inline QString sizeString(const QFileInfo& fi) {
  if (!fi.isFile())
    return QString();
  const qint64 size = fi.size();
  if ((size >> 30) > 0)
    return QString::number(size >> 30) + ' ' + QObject::tr("ГБ");
  else if ((size >> 20) > 0)
    return QString::number(size >> 20) + ' ' + QObject::tr("МБ");
  else if ((size >> 10) > 0)
    return QString::number(size >> 10) + ' ' + QObject::tr("КБ");
  return QString::number(size);
}

FileSystemModel::FileSystemModel(QObject* parent)
    : QAbstractListModel(parent), current_dir_(QDir::homePath()) {
  file_info_list_ = current_dir_.entryInfoList(
      QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
}

QVariant FileSystemModel::data(const QModelIndex& index, int role) const {
  if (index.row() < 0 || index.row() >= file_info_list_.count())
    return {};

  const auto& file_info = file_info_list_[index.row()];

  switch (role) {
    case NameRole:
      return file_info.fileName();
    case TypeRole:
      return db_.mimeTypeForFile(file_info).comment();
    case SizeRole:
      return sizeString(file_info);
    case DateModifedRole:
      return file_info.lastModified().toString("dd.MM.yyyy hh:mm");
    case PathRole:
      return file_info.absoluteFilePath();
  }

  return {};
}

QHash<int, QByteArray> FileSystemModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles[NameRole] = "name";
  roles[TypeRole] = "type";
  roles[SizeRole] = "size";
  roles[DateModifedRole] = "modifed";
  roles[PathRole] = "path";
  return roles;
}

bool FileSystemModel::up() {
  if (!current_dir_.cdUp())
    return false;

  beginResetModel();
  // file_info_list_.clear();
  file_info_list_ = current_dir_.entryInfoList(
      QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
  endResetModel();

  return true;
}

bool FileSystemModel::cd(const QString& path) {
  QFileInfo new_dir(path);
  if (!new_dir.exists() || !new_dir.isDir())
    return false;

  current_dir_ = QDir(path);

  beginResetModel();
  file_info_list_ = current_dir_.entryInfoList(
      QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
  endResetModel();

  return true;
}

void FileSystemModel::refresh() {
  beginResetModel();
  file_info_list_ = current_dir_.entryInfoList(
      QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
  endResetModel();
}

QIcon FileSystemModel::icon(const QModelIndex& index) {
  if (index.row() < 0 || index.row() >= file_info_list_.count())
    return {};

  const auto& file_info = file_info_list_[index.row()];
  return icon_provider_.icon(file_info);
}
