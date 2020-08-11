#include <QFile>
#include <QXmlStreamReader>

#include "fileparser.h"

FileParser::FileParser() {}

QVector<QPointF> FileParser::parseXml(const QString &path) {
  QVector<QPointF> points;
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
  }
  QXmlStreamReader xml(&file);

  while (!xml.atEnd() && !xml.hasError()) {
    QXmlStreamReader::TokenType token = xml.readNext();
    if (token == QXmlStreamReader::StartElement && xml.name() == "Point") {
      QPointF point;
      QXmlStreamAttributes attributes = xml.attributes();
      if (attributes.hasAttribute("X") && attributes.hasAttribute("Y")) {
        point.setX(attributes.value("X").toDouble());
        point.setY(attributes.value("Y").toDouble());
        points.append(point);
      }
    }
  }

  return points;
}

void FileParser::parseBin() {
  QVector<QPointF> points;
  QFile file(binFilePath);
  if (!file.open(QIODevice::ReadOnly)) {
  }
  unsigned int bufferSize = 4000;
  char *buffer = new char[bufferSize];
  QDataStream stream(&file);

  int count = 0;

  int readedBytes = stream.readRawData(buffer, bufferSize);
  while (readedBytes > 0 && count < 16) {
    points.clear();
    QDataStream stream2(buffer);
    stream2.setByteOrder(QDataStream::LittleEndian);
    while (readedBytes > 3) {
      QPointF point;
      int16_t value;
      stream2 >> value;
      point.setX(value);
      stream2 >> value;
      point.setY(value);
      points.append(point);
      readedBytes -= 4;
    }
    emit updateBinUpload(points);
    QThread::msleep(1000);

    readedBytes = stream.readRawData(buffer, bufferSize);
    count++;
  }
  delete[] buffer;
  emit finishBinUpload();
}

void FileParser::setBinFilePath(const QString &path) { binFilePath = path; }
