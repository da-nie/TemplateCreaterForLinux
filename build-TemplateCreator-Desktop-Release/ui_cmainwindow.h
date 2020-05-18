/********************************************************************************
** Form generated from reading UI file 'cmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *CPushButton_Create;
    QComboBox *CComboBox_Type;
    QLineEdit *CLineEdit_Name;
    QLineEdit *CLineEdit_Description;
    QLabel *label;
    QLabel *label_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWindow)
    {
        if (CMainWindow->objectName().isEmpty())
            CMainWindow->setObjectName(QStringLiteral("CMainWindow"));
        CMainWindow->resize(568, 226);
        centralWidget = new QWidget(CMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CPushButton_Create = new QPushButton(centralWidget);
        CPushButton_Create->setObjectName(QStringLiteral("CPushButton_Create"));
        CPushButton_Create->setGeometry(QRect(10, 150, 541, 41));
        CComboBox_Type = new QComboBox(centralWidget);
        CComboBox_Type->setObjectName(QStringLiteral("CComboBox_Type"));
        CComboBox_Type->setGeometry(QRect(10, 10, 541, 25));
        CLineEdit_Name = new QLineEdit(centralWidget);
        CLineEdit_Name->setObjectName(QStringLiteral("CLineEdit_Name"));
        CLineEdit_Name->setGeometry(QRect(10, 60, 541, 29));
        CLineEdit_Description = new QLineEdit(centralWidget);
        CLineEdit_Description->setObjectName(QStringLiteral("CLineEdit_Description"));
        CLineEdit_Description->setGeometry(QRect(10, 110, 541, 29));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 531, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 531, 17));
        CMainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(CMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainWindow->setStatusBar(statusBar);

        retranslateUi(CMainWindow);

        QMetaObject::connectSlotsByName(CMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindow)
    {
        CMainWindow->setWindowTitle(QApplication::translate("CMainWindow", "Template Creater", Q_NULLPTR));
        CPushButton_Create->setText(QApplication::translate("CMainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("CMainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("CMainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CMainWindow: public Ui_CMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
