/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *decLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *raLine;
    QHBoxLayout *horizontalLayout;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLineEdit *starName;
    QPushButton *viewButton;

    void setupUi(QWidget *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName("gui");
        gui->resize(400, 434);
        verticalLayoutWidget = new QWidget(gui);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 10, 261, 322));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        decLine = new QLineEdit(verticalLayoutWidget);
        decLine->setObjectName("decLine");

        horizontalLayout_3->addWidget(decLine);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        raLine = new QLineEdit(verticalLayoutWidget);
        raLine->setObjectName("raLine");

        horizontalLayout_2->addWidget(raLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameLineEdit = new QLineEdit(verticalLayoutWidget);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout->addWidget(nameLineEdit);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        starName = new QLineEdit(verticalLayoutWidget);
        starName->setObjectName("starName");

        verticalLayout->addWidget(starName);

        viewButton = new QPushButton(gui);
        viewButton->setObjectName("viewButton");
        viewButton->setGeometry(QRect(330, 40, 75, 24));

        retranslateUi(gui);

        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QWidget *gui)
    {
        gui->setWindowTitle(QCoreApplication::translate("gui", "gui", nullptr));
        label_3->setText(QCoreApplication::translate("gui", "dec", nullptr));
        label_2->setText(QCoreApplication::translate("gui", "ra", nullptr));
        label->setText(QCoreApplication::translate("gui", "Name", nullptr));
        pushButton->setText(QCoreApplication::translate("gui", "Add Star", nullptr));
        checkBox->setText(QCoreApplication::translate("gui", "CheckBox", nullptr));
        viewButton->setText(QCoreApplication::translate("gui", "View\\", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
