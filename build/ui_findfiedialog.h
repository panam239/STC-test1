/********************************************************************************
** Form generated from reading UI file 'findfiedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFIEDIALOG_H
#define UI_FINDFIEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FindFieDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *pathLabel;
    QListView *fileList;
    QPushButton *selectButton;

    void setupUi(QDialog *FindFieDialog)
    {
        if (FindFieDialog->objectName().isEmpty())
            FindFieDialog->setObjectName(QString::fromUtf8("FindFieDialog"));
        FindFieDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(FindFieDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pathLabel = new QLabel(FindFieDialog);
        pathLabel->setObjectName(QString::fromUtf8("pathLabel"));

        verticalLayout->addWidget(pathLabel);

        fileList = new QListView(FindFieDialog);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fileList->sizePolicy().hasHeightForWidth());
        fileList->setSizePolicy(sizePolicy);
        fileList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(fileList);

        selectButton = new QPushButton(FindFieDialog);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        verticalLayout->addWidget(selectButton);


        retranslateUi(FindFieDialog);

        QMetaObject::connectSlotsByName(FindFieDialog);
    } // setupUi

    void retranslateUi(QDialog *FindFieDialog)
    {
        FindFieDialog->setWindowTitle(QCoreApplication::translate("FindFieDialog", "Dialog", nullptr));
        pathLabel->setText(QCoreApplication::translate("FindFieDialog", "path", nullptr));
        selectButton->setText(QCoreApplication::translate("FindFieDialog", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindFieDialog: public Ui_FindFieDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFIEDIALOG_H
