#ifndef DRAWWGT_H
#define DRAWWGT_H

#include <QWidget>

namespace Ui {
class DrawWgt;
}

class DrawWgt : public QWidget {
  Q_OBJECT

public:
  explicit DrawWgt(QWidget *parent = nullptr);
  ~DrawWgt();

  void setXmlPoints(const QVector<QPointF> &points);

  void setBinPoints(const QVector<QPointF> &points);
  void addBinPoints(const QVector<QPointF> &points);
  void clearBinPoints();
  int getBinPointsCount();

  void setZoom(const double &zoom);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  void paintGrid(QPainter &painter);

  Ui::DrawWgt *ui;
  QVector<QPointF> xmlPoints;
  QVector<QPointF> binPoints;
  double zoom = 1;
};

#endif // DRAWWGT_H
