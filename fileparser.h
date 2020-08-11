#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QtCore>

class FileParser : public QObject {
  Q_OBJECT
public:
  FileParser();

  QVector<QPointF> parseXml(const QString &path);
  void parseBin();
  void setBinFilePath(const QString &path);

private:
  QString binFilePath;

signals:
  void updateBinUpload(const QVector<QPointF> &points);
  void finishBinUpload();
};

#endif // XMLPARSER_H
