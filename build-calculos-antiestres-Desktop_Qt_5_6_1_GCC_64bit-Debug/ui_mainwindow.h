/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QRadioButton *radioCircular;
    QRadioButton *radioRectangular;
    QLabel *labelPulv;
    QLabel *labelDiam;
    QLabel *labelAncho;
    QLabel *labelLargo;
    QPushButton *pushButtonCalc;
    QLineEdit *lineEditPulv;
    QLineEdit *lineEditDiam;
    QLineEdit *lineEditAncho;
    QLineEdit *lineEditLargo;
    QTextEdit *textEditPulv;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        radioCircular = new QRadioButton(tab);
        radioCircular->setObjectName(QStringLiteral("radioCircular"));
        radioCircular->setGeometry(QRect(10, 20, 106, 21));
        radioRectangular = new QRadioButton(tab);
        radioRectangular->setObjectName(QStringLiteral("radioRectangular"));
        radioRectangular->setGeometry(QRect(10, 50, 106, 21));
        labelPulv = new QLabel(tab);
        labelPulv->setObjectName(QStringLiteral("labelPulv"));
        labelPulv->setGeometry(QRect(10, 100, 64, 15));
        labelDiam = new QLabel(tab);
        labelDiam->setObjectName(QStringLiteral("labelDiam"));
        labelDiam->setGeometry(QRect(10, 180, 64, 15));
        labelAncho = new QLabel(tab);
        labelAncho->setObjectName(QStringLiteral("labelAncho"));
        labelAncho->setGeometry(QRect(10, 250, 64, 15));
        labelLargo = new QLabel(tab);
        labelLargo->setObjectName(QStringLiteral("labelLargo"));
        labelLargo->setGeometry(QRect(10, 290, 64, 15));
        pushButtonCalc = new QPushButton(tab);
        pushButtonCalc->setObjectName(QStringLiteral("pushButtonCalc"));
        pushButtonCalc->setGeometry(QRect(140, 350, 83, 23));
        lineEditPulv = new QLineEdit(tab);
        lineEditPulv->setObjectName(QStringLiteral("lineEditPulv"));
        lineEditPulv->setGeometry(QRect(150, 100, 113, 23));
        lineEditPulv->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditDiam = new QLineEdit(tab);
        lineEditDiam->setObjectName(QStringLiteral("lineEditDiam"));
        lineEditDiam->setGeometry(QRect(150, 180, 113, 23));
        lineEditDiam->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditAncho = new QLineEdit(tab);
        lineEditAncho->setObjectName(QStringLiteral("lineEditAncho"));
        lineEditAncho->setGeometry(QRect(150, 250, 113, 23));
        lineEditAncho->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditLargo = new QLineEdit(tab);
        lineEditLargo->setObjectName(QStringLiteral("lineEditLargo"));
        lineEditLargo->setGeometry(QRect(150, 290, 113, 23));
        lineEditLargo->setInputMethodHints(Qt::ImhDigitsOnly);
        textEditPulv = new QTextEdit(tab);
        textEditPulv->setObjectName(QStringLiteral("textEditPulv"));
        textEditPulv->setGeometry(QRect(10, 110, 104, 71));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        graphicsView = new QGraphicsView(tab_2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout_2->addWidget(graphicsView);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        radioCircular->setText(QApplication::translate("MainWindow", "RadioButton", 0));
        radioRectangular->setText(QApplication::translate("MainWindow", "RadioButton", 0));
        labelPulv->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        labelDiam->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        labelAncho->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        labelLargo->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButtonCalc->setText(QApplication::translate("MainWindow", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
