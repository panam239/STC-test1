#include "findfiedialog.h"
#include "ui_findfiedialog.h"
#include <QDebug>

#include <QString>

FindFieDialog::FindFieDialog(const QString &_mask, QWidget *parent)
    : QDialog(parent), ui(new Ui::FindFieDialog), mask(_mask) {
  ui->setupUi(this);
  setAttribute(Qt::WA_DeleteOnClose);
  dir = QDir(QDir::current().absolutePath());
  model = new QFileSystemModel();
  model->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDot);

  QStringList filters;
  filters << mask;

  model->setNameFilters(filters);
  model->setNameFilterDisables(false);

  connect(ui->fileList, &QListView::doubleClicked, this,
          &FindFieDialog::itemDoubleClicked);
  fillTable();
}

FindFieDialog::~FindFieDialog() {
  delete model;
  delete ui;
}

void FindFieDialog::fillTable() {
  ui->pathLabel->setText(dir.absolutePath());
  QModelIndex index = model->setRootPath(dir.absolutePath());

  ui->fileList->setModel(model);
  ui->fileList->setRootIndex(index);
}

void FindFieDialog::itemDoubleClicked(const QModelIndex &index) {
  qDebug() << model->filePath(index);
  if (model->isDir(index)) {
    dir.cd(model->fileName(index));
  } else {
    emit uploadFile(model->filePath(index));
    close();
  }
  fillTable();
}
