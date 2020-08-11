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
    QPushButton *findXmlButton;
    QLabel *filePathXmlLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *infoXmlLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *zoomLabel;
    QDoubleSpinBox *zoomDoubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *findBinButton;
    QLabel *filePathBinLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *infoBinLabel;
    QSpacerItem *horizontalSpacer_4;
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
        findXmlButton = new QPushButton(centralwidget);
        findXmlButton->setObjectName(QString::fromUtf8("findXmlButton"));

        horizontalLayout->addWidget(findXmlButton);

        filePathXmlLabel = new QLabel(centralwidget);
        filePathXmlLabel->setObjectName(QString::fromUtf8("filePathXmlLabel"));

        horizontalLayout->addWidget(filePathXmlLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        infoXmlLabel = new QLabel(centralwidget);
        infoXmlLabel->setObjectName(QString::fromUtf8("infoXmlLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(infoXmlLabel->sizePolicy().hasHeightForWidth());
        infoXmlLabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(infoXmlLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        zoomLabel = new QLabel(centralwidget);
        zoomLabel->setObjectName(QString::fromUtf8("zoomLabel"));

        horizontalLayout->addWidget(zoomLabel);

        zoomDoubleSpinBox = new QDoubleSpinBox(centralwidget);
        zoomDoubleSpinBox->setObjectName(QString::fromUtf8("zoomDoubleSpinBox"));
        zoomDoubleSpinBox->setMinimum(0.010000000000000);
        zoomDoubleSpinBox->setMaximum(100000.000000000000000);
        zoomDoubleSpinBox->setSingleStep(0.010000000000000);
        zoomDoubleSpinBox->setValue(1.000000000000000);

        horizontalLayout->addWidget(zoomDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        findBinButton = new QPushButton(centralwidget);
        findBinButton->setObjectName(QString::fromUtf8("findBinButton"));

        horizontalLayout_2->addWidget(findBinButton);

        filePathBinLabel = new QLabel(centralwidget);
        filePathBinLabel->setObjectName(QString::fromUtf8("filePathBinLabel"));

        horizontalLayout_2->addWidget(filePathBinLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        infoBinLabel = new QLabel(centralwidget);
        infoBinLabel->setObjectName(QString::fromUtf8("infoBinLabel"));

        horizontalLayout_2->addWidget(infoBinLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

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
        findXmlButton->setText(QCoreApplication::translate("MainWindow", "find xml file", nullptr));
        filePathXmlLabel->setText(QString());
        infoXmlLabel->setText(QString());
        zoomLabel->setText(QCoreApplication::translate("MainWindow", "zoom", nullptr));
        findBinButton->setText(QCoreApplication::translate("MainWindow", "find bin file", nullptr));
        filePathBinLabel->setText(QString());
        infoBinLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
