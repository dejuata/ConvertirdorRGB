/********************************************************************************
** Form generated from reading UI file 'settingsfilter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSFILTER_H
#define UI_SETTINGSFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsFilter
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *show;
    QWidget *layoutWidget_2;
    QGridLayout *filterLayout;
    QLineEdit *f_1_2;
    QLineEdit *f_0_3;
    QLineEdit *f_0_4;
    QLineEdit *f_0_7;
    QLineEdit *f_1_6;
    QLineEdit *f_1_7;
    QLineEdit *f_1_8;
    QLineEdit *f_2_0;
    QLineEdit *f_2_2;
    QLineEdit *f_0_8;
    QLineEdit *f_2_3;
    QLineEdit *f_0_0;
    QLineEdit *f_1_4;
    QLineEdit *f_1_1;
    QLineEdit *f_0_6;
    QLineEdit *f_1_3;
    QLineEdit *f_1_5;
    QLineEdit *f_2_1;
    QLineEdit *f_0_1;
    QLineEdit *f_1_0;
    QLineEdit *f_0_2;
    QLineEdit *f_0_5;
    QLineEdit *f_4_5;
    QLineEdit *f_3_7;
    QLineEdit *f_5_3;
    QLineEdit *f_5_5;
    QLineEdit *f_4_4;
    QLineEdit *f_3_0;
    QLineEdit *f_3_8;
    QLineEdit *f_2_8;
    QLineEdit *f_4_0;
    QLineEdit *f_5_2;
    QLineEdit *f_3_3;
    QLineEdit *f_2_6;
    QLineEdit *f_3_5;
    QLineEdit *f_2_4;
    QLineEdit *f_3_6;
    QLineEdit *f_4_3;
    QLineEdit *f_4_7;
    QLineEdit *f_4_8;
    QLineEdit *f_5_6;
    QLineEdit *f_3_4;
    QLineEdit *f_2_5;
    QLineEdit *f_4_1;
    QLineEdit *f_5_1;
    QLineEdit *f_5_8;
    QLineEdit *f_2_7;
    QLineEdit *f_3_2;
    QLineEdit *f_4_6;
    QLineEdit *f_3_1;
    QLineEdit *f_5_4;
    QLineEdit *f_5_7;
    QLineEdit *f_5_0;
    QLineEdit *f_4_2;
    QLineEdit *f_6_7;
    QLineEdit *f_7_1;
    QLineEdit *f_6_6;
    QLineEdit *f_8_6;
    QLineEdit *f_8_7;
    QLineEdit *f_7_0;
    QLineEdit *f_8_5;
    QLineEdit *f_7_3;
    QLineEdit *f_7_5;
    QLineEdit *f_7_2;
    QLineEdit *f_7_8;
    QLineEdit *f_6_0;
    QLineEdit *f_6_5;
    QLineEdit *f_7_7;
    QLineEdit *f_7_4;
    QLineEdit *f_8_0;
    QLineEdit *f_6_2;
    QLineEdit *f_6_3;
    QLineEdit *f_8_2;
    QLineEdit *f_8_3;
    QLineEdit *f_6_1;
    QLineEdit *f_6_4;
    QLineEdit *f_6_8;
    QLineEdit *f_8_1;
    QLineEdit *f_8_8;
    QLineEdit *f_8_4;
    QLineEdit *f_7_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *filterByDefault;
    QComboBox *selectFilter;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnLoad;
    QLabel *loaded;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *SettingsFilter)
    {
        if (SettingsFilter->objectName().isEmpty())
            SettingsFilter->setObjectName(QStringLiteral("SettingsFilter"));
        SettingsFilter->resize(421, 467);
        buttonBox = new QDialogButtonBox(SettingsFilter);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-230, 430, 641, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        show = new QFrame(SettingsFilter);
        show->setObjectName(QStringLiteral("show"));
        show->setGeometry(QRect(10, 100, 401, 325));
        show->setFrameShape(QFrame::StyledPanel);
        show->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(show);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(8, 4, 381, 321));
        filterLayout = new QGridLayout(layoutWidget_2);
        filterLayout->setObjectName(QStringLiteral("filterLayout"));
        filterLayout->setContentsMargins(0, 0, 0, 0);
        f_1_2 = new QLineEdit(layoutWidget_2);
        f_1_2->setObjectName(QStringLiteral("f_1_2"));
        f_1_2->setMinimumSize(QSize(20, 20));
        f_1_2->setMaximumSize(QSize(50, 50));
        f_1_2->setBaseSize(QSize(20, 20));
        f_1_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_2, 1, 2, 1, 1);

        f_0_3 = new QLineEdit(layoutWidget_2);
        f_0_3->setObjectName(QStringLiteral("f_0_3"));
        f_0_3->setMinimumSize(QSize(20, 20));
        f_0_3->setMaximumSize(QSize(50, 50));
        f_0_3->setBaseSize(QSize(20, 20));
        f_0_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_3, 0, 3, 1, 1);

        f_0_4 = new QLineEdit(layoutWidget_2);
        f_0_4->setObjectName(QStringLiteral("f_0_4"));
        f_0_4->setMinimumSize(QSize(20, 20));
        f_0_4->setMaximumSize(QSize(50, 50));
        f_0_4->setBaseSize(QSize(20, 20));
        f_0_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_4, 0, 4, 1, 1);

        f_0_7 = new QLineEdit(layoutWidget_2);
        f_0_7->setObjectName(QStringLiteral("f_0_7"));
        f_0_7->setMinimumSize(QSize(20, 20));
        f_0_7->setMaximumSize(QSize(50, 50));
        f_0_7->setBaseSize(QSize(20, 20));
        f_0_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_7, 0, 7, 1, 1);

        f_1_6 = new QLineEdit(layoutWidget_2);
        f_1_6->setObjectName(QStringLiteral("f_1_6"));
        f_1_6->setMinimumSize(QSize(20, 20));
        f_1_6->setMaximumSize(QSize(50, 50));
        f_1_6->setBaseSize(QSize(20, 20));
        f_1_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_6, 1, 6, 1, 1);

        f_1_7 = new QLineEdit(layoutWidget_2);
        f_1_7->setObjectName(QStringLiteral("f_1_7"));
        f_1_7->setMinimumSize(QSize(20, 20));
        f_1_7->setMaximumSize(QSize(50, 50));
        f_1_7->setBaseSize(QSize(20, 20));
        f_1_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_7, 1, 7, 1, 1);

        f_1_8 = new QLineEdit(layoutWidget_2);
        f_1_8->setObjectName(QStringLiteral("f_1_8"));
        f_1_8->setMinimumSize(QSize(20, 20));
        f_1_8->setMaximumSize(QSize(50, 50));
        f_1_8->setBaseSize(QSize(20, 20));
        f_1_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_8, 1, 8, 1, 1);

        f_2_0 = new QLineEdit(layoutWidget_2);
        f_2_0->setObjectName(QStringLiteral("f_2_0"));
        f_2_0->setMinimumSize(QSize(20, 20));
        f_2_0->setMaximumSize(QSize(50, 50));
        f_2_0->setBaseSize(QSize(20, 20));
        f_2_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_0, 2, 0, 1, 1);

        f_2_2 = new QLineEdit(layoutWidget_2);
        f_2_2->setObjectName(QStringLiteral("f_2_2"));
        f_2_2->setMinimumSize(QSize(20, 20));
        f_2_2->setMaximumSize(QSize(50, 50));
        f_2_2->setBaseSize(QSize(20, 20));
        f_2_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_2, 2, 2, 1, 1);

        f_0_8 = new QLineEdit(layoutWidget_2);
        f_0_8->setObjectName(QStringLiteral("f_0_8"));
        f_0_8->setMinimumSize(QSize(20, 20));
        f_0_8->setMaximumSize(QSize(50, 50));
        f_0_8->setBaseSize(QSize(20, 20));
        f_0_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_8, 0, 8, 1, 1);

        f_2_3 = new QLineEdit(layoutWidget_2);
        f_2_3->setObjectName(QStringLiteral("f_2_3"));
        f_2_3->setMinimumSize(QSize(20, 20));
        f_2_3->setMaximumSize(QSize(50, 50));
        f_2_3->setBaseSize(QSize(20, 20));
        f_2_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_3, 2, 3, 1, 1);

        f_0_0 = new QLineEdit(layoutWidget_2);
        f_0_0->setObjectName(QStringLiteral("f_0_0"));
        f_0_0->setEnabled(true);
        f_0_0->setMinimumSize(QSize(20, 20));
        f_0_0->setMaximumSize(QSize(50, 50));
        f_0_0->setBaseSize(QSize(20, 20));
        f_0_0->setInputMethodHints(Qt::ImhPreferNumbers);
        f_0_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_0, 0, 0, 1, 1);

        f_1_4 = new QLineEdit(layoutWidget_2);
        f_1_4->setObjectName(QStringLiteral("f_1_4"));
        f_1_4->setMinimumSize(QSize(20, 20));
        f_1_4->setMaximumSize(QSize(50, 50));
        f_1_4->setBaseSize(QSize(20, 20));
        f_1_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_4, 1, 4, 1, 1);

        f_1_1 = new QLineEdit(layoutWidget_2);
        f_1_1->setObjectName(QStringLiteral("f_1_1"));
        f_1_1->setMinimumSize(QSize(20, 20));
        f_1_1->setMaximumSize(QSize(50, 50));
        f_1_1->setBaseSize(QSize(20, 20));
        f_1_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_1, 1, 1, 1, 1);

        f_0_6 = new QLineEdit(layoutWidget_2);
        f_0_6->setObjectName(QStringLiteral("f_0_6"));
        f_0_6->setMinimumSize(QSize(20, 20));
        f_0_6->setMaximumSize(QSize(50, 50));
        f_0_6->setBaseSize(QSize(20, 20));
        f_0_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_6, 0, 6, 1, 1);

        f_1_3 = new QLineEdit(layoutWidget_2);
        f_1_3->setObjectName(QStringLiteral("f_1_3"));
        f_1_3->setMinimumSize(QSize(20, 20));
        f_1_3->setMaximumSize(QSize(50, 50));
        f_1_3->setBaseSize(QSize(20, 20));
        f_1_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_3, 1, 3, 1, 1);

        f_1_5 = new QLineEdit(layoutWidget_2);
        f_1_5->setObjectName(QStringLiteral("f_1_5"));
        f_1_5->setMinimumSize(QSize(20, 20));
        f_1_5->setMaximumSize(QSize(50, 50));
        f_1_5->setBaseSize(QSize(20, 20));
        f_1_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_5, 1, 5, 1, 1);

        f_2_1 = new QLineEdit(layoutWidget_2);
        f_2_1->setObjectName(QStringLiteral("f_2_1"));
        f_2_1->setMinimumSize(QSize(20, 20));
        f_2_1->setMaximumSize(QSize(50, 50));
        f_2_1->setBaseSize(QSize(20, 20));
        f_2_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_1, 2, 1, 1, 1);

        f_0_1 = new QLineEdit(layoutWidget_2);
        f_0_1->setObjectName(QStringLiteral("f_0_1"));
        f_0_1->setMinimumSize(QSize(20, 20));
        f_0_1->setMaximumSize(QSize(50, 50));
        f_0_1->setBaseSize(QSize(20, 20));
        f_0_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_1, 0, 1, 1, 1);

        f_1_0 = new QLineEdit(layoutWidget_2);
        f_1_0->setObjectName(QStringLiteral("f_1_0"));
        f_1_0->setMinimumSize(QSize(20, 20));
        f_1_0->setMaximumSize(QSize(50, 50));
        f_1_0->setBaseSize(QSize(20, 20));
        f_1_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_1_0, 1, 0, 1, 1);

        f_0_2 = new QLineEdit(layoutWidget_2);
        f_0_2->setObjectName(QStringLiteral("f_0_2"));
        f_0_2->setMinimumSize(QSize(20, 20));
        f_0_2->setMaximumSize(QSize(50, 50));
        f_0_2->setBaseSize(QSize(20, 20));
        f_0_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_2, 0, 2, 1, 1);

        f_0_5 = new QLineEdit(layoutWidget_2);
        f_0_5->setObjectName(QStringLiteral("f_0_5"));
        f_0_5->setMinimumSize(QSize(20, 20));
        f_0_5->setMaximumSize(QSize(50, 50));
        f_0_5->setBaseSize(QSize(20, 20));
        f_0_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_0_5, 0, 5, 1, 1);

        f_4_5 = new QLineEdit(layoutWidget_2);
        f_4_5->setObjectName(QStringLiteral("f_4_5"));
        f_4_5->setMinimumSize(QSize(20, 20));
        f_4_5->setMaximumSize(QSize(50, 50));
        f_4_5->setBaseSize(QSize(20, 20));
        f_4_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_5, 4, 5, 1, 1);

        f_3_7 = new QLineEdit(layoutWidget_2);
        f_3_7->setObjectName(QStringLiteral("f_3_7"));
        f_3_7->setMinimumSize(QSize(20, 20));
        f_3_7->setMaximumSize(QSize(50, 50));
        f_3_7->setBaseSize(QSize(20, 20));
        f_3_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_7, 3, 7, 1, 1);

        f_5_3 = new QLineEdit(layoutWidget_2);
        f_5_3->setObjectName(QStringLiteral("f_5_3"));
        f_5_3->setMinimumSize(QSize(20, 20));
        f_5_3->setMaximumSize(QSize(50, 50));
        f_5_3->setBaseSize(QSize(20, 20));
        f_5_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_3, 5, 3, 1, 1);

        f_5_5 = new QLineEdit(layoutWidget_2);
        f_5_5->setObjectName(QStringLiteral("f_5_5"));
        f_5_5->setMinimumSize(QSize(20, 20));
        f_5_5->setMaximumSize(QSize(50, 50));
        f_5_5->setBaseSize(QSize(20, 20));
        f_5_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_5, 5, 5, 1, 1);

        f_4_4 = new QLineEdit(layoutWidget_2);
        f_4_4->setObjectName(QStringLiteral("f_4_4"));
        f_4_4->setMinimumSize(QSize(20, 20));
        f_4_4->setMaximumSize(QSize(50, 50));
        f_4_4->setBaseSize(QSize(20, 20));
        f_4_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_4, 4, 4, 1, 1);

        f_3_0 = new QLineEdit(layoutWidget_2);
        f_3_0->setObjectName(QStringLiteral("f_3_0"));
        f_3_0->setMinimumSize(QSize(20, 20));
        f_3_0->setMaximumSize(QSize(50, 50));
        f_3_0->setBaseSize(QSize(20, 20));
        f_3_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_0, 3, 0, 1, 1);

        f_3_8 = new QLineEdit(layoutWidget_2);
        f_3_8->setObjectName(QStringLiteral("f_3_8"));
        f_3_8->setMinimumSize(QSize(20, 20));
        f_3_8->setMaximumSize(QSize(50, 50));
        f_3_8->setBaseSize(QSize(20, 20));
        f_3_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_8, 3, 8, 1, 1);

        f_2_8 = new QLineEdit(layoutWidget_2);
        f_2_8->setObjectName(QStringLiteral("f_2_8"));
        f_2_8->setMinimumSize(QSize(20, 20));
        f_2_8->setMaximumSize(QSize(50, 50));
        f_2_8->setBaseSize(QSize(20, 20));
        f_2_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_8, 2, 8, 1, 1);

        f_4_0 = new QLineEdit(layoutWidget_2);
        f_4_0->setObjectName(QStringLiteral("f_4_0"));
        f_4_0->setMinimumSize(QSize(20, 20));
        f_4_0->setMaximumSize(QSize(50, 50));
        f_4_0->setBaseSize(QSize(20, 20));
        f_4_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_0, 4, 0, 1, 1);

        f_5_2 = new QLineEdit(layoutWidget_2);
        f_5_2->setObjectName(QStringLiteral("f_5_2"));
        f_5_2->setMinimumSize(QSize(20, 20));
        f_5_2->setMaximumSize(QSize(50, 50));
        f_5_2->setBaseSize(QSize(20, 20));
        f_5_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_2, 5, 2, 1, 1);

        f_3_3 = new QLineEdit(layoutWidget_2);
        f_3_3->setObjectName(QStringLiteral("f_3_3"));
        f_3_3->setMinimumSize(QSize(20, 20));
        f_3_3->setMaximumSize(QSize(50, 50));
        f_3_3->setBaseSize(QSize(20, 20));
        f_3_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_3, 3, 3, 1, 1);

        f_2_6 = new QLineEdit(layoutWidget_2);
        f_2_6->setObjectName(QStringLiteral("f_2_6"));
        f_2_6->setMinimumSize(QSize(20, 20));
        f_2_6->setMaximumSize(QSize(50, 50));
        f_2_6->setBaseSize(QSize(20, 20));
        f_2_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_6, 2, 6, 1, 1);

        f_3_5 = new QLineEdit(layoutWidget_2);
        f_3_5->setObjectName(QStringLiteral("f_3_5"));
        f_3_5->setMinimumSize(QSize(20, 20));
        f_3_5->setMaximumSize(QSize(50, 50));
        f_3_5->setBaseSize(QSize(20, 20));
        f_3_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_5, 3, 5, 1, 1);

        f_2_4 = new QLineEdit(layoutWidget_2);
        f_2_4->setObjectName(QStringLiteral("f_2_4"));
        f_2_4->setMinimumSize(QSize(20, 20));
        f_2_4->setMaximumSize(QSize(50, 50));
        f_2_4->setBaseSize(QSize(20, 20));
        f_2_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_4, 2, 4, 1, 1);

        f_3_6 = new QLineEdit(layoutWidget_2);
        f_3_6->setObjectName(QStringLiteral("f_3_6"));
        f_3_6->setMinimumSize(QSize(20, 20));
        f_3_6->setMaximumSize(QSize(50, 50));
        f_3_6->setBaseSize(QSize(20, 20));
        f_3_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_6, 3, 6, 1, 1);

        f_4_3 = new QLineEdit(layoutWidget_2);
        f_4_3->setObjectName(QStringLiteral("f_4_3"));
        f_4_3->setMinimumSize(QSize(20, 20));
        f_4_3->setMaximumSize(QSize(50, 50));
        f_4_3->setBaseSize(QSize(20, 20));
        f_4_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_3, 4, 3, 1, 1);

        f_4_7 = new QLineEdit(layoutWidget_2);
        f_4_7->setObjectName(QStringLiteral("f_4_7"));
        f_4_7->setMinimumSize(QSize(20, 20));
        f_4_7->setMaximumSize(QSize(50, 50));
        f_4_7->setBaseSize(QSize(20, 20));
        f_4_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_7, 4, 7, 1, 1);

        f_4_8 = new QLineEdit(layoutWidget_2);
        f_4_8->setObjectName(QStringLiteral("f_4_8"));
        f_4_8->setMinimumSize(QSize(20, 20));
        f_4_8->setMaximumSize(QSize(50, 50));
        f_4_8->setBaseSize(QSize(20, 20));
        f_4_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_8, 4, 8, 1, 1);

        f_5_6 = new QLineEdit(layoutWidget_2);
        f_5_6->setObjectName(QStringLiteral("f_5_6"));
        f_5_6->setMinimumSize(QSize(20, 20));
        f_5_6->setMaximumSize(QSize(50, 50));
        f_5_6->setBaseSize(QSize(20, 20));
        f_5_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_6, 5, 6, 1, 1);

        f_3_4 = new QLineEdit(layoutWidget_2);
        f_3_4->setObjectName(QStringLiteral("f_3_4"));
        f_3_4->setMinimumSize(QSize(20, 20));
        f_3_4->setMaximumSize(QSize(50, 50));
        f_3_4->setBaseSize(QSize(20, 20));
        f_3_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_4, 3, 4, 1, 1);

        f_2_5 = new QLineEdit(layoutWidget_2);
        f_2_5->setObjectName(QStringLiteral("f_2_5"));
        f_2_5->setMinimumSize(QSize(20, 20));
        f_2_5->setMaximumSize(QSize(50, 50));
        f_2_5->setBaseSize(QSize(20, 20));
        f_2_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_5, 2, 5, 1, 1);

        f_4_1 = new QLineEdit(layoutWidget_2);
        f_4_1->setObjectName(QStringLiteral("f_4_1"));
        f_4_1->setMinimumSize(QSize(20, 20));
        f_4_1->setMaximumSize(QSize(50, 50));
        f_4_1->setBaseSize(QSize(20, 20));
        f_4_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_1, 4, 1, 1, 1);

        f_5_1 = new QLineEdit(layoutWidget_2);
        f_5_1->setObjectName(QStringLiteral("f_5_1"));
        f_5_1->setMinimumSize(QSize(20, 20));
        f_5_1->setMaximumSize(QSize(50, 50));
        f_5_1->setBaseSize(QSize(20, 20));
        f_5_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_1, 5, 1, 1, 1);

        f_5_8 = new QLineEdit(layoutWidget_2);
        f_5_8->setObjectName(QStringLiteral("f_5_8"));
        f_5_8->setMinimumSize(QSize(20, 20));
        f_5_8->setMaximumSize(QSize(50, 50));
        f_5_8->setBaseSize(QSize(20, 20));
        f_5_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_8, 5, 8, 1, 1);

        f_2_7 = new QLineEdit(layoutWidget_2);
        f_2_7->setObjectName(QStringLiteral("f_2_7"));
        f_2_7->setMinimumSize(QSize(20, 20));
        f_2_7->setMaximumSize(QSize(50, 50));
        f_2_7->setBaseSize(QSize(20, 20));
        f_2_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_2_7, 2, 7, 1, 1);

        f_3_2 = new QLineEdit(layoutWidget_2);
        f_3_2->setObjectName(QStringLiteral("f_3_2"));
        f_3_2->setMinimumSize(QSize(20, 20));
        f_3_2->setMaximumSize(QSize(50, 50));
        f_3_2->setBaseSize(QSize(20, 20));
        f_3_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_2, 3, 2, 1, 1);

        f_4_6 = new QLineEdit(layoutWidget_2);
        f_4_6->setObjectName(QStringLiteral("f_4_6"));
        f_4_6->setMinimumSize(QSize(20, 20));
        f_4_6->setMaximumSize(QSize(50, 50));
        f_4_6->setBaseSize(QSize(20, 20));
        f_4_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_6, 4, 6, 1, 1);

        f_3_1 = new QLineEdit(layoutWidget_2);
        f_3_1->setObjectName(QStringLiteral("f_3_1"));
        f_3_1->setMinimumSize(QSize(20, 20));
        f_3_1->setMaximumSize(QSize(50, 50));
        f_3_1->setBaseSize(QSize(20, 20));
        f_3_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_3_1, 3, 1, 1, 1);

        f_5_4 = new QLineEdit(layoutWidget_2);
        f_5_4->setObjectName(QStringLiteral("f_5_4"));
        f_5_4->setMinimumSize(QSize(20, 20));
        f_5_4->setMaximumSize(QSize(50, 50));
        f_5_4->setBaseSize(QSize(20, 20));
        f_5_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_4, 5, 4, 1, 1);

        f_5_7 = new QLineEdit(layoutWidget_2);
        f_5_7->setObjectName(QStringLiteral("f_5_7"));
        f_5_7->setMinimumSize(QSize(20, 20));
        f_5_7->setMaximumSize(QSize(50, 50));
        f_5_7->setBaseSize(QSize(20, 20));
        f_5_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_7, 5, 7, 1, 1);

        f_5_0 = new QLineEdit(layoutWidget_2);
        f_5_0->setObjectName(QStringLiteral("f_5_0"));
        f_5_0->setMinimumSize(QSize(20, 20));
        f_5_0->setMaximumSize(QSize(50, 50));
        f_5_0->setBaseSize(QSize(20, 20));
        f_5_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_5_0, 5, 0, 1, 1);

        f_4_2 = new QLineEdit(layoutWidget_2);
        f_4_2->setObjectName(QStringLiteral("f_4_2"));
        f_4_2->setMinimumSize(QSize(20, 20));
        f_4_2->setMaximumSize(QSize(50, 50));
        f_4_2->setBaseSize(QSize(20, 20));
        f_4_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_4_2, 4, 2, 1, 1);

        f_6_7 = new QLineEdit(layoutWidget_2);
        f_6_7->setObjectName(QStringLiteral("f_6_7"));
        f_6_7->setMinimumSize(QSize(20, 20));
        f_6_7->setMaximumSize(QSize(50, 50));
        f_6_7->setBaseSize(QSize(20, 20));
        f_6_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_7, 6, 7, 1, 1);

        f_7_1 = new QLineEdit(layoutWidget_2);
        f_7_1->setObjectName(QStringLiteral("f_7_1"));
        f_7_1->setMinimumSize(QSize(20, 20));
        f_7_1->setMaximumSize(QSize(50, 50));
        f_7_1->setBaseSize(QSize(20, 20));
        f_7_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_1, 7, 1, 1, 1);

        f_6_6 = new QLineEdit(layoutWidget_2);
        f_6_6->setObjectName(QStringLiteral("f_6_6"));
        f_6_6->setMinimumSize(QSize(20, 20));
        f_6_6->setMaximumSize(QSize(50, 50));
        f_6_6->setBaseSize(QSize(20, 20));
        f_6_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_6, 6, 6, 1, 1);

        f_8_6 = new QLineEdit(layoutWidget_2);
        f_8_6->setObjectName(QStringLiteral("f_8_6"));
        f_8_6->setMinimumSize(QSize(20, 20));
        f_8_6->setMaximumSize(QSize(50, 50));
        f_8_6->setBaseSize(QSize(20, 20));
        f_8_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_6, 8, 6, 1, 1);

        f_8_7 = new QLineEdit(layoutWidget_2);
        f_8_7->setObjectName(QStringLiteral("f_8_7"));
        f_8_7->setMinimumSize(QSize(20, 20));
        f_8_7->setMaximumSize(QSize(50, 50));
        f_8_7->setBaseSize(QSize(20, 20));
        f_8_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_7, 8, 7, 1, 1);

        f_7_0 = new QLineEdit(layoutWidget_2);
        f_7_0->setObjectName(QStringLiteral("f_7_0"));
        f_7_0->setMinimumSize(QSize(20, 20));
        f_7_0->setMaximumSize(QSize(50, 50));
        f_7_0->setBaseSize(QSize(20, 20));
        f_7_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_0, 7, 0, 1, 1);

        f_8_5 = new QLineEdit(layoutWidget_2);
        f_8_5->setObjectName(QStringLiteral("f_8_5"));
        f_8_5->setMinimumSize(QSize(20, 20));
        f_8_5->setMaximumSize(QSize(50, 50));
        f_8_5->setBaseSize(QSize(20, 20));
        f_8_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_5, 8, 5, 1, 1);

        f_7_3 = new QLineEdit(layoutWidget_2);
        f_7_3->setObjectName(QStringLiteral("f_7_3"));
        f_7_3->setMinimumSize(QSize(20, 20));
        f_7_3->setMaximumSize(QSize(50, 50));
        f_7_3->setBaseSize(QSize(20, 20));
        f_7_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_3, 7, 3, 1, 1);

        f_7_5 = new QLineEdit(layoutWidget_2);
        f_7_5->setObjectName(QStringLiteral("f_7_5"));
        f_7_5->setMinimumSize(QSize(20, 20));
        f_7_5->setMaximumSize(QSize(50, 50));
        f_7_5->setBaseSize(QSize(20, 20));
        f_7_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_5, 7, 5, 1, 1);

        f_7_2 = new QLineEdit(layoutWidget_2);
        f_7_2->setObjectName(QStringLiteral("f_7_2"));
        f_7_2->setMinimumSize(QSize(20, 20));
        f_7_2->setMaximumSize(QSize(50, 50));
        f_7_2->setBaseSize(QSize(20, 20));
        f_7_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_2, 7, 2, 1, 1);

        f_7_8 = new QLineEdit(layoutWidget_2);
        f_7_8->setObjectName(QStringLiteral("f_7_8"));
        f_7_8->setMinimumSize(QSize(20, 20));
        f_7_8->setMaximumSize(QSize(50, 50));
        f_7_8->setBaseSize(QSize(20, 20));
        f_7_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_8, 7, 8, 1, 1);

        f_6_0 = new QLineEdit(layoutWidget_2);
        f_6_0->setObjectName(QStringLiteral("f_6_0"));
        f_6_0->setMinimumSize(QSize(20, 20));
        f_6_0->setMaximumSize(QSize(50, 50));
        f_6_0->setBaseSize(QSize(20, 20));
        f_6_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_0, 6, 0, 1, 1);

        f_6_5 = new QLineEdit(layoutWidget_2);
        f_6_5->setObjectName(QStringLiteral("f_6_5"));
        f_6_5->setMinimumSize(QSize(20, 20));
        f_6_5->setMaximumSize(QSize(50, 50));
        f_6_5->setBaseSize(QSize(20, 20));
        f_6_5->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_5, 6, 5, 1, 1);

        f_7_7 = new QLineEdit(layoutWidget_2);
        f_7_7->setObjectName(QStringLiteral("f_7_7"));
        f_7_7->setMinimumSize(QSize(20, 20));
        f_7_7->setMaximumSize(QSize(50, 50));
        f_7_7->setBaseSize(QSize(20, 20));
        f_7_7->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_7, 7, 7, 1, 1);

        f_7_4 = new QLineEdit(layoutWidget_2);
        f_7_4->setObjectName(QStringLiteral("f_7_4"));
        f_7_4->setMinimumSize(QSize(20, 20));
        f_7_4->setMaximumSize(QSize(50, 50));
        f_7_4->setBaseSize(QSize(20, 20));
        f_7_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_4, 7, 4, 1, 1);

        f_8_0 = new QLineEdit(layoutWidget_2);
        f_8_0->setObjectName(QStringLiteral("f_8_0"));
        f_8_0->setMinimumSize(QSize(20, 20));
        f_8_0->setMaximumSize(QSize(50, 50));
        f_8_0->setBaseSize(QSize(20, 20));
        f_8_0->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_0, 8, 0, 1, 1);

        f_6_2 = new QLineEdit(layoutWidget_2);
        f_6_2->setObjectName(QStringLiteral("f_6_2"));
        f_6_2->setMinimumSize(QSize(20, 20));
        f_6_2->setMaximumSize(QSize(50, 50));
        f_6_2->setBaseSize(QSize(20, 20));
        f_6_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_2, 6, 2, 1, 1);

        f_6_3 = new QLineEdit(layoutWidget_2);
        f_6_3->setObjectName(QStringLiteral("f_6_3"));
        f_6_3->setMinimumSize(QSize(20, 20));
        f_6_3->setMaximumSize(QSize(50, 50));
        f_6_3->setBaseSize(QSize(20, 20));
        f_6_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_3, 6, 3, 1, 1);

        f_8_2 = new QLineEdit(layoutWidget_2);
        f_8_2->setObjectName(QStringLiteral("f_8_2"));
        f_8_2->setMinimumSize(QSize(20, 20));
        f_8_2->setMaximumSize(QSize(50, 50));
        f_8_2->setBaseSize(QSize(20, 20));
        f_8_2->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_2, 8, 2, 1, 1);

        f_8_3 = new QLineEdit(layoutWidget_2);
        f_8_3->setObjectName(QStringLiteral("f_8_3"));
        f_8_3->setMinimumSize(QSize(20, 20));
        f_8_3->setMaximumSize(QSize(50, 50));
        f_8_3->setBaseSize(QSize(20, 20));
        f_8_3->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_3, 8, 3, 1, 1);

        f_6_1 = new QLineEdit(layoutWidget_2);
        f_6_1->setObjectName(QStringLiteral("f_6_1"));
        f_6_1->setMinimumSize(QSize(20, 20));
        f_6_1->setMaximumSize(QSize(50, 50));
        f_6_1->setBaseSize(QSize(20, 20));
        f_6_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_1, 6, 1, 1, 1);

        f_6_4 = new QLineEdit(layoutWidget_2);
        f_6_4->setObjectName(QStringLiteral("f_6_4"));
        f_6_4->setMinimumSize(QSize(20, 20));
        f_6_4->setMaximumSize(QSize(50, 50));
        f_6_4->setBaseSize(QSize(20, 20));
        f_6_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_4, 6, 4, 1, 1);

        f_6_8 = new QLineEdit(layoutWidget_2);
        f_6_8->setObjectName(QStringLiteral("f_6_8"));
        f_6_8->setMinimumSize(QSize(20, 20));
        f_6_8->setMaximumSize(QSize(50, 50));
        f_6_8->setBaseSize(QSize(20, 20));
        f_6_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_6_8, 6, 8, 1, 1);

        f_8_1 = new QLineEdit(layoutWidget_2);
        f_8_1->setObjectName(QStringLiteral("f_8_1"));
        f_8_1->setMinimumSize(QSize(20, 20));
        f_8_1->setMaximumSize(QSize(50, 50));
        f_8_1->setBaseSize(QSize(20, 20));
        f_8_1->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_1, 8, 1, 1, 1);

        f_8_8 = new QLineEdit(layoutWidget_2);
        f_8_8->setObjectName(QStringLiteral("f_8_8"));
        f_8_8->setMinimumSize(QSize(20, 20));
        f_8_8->setMaximumSize(QSize(50, 50));
        f_8_8->setBaseSize(QSize(20, 20));
        f_8_8->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_8, 8, 8, 1, 1);

        f_8_4 = new QLineEdit(layoutWidget_2);
        f_8_4->setObjectName(QStringLiteral("f_8_4"));
        f_8_4->setMinimumSize(QSize(20, 20));
        f_8_4->setMaximumSize(QSize(50, 50));
        f_8_4->setBaseSize(QSize(20, 20));
        f_8_4->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_8_4, 8, 4, 1, 1);

        f_7_6 = new QLineEdit(layoutWidget_2);
        f_7_6->setObjectName(QStringLiteral("f_7_6"));
        f_7_6->setMinimumSize(QSize(20, 20));
        f_7_6->setMaximumSize(QSize(50, 50));
        f_7_6->setBaseSize(QSize(20, 20));
        f_7_6->setAlignment(Qt::AlignCenter);

        filterLayout->addWidget(f_7_6, 7, 6, 1, 1);

        layoutWidget = new QWidget(SettingsFilter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 401, 83));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        filterByDefault = new QComboBox(layoutWidget);
        filterByDefault->setObjectName(QStringLiteral("filterByDefault"));

        horizontalLayout_2->addWidget(filterByDefault);

        selectFilter = new QComboBox(layoutWidget);
        selectFilter->setObjectName(QStringLiteral("selectFilter"));
        selectFilter->setEnabled(false);

        horizontalLayout_2->addWidget(selectFilter);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        btnLoad = new QPushButton(layoutWidget);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));

        horizontalLayout->addWidget(btnLoad);

        loaded = new QLabel(layoutWidget);
        loaded->setObjectName(QStringLiteral("loaded"));

        horizontalLayout->addWidget(loaded);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox->raise();
        layoutWidget->raise();
        show->raise();

        retranslateUi(SettingsFilter);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsFilter, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsFilter, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsFilter);
    } // setupUi

    void retranslateUi(QDialog *SettingsFilter)
    {
        SettingsFilter->setWindowTitle(QApplication::translate("SettingsFilter", "Dialog", 0));
        label_2->setText(QApplication::translate("SettingsFilter", "Select default filter", 0));
        filterByDefault->clear();
        filterByDefault->insertItems(0, QStringList()
         << QApplication::translate("SettingsFilter", "Select", 0)
         << QApplication::translate("SettingsFilter", "Average", 0)
         << QApplication::translate("SettingsFilter", "Gaussiano", 0)
        );
        selectFilter->clear();
        selectFilter->insertItems(0, QStringList()
         << QApplication::translate("SettingsFilter", "Select", 0)
         << QApplication::translate("SettingsFilter", "3 x 3", 0)
         << QApplication::translate("SettingsFilter", "5 x 5", 0)
         << QApplication::translate("SettingsFilter", "7 x 7", 0)
         << QApplication::translate("SettingsFilter", "9 x 9", 0)
        );
        label->setText(QApplication::translate("SettingsFilter", "New filter", 0));
        btnLoad->setText(QApplication::translate("SettingsFilter", "load", 0));
        loaded->setText(QApplication::translate("SettingsFilter", "Loaded", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsFilter: public Ui_SettingsFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSFILTER_H
