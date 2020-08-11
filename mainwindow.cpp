#include <QPainter>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->drawWgt->show();
  connect(ui->findXmlButton, &QPushButton::clicked, this, &MainWindow::findXml);
  connect(ui->findBinButton, &QPushButton::clicked, this, &MainWindow::findBin);
  connect(ui->zoomDoubleSpinBox,
          QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &MainWindow::zoomChange);

  findFileDialog = new FindFieDialog("");

  thread = new QThread;
  parser = new FileParser();
  parser->moveToThread(thread);

  qRegisterMetaType<QVector<QPointF>>("QVector<QPointF>");
  connect(parser, &FileParser::finishBinUpload, thread, &QThread::quit);
  connect(parser, &FileParser::updateBinUpload, this,
          &MainWindow::updateBinUpload);
  connect(parser, &FileParser::finishBinUpload, this,
          &MainWindow::finishBinUpload);
  connect(thread, &QThread::started, parser, &FileParser::parseBin);
}

MainWindow::~MainWindow() {
  thread->wait();
  delete thread;
  delete parser;
  delete ui;
}

void MainWindow::wheelEvent(QWheelEvent *we) {
  double zoom = ui->zoomDoubleSpinBox->value();
  zoom += we->angleDelta().y() / 120 * 0.01 * static_cast<int>(zoom + 1);
  zoom = qMax(zoom, ui->zoomDoubleSpinBox->minimum());
  zoom = qMin(zoom, ui->zoomDoubleSpinBox->maximum());
  zoomChange(zoom);
}

void MainWindow::uploadFile(const QString &path) {

  if (path.endsWith("xml")) {
    ui->filePathXmlLabel->setText(path);
    auto points = parser->parseXml(path);
    ui->infoXmlLabel->setText("upload " + QString::number(points.count()) +
                              " xml points");
    ui->drawWgt->setXmlPoints(points);
    delete parser;
  } else if (path.endsWith("bin")) {
    ui->drawWgt->clearBinPoints();
    parser->setBinFilePath(path);
    ui->findBinButton->setEnabled(false);
    ui->infoBinLabel->setText("upload 0 xml points");
    ui->filePathBinLabel->setText(path);

    thread->start();
  }
}

void MainWindow::findXml() { findFile("*.xml"); }

void MainWindow::findBin() { findFile("*.bin"); }

void MainWindow::findFile(const QString &mask) {

  connect(findFileDialog, &FindFieDialog::uploadFile, this,
          &MainWindow::uploadFile);
  findFileDialog->setModal(true);
  findFileDialog->show();
}

void MainWindow::zoomChange(const double &zoom) {
  ui->drawWgt->setZoom(zoom);
  ui->zoomDoubleSpinBox->setValue(zoom);
}

void MainWindow::updateBinUpload(const QVector<QPointF> &points) {
  ui->drawWgt->addBinPoints(points);
  ui->infoBinLabel->setText("upload " +
                            QString::number(ui->drawWgt->getBinPointsCount()) +
                            " xml points");
}

void MainWindow::finishBinUpload() {
  ui->infoBinLabel->setText("Finished");
  ui->findBinButton->setEnabled(true);
}
