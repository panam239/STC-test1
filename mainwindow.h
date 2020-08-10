#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWheelEvent>

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
  Ui::MainWindow *ui;
private slots:
  void uploadFile(const QString &path);
  void findFile();
  void zoomChange(const double &zoom);
};
#endif // MAINWINDOW_H
