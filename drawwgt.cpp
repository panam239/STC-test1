#include <QPainter>

#include "drawwgt.h"
#include "ui_drawwgt.h"

DrawWgt::DrawWgt(QWidget *parent) : QWidget(parent), ui(new Ui::DrawWgt) {
  ui->setupUi(this);
}

void DrawWgt::setXmlPoints(const QVector<QPointF> &points) {
  this->xmlPoints = points;
  repaint();
}

void DrawWgt::setBinPoints(const QVector<QPointF> &points) {
  this->binPoints = points;
  repaint();
}

void DrawWgt::addBinPoints(const QVector<QPointF> &points) {
  this->binPoints.append(points);
  repaint();
}

void DrawWgt::clearBinPoints() {
  this->binPoints.clear();
  repaint();
}

int DrawWgt::getBinPointsCount() { return this->binPoints.count(); }

void DrawWgt::setZoom(const double &zoom) {
  this->zoom = zoom;
  repaint();
}

DrawWgt::~DrawWgt() { delete ui; }

void DrawWgt::paintGrid(QPainter &painter) {
  painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

  painter.drawLine(0, height() / 2, width(), height() / 2);
  painter.drawLine(width(), height() / 2, width() - 5, height() / 2 + 5);
  painter.drawLine(width(), height() / 2, width() - 5, height() / 2 - 5);
  painter.drawLine(width() / 2, 0, width() / 2, height());
  painter.drawLine(width() / 2, 0, width() / 2 + 5, 5);
  painter.drawLine(width() / 2, 0, width() / 2 - 5, 5);

  for (int i = 1; i <= 7; i++) {
    if (i == 4)
      continue;
    painter.drawLine(width() / 2, height() * i / 8, width() / 2 + 5,
                     height() * i / 8);
    painter.drawText(width() / 2 + 5, height() * i / 8,
                     QString::number((i - 4) * zoom));
    painter.drawLine(width() * i / 8, height() / 2, width() * i / 8,
                     height() / 2 - 5);
    painter.drawText(width() * i / 8, height() / 2 - 5,
                     QString::number((i - 4) * zoom));
  }
}

void DrawWgt::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);
  QPainter painter(this);
  paintGrid(painter);

  painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap));
  for (auto &point : binPoints) {
    if (qAbs(point.x() / zoom) <= 4 && qAbs(point.y() / zoom) <= 4) {
      double centerX = point.x() / zoom + 4;
      double centerY = 4 - point.y() / zoom;

      painter.drawPoint(width() * centerX / 8, height() * centerY / 8);
    }
  }

  painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::SquareCap));
  for (auto &point : xmlPoints) {
    if (qAbs(point.x() / zoom) <= 4 && qAbs(point.y() / zoom) <= 4) {
      double centerX = point.x() / zoom + 4;
      double centerY = 4 - point.y() / zoom;
      painter.drawLine(width() * centerX / 8, height() * centerY / 8 - 3,
                       width() * centerX / 8, height() * centerY / 8 + 3);

      painter.drawLine(width() * centerX / 8 - 3, height() * centerY / 8,
                       width() * centerX / 8 + 3, height() * centerY / 8);
    }
  }
}
