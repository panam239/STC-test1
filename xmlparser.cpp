#include "xmlparser.h"

#include <QFile>
#include <QXmlStreamReader>

XmlParser::XmlParser() {}

QVector<QPointF> XmlParser::parseFile(const QString &path) {
  QVector<QPointF> points;
  QFile *file = new QFile(path);
  if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
  }
  QXmlStreamReader xml(file);

  while (!xml.atEnd() && !xml.hasError()) {
    QXmlStreamReader::TokenType token = xml.readNext();
    if (token == QXmlStreamReader::StartElement && xml.name() == "Point") {
      points.append(parsePoint(xml));
    }
  }

  return points;
}

QPointF XmlParser::parsePoint(QXmlStreamReader &reader) {
  QPointF point;
  QXmlStreamAttributes attributes = reader.attributes();
  if (!attributes.hasAttribute("X") || !attributes.hasAttribute("Y")) {
    return point;
  }
  point.setX(attributes.value("X").toDouble());
  point.setY(attributes.value("Y").toDouble());

  return point;
}
