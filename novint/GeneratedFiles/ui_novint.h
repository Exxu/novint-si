/********************************************************************************
** Form generated from reading UI file 'novint.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVINT_H
#define UI_NOVINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_novintClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QCommandLinkButton *commandLinkButton;
    QWidget *tab_2;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QCommandLinkButton *commandLinkButton_2;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QToolBox *toolBox;
    QWidget *page_3;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QMainWindow *novintClass)
    {
        if (novintClass->objectName().isEmpty())
            novintClass->setObjectName(QString::fromUtf8("novintClass"));
        novintClass->resize(800, 600);
        novintClass->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border: 1px inset gray\n"
"}"));
        centralWidget = new QWidget(novintClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(650, 0));
        tabWidget->setTabPosition(QTabWidget::West);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 130, 371, 331));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 30, 113, 20));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 30, 91, 16));
        commandLinkButton = new QCommandLinkButton(tab);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(500, 530, 121, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 101, 23));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 10, 501, 21));
        commandLinkButton_2 = new QCommandLinkButton(tab_2);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(270, 40, 111, 31));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 140, 400, 400));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 90, 141, 23));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 90, 141, 23));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 126, 501));
        formLayout = new QFormLayout(page_3);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(page_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(page_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        toolBox->addItem(page_3, QString::fromUtf8("Lectura del sistema"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 126, 501));
        toolBox->addItem(page, QString::fromUtf8("Configuraciones"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 126, 501));
        toolBox->addItem(page_2, QString::fromUtf8("Ajustes del sistema"));

        horizontalLayout->addWidget(toolBox);

        novintClass->setCentralWidget(centralWidget);

        retranslateUi(novintClass);

        tabWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(novintClass);
    } // setupUi

    void retranslateUi(QMainWindow *novintClass)
    {
        novintClass->setWindowTitle(QApplication::translate("novintClass", "novint", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("novintClass", "(gr\303\241fico de los movimientos del Falcon)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("novintClass", "Letras a evaluar:", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("novintClass", "Ver resultados", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("novintClass", "Evaluaci\303\263n", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("novintClass", "Seleccionar letra", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        commandLinkButton_2->setText(QApplication::translate("novintClass", "Cargar letra", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("novintClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("novintClass", "Inicializar Herramienta", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("novintClass", "Realizar movimiento", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("novintClass", "Entrenamiento", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("novintClass", "X:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("novintClass", "Y:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("novintClass", "Z:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("novintClass", "Lectura del sistema", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("novintClass", "Configuraciones", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("novintClass", "Ajustes del sistema", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class novintClass: public Ui_novintClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVINT_H
