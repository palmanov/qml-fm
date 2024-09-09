#ifndef ICONPROVIDER_H
#define ICONPROVIDER_H

#include <QQuickImageProvider>

#include "filesystemmodel.h"

class IconProvider : public QQuickImageProvider {
 public:
  explicit IconProvider(FileSystemModel* filesystem_model);
  QPixmap requestPixmap(const QString& id, QSize* size,
                        const QSize& requested_size);

  void setSize(const QSize& size) { icon_size_ = size; }

 private:
  FileSystemModel* filesystem_model_;
  QSize icon_size_;
};

#endif  // ICONPROVIDER_H
