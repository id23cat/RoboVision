/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelProccess;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButtonUp;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonLeft;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButtonDown;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolButtonRight;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *commandLine;
    QToolButton *toolButtonSend;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLineEdit *IPline;
    QLabel *label_5;
    QLineEdit *Portline;
    QPushButton *ReconnectBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(680, 382);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(680, 350));
        MainWindow->setMaximumSize(QSize(680, 407));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(320, 240));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelProccess = new QLabel(centralWidget);
        labelProccess->setObjectName(QString::fromUtf8("labelProccess"));
        labelProccess->setMinimumSize(QSize(320, 240));

        verticalLayout_2->addWidget(labelProccess);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        toolButtonUp = new QToolButton(centralWidget);
        toolButtonUp->setObjectName(QString::fromUtf8("toolButtonUp"));

        horizontalLayout_3->addWidget(toolButtonUp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButtonLeft = new QToolButton(centralWidget);
        toolButtonLeft->setObjectName(QString::fromUtf8("toolButtonLeft"));

        horizontalLayout_2->addWidget(toolButtonLeft);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        toolButtonDown = new QToolButton(centralWidget);
        toolButtonDown->setObjectName(QString::fromUtf8("toolButtonDown"));

        horizontalLayout_2->addWidget(toolButtonDown);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        toolButtonRight = new QToolButton(centralWidget);
        toolButtonRight->setObjectName(QString::fromUtf8("toolButtonRight"));

        horizontalLayout_2->addWidget(toolButtonRight);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        commandLine = new QLineEdit(centralWidget);
        commandLine->setObjectName(QString::fromUtf8("commandLine"));

        horizontalLayout_4->addWidget(commandLine);

        toolButtonSend = new QToolButton(centralWidget);
        toolButtonSend->setObjectName(QString::fromUtf8("toolButtonSend"));

        horizontalLayout_4->addWidget(toolButtonSend);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        IPline = new QLineEdit(centralWidget);
        IPline->setObjectName(QString::fromUtf8("IPline"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(IPline->sizePolicy().hasHeightForWidth());
        IPline->setSizePolicy(sizePolicy1);
        IPline->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(IPline);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        Portline = new QLineEdit(centralWidget);
        Portline->setObjectName(QString::fromUtf8("Portline"));
        sizePolicy1.setHeightForWidth(Portline->sizePolicy().hasHeightForWidth());
        Portline->setSizePolicy(sizePolicy1);
        Portline->setMinimumSize(QSize(0, 0));
        Portline->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_8->addWidget(Portline);

        ReconnectBtn = new QPushButton(centralWidget);
        ReconnectBtn->setObjectName(QString::fromUtf8("ReconnectBtn"));

        horizontalLayout_8->addWidget(ReconnectBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 22));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(commandLine, toolButtonSend);
        QWidget::setTabOrder(toolButtonSend, toolButtonUp);
        QWidget::setTabOrder(toolButtonUp, toolButtonDown);
        QWidget::setTabOrder(toolButtonDown, toolButtonLeft);
        QWidget::setTabOrder(toolButtonLeft, toolButtonRight);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Original", 0, QApplication::UnicodeUTF8));
        labelProccess->setText(QApplication::translate("MainWindow", "Processed", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Move control", 0, QApplication::UnicodeUTF8));
        toolButtonUp->setText(QApplication::translate("MainWindow", "\342\206\221", 0, QApplication::UnicodeUTF8));
        toolButtonUp->setShortcut(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
        toolButtonLeft->setText(QApplication::translate("MainWindow", "\342\206\220", 0, QApplication::UnicodeUTF8));
        toolButtonLeft->setShortcut(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        toolButtonDown->setText(QApplication::translate("MainWindow", "\342\206\223", 0, QApplication::UnicodeUTF8));
        toolButtonDown->setShortcut(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
        toolButtonRight->setText(QApplication::translate("MainWindow", "\342\206\222", 0, QApplication::UnicodeUTF8));
        toolButtonRight->setShortcut(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Send to UART", 0, QApplication::UnicodeUTF8));
        toolButtonSend->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        toolButtonSend->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "IP:", 0, QApplication::UnicodeUTF8));
        IPline->setInputMask(QApplication::translate("MainWindow", "000.000.000.000; ", 0, QApplication::UnicodeUTF8));
        IPline->setText(QApplication::translate("MainWindow", "192.168.1.2", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Port:", 0, QApplication::UnicodeUTF8));
        Portline->setInputMask(QApplication::translate("MainWindow", "00000; ", 0, QApplication::UnicodeUTF8));
        Portline->setText(QApplication::translate("MainWindow", "2000", 0, QApplication::UnicodeUTF8));
        ReconnectBtn->setText(QApplication::translate("MainWindow", "Reconnect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
