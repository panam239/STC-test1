#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QVector>
#include <QtCore>
class XmlParser : public QObject {
  Q_OBJECT
public:
  XmlParser();
  static QVector<QPointF> parseFile(const QString &path);

private:
  static QPointF parsePoint(QXmlStreamReader &reader);
};

#endif // XMLPARSER_H
