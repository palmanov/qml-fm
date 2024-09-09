#include <QtDBus/QDBusConnection>
#include "filehelper_adaptor.h"

class FileHelperService : public QObject {
  Q_OBJECT
 public:
  explicit FileHelperService(QObject* parent = nullptr);

 public slots:
  void DeleteFile(const QString& filePath);
  void PasteFile(const QString& source, const QString& destination);

 private:
  QTimer timer_;
};
