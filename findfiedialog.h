#ifndef FINDFIEDIALOG_H
#define FINDFIEDIALOG_H

#include <QDialog>
#include <QDir>
#include <QFileSystemModel>

namespace Ui {
class FindFieDialog;
}

class FindFieDialog : public QDialog {
  Q_OBJECT

public:
  explicit FindFieDialog(const QString &_mask, QWidget *parent = nullptr);
  ~FindFieDialog();

private:
  void fillTable();
  QFileInfoList filterFiles(const QFileInfoList &list);
  Ui::FindFieDialog *ui;
  QDir dir;
  QString mask;
  QFileSystemModel *model;
private slots:
  void itemDoubleClicked(const QModelIndex &index);
signals:
  void uploadFile(const QString &filePath);
};

#endif // FINDFIEDIALOG_H
