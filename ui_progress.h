/********************************************************************************
** Form generated from reading UI file 'progress.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_H
#define UI_PROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Progress
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *calculated;
    QPushButton *open;
    QGroupBox *info;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QLabel *ac;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_7;
    QLabel *tp;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLabel *fp;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLabel *tn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_13;
    QLabel *fn;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLabel *p;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *imageB;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_10;
    QLabel *imageA;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *a;
    QLabel *b;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLabel *c;
    QLabel *d;

    void setupUi(QDialog *Progress)
    {
        if (Progress->objectName().isEmpty())
            Progress->setObjectName(QStringLiteral("Progress"));
        Progress->resize(673, 479);
        verticalLayout = new QVBoxLayout(Progress);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        calculated = new QPushButton(Progress);
        calculated->setObjectName(QStringLiteral("calculated"));
        calculated->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(calculated);

        open = new QPushButton(Progress);
        open->setObjectName(QStringLiteral("open"));
        open->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(open);


        horizontalLayout->addLayout(horizontalLayout_4);

        info = new QGroupBox(Progress);
        info->setObjectName(QStringLiteral("info"));
        verticalLayout_2 = new QVBoxLayout(info);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_4 = new QLabel(info);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_11->addWidget(label_4);

        ac = new QLabel(info);
        ac->setObjectName(QStringLiteral("ac"));

        horizontalLayout_11->addWidget(ac);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_7 = new QLabel(info);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_12->addWidget(label_7);

        tp = new QLabel(info);
        tp->setObjectName(QStringLiteral("tp"));

        horizontalLayout_12->addWidget(tp);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(info);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        fp = new QLabel(info);
        fp->setObjectName(QStringLiteral("fp"));

        horizontalLayout_10->addWidget(fp);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(info);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_9->addWidget(label_11);

        tn = new QLabel(info);
        tn->setObjectName(QStringLiteral("tn"));

        horizontalLayout_9->addWidget(tn);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_13 = new QLabel(info);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);

        fn = new QLabel(info);
        fn->setObjectName(QStringLiteral("fn"));

        horizontalLayout_5->addWidget(fn);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_15 = new QLabel(info);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_13->addWidget(label_15);

        p = new QLabel(info);
        p->setObjectName(QStringLiteral("p"));

        horizontalLayout_13->addWidget(p);


        verticalLayout_2->addLayout(horizontalLayout_13);


        horizontalLayout->addWidget(info);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(Progress);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(200, 30));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        imageB = new QLabel(Progress);
        imageB->setObjectName(QStringLiteral("imageB"));
        imageB->setMinimumSize(QSize(200, 100));
        imageB->setMaximumSize(QSize(200, 100));
        imageB->setFrameShape(QFrame::Box);
        imageB->setMidLineWidth(0);
        imageB->setScaledContents(true);
        imageB->setMargin(0);

        verticalLayout_4->addWidget(imageB);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_10 = new QLabel(Progress);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(200, 30));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_10);

        imageA = new QLabel(Progress);
        imageA->setObjectName(QStringLiteral("imageA"));
        imageA->setMinimumSize(QSize(200, 100));
        imageA->setMaximumSize(QSize(200, 100));
        imageA->setFrameShape(QFrame::Box);
        imageA->setScaledContents(true);
        imageA->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(imageA);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(Progress);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(200, 200));

        horizontalLayout_7->addWidget(label_3);

        label_2 = new QLabel(Progress);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(200, 50));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_2);

        label = new QLabel(Progress);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(200, 50));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(Progress);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(200, 50));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        a = new QLabel(Progress);
        a->setObjectName(QStringLiteral("a"));
        a->setMaximumSize(QSize(200, 250));
        a->setFrameShape(QFrame::Box);
        a->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(a);

        b = new QLabel(Progress);
        b->setObjectName(QStringLiteral("b"));
        b->setMaximumSize(QSize(200, 250));
        b->setFrameShape(QFrame::Box);
        b->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(b);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(Progress);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(200, 50));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_9);

        c = new QLabel(Progress);
        c->setObjectName(QStringLiteral("c"));
        c->setMaximumSize(QSize(200, 250));
        c->setFrameShape(QFrame::Box);
        c->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(c);

        d = new QLabel(Progress);
        d->setObjectName(QStringLiteral("d"));
        d->setMaximumSize(QSize(200, 250));
        d->setFrameShape(QFrame::Box);
        d->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(d);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Progress);

        QMetaObject::connectSlotsByName(Progress);
    } // setupUi

    void retranslateUi(QDialog *Progress)
    {
        Progress->setWindowTitle(QApplication::translate("Progress", "Dialog", 0));
        calculated->setText(QApplication::translate("Progress", "Calcular", 0));
        open->setText(QApplication::translate("Progress", "Open Image", 0));
        info->setTitle(QApplication::translate("Progress", "Info", 0));
        label_4->setText(QApplication::translate("Progress", "Accuary", 0));
        ac->setText(QString());
        label_7->setText(QApplication::translate("Progress", "true positive rate ", 0));
        tp->setText(QString());
        label_8->setText(QApplication::translate("Progress", "false positive rate", 0));
        fp->setText(QString());
        label_11->setText(QApplication::translate("Progress", "true negative rate", 0));
        tn->setText(QString());
        label_13->setText(QApplication::translate("Progress", "false negative rate", 0));
        fn->setText(QString());
        label_15->setText(QApplication::translate("Progress", "precision", 0));
        p->setText(QString());
        label_5->setText(QApplication::translate("Progress", "Prediction", 0));
        imageB->setText(QString());
        label_10->setText(QApplication::translate("Progress", "Actual", 0));
        imageA->setText(QString());
        label_3->setText(QString());
        label_2->setText(QApplication::translate("Progress", "No Vena", 0));
        label->setText(QApplication::translate("Progress", "Vena", 0));
        label_6->setText(QApplication::translate("Progress", "No vena", 0));
        a->setText(QString());
        b->setText(QString());
        label_9->setText(QApplication::translate("Progress", "Vena", 0));
        c->setText(QString());
        d->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Progress: public Ui_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_H
