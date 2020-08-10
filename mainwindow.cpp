#include "mainwindow.h"
#include "findfiedialog.h"
#include "ui_mainwindow.h"
#include "xmlparser.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->drawWgt->show();
  //  connect(ui->uploadButton, &QPushButton::clicked, this,
  //          &MainWindow::uploadFile);
  connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::findFile);
  connect(ui->zoomDoubleSpinBox,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &MainWindow::zoomChange);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::wheelEvent(QWheelEvent *we) {
  double zoom = ui->zoomDoubleSpinBox->value();
  zoom += we->angleDelta().y() / 120 * 0.01;
  zoom = qMax(zoom, ui->zoomDoubleSpinBox->minimum());
  zoom = qMin(zoom, ui->zoomDoubleSpinBox->maximum());
  zoomChange(zoom);
}

void MainWindow::uploadFile(const QString &path) {
  ui->filePathLabel->setText(path);
  ui->drawWgt->setPoints(XmlParser::parseFile(path));
}

void MainWindow::findFile() {
  FindFieDialog *findFileDialog = new FindFieDialog("*.xml");
  connect(findFileDialog, &FindFieDialog::uploadFile, this,
          &MainWindow::uploadFile);
  findFileDialog->setModal(true);
  findFileDialog->show();
}

void MainWindow::zoomChange(const double &zoom) {
  ui->drawWgt->setZoom(zoom);
  ui->zoomDoubleSpinBox->setValue(zoom);
}
