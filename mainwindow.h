#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QWheelEvent>

#include "fileparser.h"
#include "findfiedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

protected:
  void wheelEvent(QWheelEvent *we) override;

private:
  void findFile(const QString &mask);

  Ui::MainWindow *ui;
  QThread *thread;
  FileParser *parser;
  FindFieDialog *findFileDialog;

private slots:
  void uploadFile(const QString &path);
  void findXml();
  void findBin();
  void zoomChange(const double &zoom);
  void updateBinUpload(const QVector<QPointF> &points);
  void finishBinUpload();
};
#endif // MAINWINDOW_H
