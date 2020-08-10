/********************************************************************************
** Form generated from reading UI file 'drawwgt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWWGT_H
#define UI_DRAWWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawWgt
{
public:

    void setupUi(QWidget *DrawWgt)
    {
        if (DrawWgt->objectName().isEmpty())
            DrawWgt->setObjectName(QString::fromUtf8("DrawWgt"));
        DrawWgt->resize(400, 300);

        retranslateUi(DrawWgt);

        QMetaObject::connectSlotsByName(DrawWgt);
    } // setupUi

    void retranslateUi(QWidget *DrawWgt)
    {
        DrawWgt->setWindowTitle(QCoreApplication::translate("DrawWgt", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawWgt: public Ui_DrawWgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWWGT_H
