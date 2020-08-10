/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "drawwgt.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    DrawWgt *drawWgt;
    QHBoxLayout *horizontalLayout;
    QLabel *filePathLabel;
    QPushButton *uploadButton;
    QPushButton *findButton;
    QSpacerItem *horizontalSpacer;
    QLabel *infoLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *zoomLabel;
    QDoubleSpinBox *zoomDoubleSpinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        drawWgt = new DrawWgt(centralwidget);
        drawWgt->setObjectName(QString::fromUtf8("drawWgt"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(drawWgt->sizePolicy().hasHeightForWidth());
        drawWgt->setSizePolicy(sizePolicy);
        drawWgt->setMinimumSize(QSize(500, 500));

        verticalLayout->addWidget(drawWgt);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filePathLabel = new QLabel(centralwidget);
        filePathLabel->setObjectName(QString::fromUtf8("filePathLabel"));

        horizontalLayout->addWidget(filePathLabel);

        uploadButton = new QPushButton(centralwidget);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(uploadButton->sizePolicy().hasHeightForWidth());
        uploadButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(uploadButton);

        findButton = new QPushButton(centralwidget);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        horizontalLayout->addWidget(findButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(infoLabel->sizePolicy().hasHeightForWidth());
        infoLabel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(infoLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        zoomLabel = new QLabel(centralwidget);
        zoomLabel->setObjectName(QString::fromUtf8("zoomLabel"));

        horizontalLayout->addWidget(zoomLabel);

        zoomDoubleSpinBox = new QDoubleSpinBox(centralwidget);
        zoomDoubleSpinBox->setObjectName(QString::fromUtf8("zoomDoubleSpinBox"));
        zoomDoubleSpinBox->setMinimum(0.010000000000000);
        zoomDoubleSpinBox->setMaximum(10.000000000000000);
        zoomDoubleSpinBox->setSingleStep(0.010000000000000);
        zoomDoubleSpinBox->setValue(1.000000000000000);

        horizontalLayout->addWidget(zoomDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        filePathLabel->setText(QString());
        uploadButton->setText(QCoreApplication::translate("MainWindow", "upload", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "find file", nullptr));
        infoLabel->setText(QString());
        zoomLabel->setText(QCoreApplication::translate("MainWindow", "zoom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
