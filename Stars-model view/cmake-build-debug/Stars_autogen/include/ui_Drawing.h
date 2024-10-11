/********************************************************************************
** Form generated from reading UI file 'drawing.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWING_H
#define UI_DRAWING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Drawing
{
public:

    void setupUi(QWidget *Drawing)
    {
        if (Drawing->objectName().isEmpty())
            Drawing->setObjectName("Drawing");
        Drawing->resize(400, 300);

        retranslateUi(Drawing);

        QMetaObject::connectSlotsByName(Drawing);
    } // setupUi

    void retranslateUi(QWidget *Drawing)
    {
        Drawing->setWindowTitle(QCoreApplication::translate("Drawing", "Drawing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Drawing: public Ui_Drawing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWING_H
