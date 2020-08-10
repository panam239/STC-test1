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
  void setPoints(const QVector<QPointF> &points);
  void setZoom(const double &zoom);
  ~DrawWgt();

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::DrawWgt *ui;
  QVector<QPointF> points;
  double zoom = 1;
  void paintGrid(QPainter &painter);
};

#endif // DRAWWGT_H
