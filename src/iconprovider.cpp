#include "iconprovider.h"

IconProvider::IconProvider(FileSystemModel* filesystem_model)
    : QQuickImageProvider(QQuickImageProvider::Pixmap),
      filesystem_model_(filesystem_model),
      icon_size_{64, 64} {}

QPixmap IconProvider::requestPixmap(const QString& id, QSize* size,
                                    const QSize& requested_size) {
  QModelIndex index;
  bool foundId = false;

  for (int row = 0; row < filesystem_model_->rowCount(); row++) {
    index = filesystem_model_->index(row, 0);
    QString path =
        filesystem_model_->data(index, FileSystemModel::InfoRoles::PathRole)
            .toString();

    if (path == id) {
      foundId = true;
      break;
    }
  }

  if (!foundId)
    return {};

  QIcon icon = filesystem_model_->icon(index);
  QPixmap pixmap = icon.pixmap(icon_size_);
  return pixmap;
}
