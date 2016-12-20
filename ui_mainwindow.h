/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionRGB_to_RGB;
    QAction *actionRGB_to_YUV;
    QAction *actionRGB_to_CMY;
    QAction *actionRGB_to_HSV;
    QAction *actionRGB_to_HSL;
    QAction *actionRGB_to_XYZ;
    QAction *actionRGB_to_YIQ;
    QAction *actionRGB_to_O1O2O3;
    QAction *actionSettings;
    QAction *actionRGB_to_YYY;
    QAction *actionNormalizeHistograma;
    QAction *actionDemo;
    QAction *actionConvert_to_YYY;
    QAction *actionNew_Convertion;
    QAction *actionUndo;
    QAction *actionConfusion_table;
    QAction *actionSave_Step;
    QAction *actionShow_Step;
    QAction *actionLoad;
    QAction *actionApply;
    QAction *actionNew;
    QAction *actionSave_2;
    QAction *actionChannel1;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *convert;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_origin;
    QLabel *after;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_transform;
    QLabel *before;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btn_one;
    QLabel *r;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btn_two;
    QLabel *g;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn_three;
    QLabel *b;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_8;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QComboBox *kernelMinMedMax;
    QPushButton *btnAverage;
    QPushButton *btnGaussiano;
    QPushButton *btnMinimum;
    QPushButton *btnMedium;
    QPushButton *btnMaximum;
    QFrame *line_5;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_22;
    QSpinBox *numberSigma;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QSlider *sliderSigma;
    QPushButton *btnSigma;
    QPushButton *btnNagao;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_13;
    QSpinBox *threshold;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QSlider *horizontalSlider;
    QLabel *label_5;
    QPushButton *btnThreshold;
    QFrame *line;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *white;
    QRadioButton *black;
    QPushButton *btnRobert;
    QPushButton *btnPrewitt;
    QPushButton *btnSobel;
    QPushButton *btnEdgeDetection;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_12;
    QPushButton *btn_histograma;
    QGraphicsView *minHistograma;
    QComboBox *selectChannelHistograma;
    QPushButton *equalizarHistograma;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSlider *gamma;
    QPushButton *btnGamma;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *const_2;
    QPushButton *btnSubstract;
    QPushButton *btnPlus;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_17;
    QVBoxLayout *verticalLayout_18;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *sizeEstruc;
    QComboBox *optionsEstruc;
    QSpacerItem *verticalSpacer_6;
    QFrame *structure;
    QVBoxLayout *verticalLayout_21;
    QGridLayout *grid;
    QHBoxLayout *E_1;
    QLineEdit *e_1_0;
    QLineEdit *e_1_1;
    QLineEdit *e_1_2;
    QLineEdit *e_1_3;
    QLineEdit *e_1_4;
    QHBoxLayout *E_4;
    QLineEdit *e_4_0;
    QLineEdit *e_4_1;
    QLineEdit *e_4_2;
    QLineEdit *e_4_3;
    QLineEdit *e_4_4;
    QHBoxLayout *E_2;
    QLineEdit *e_2_0;
    QLineEdit *e_2_1;
    QLineEdit *e_2_2;
    QLineEdit *e_2_3;
    QLineEdit *e_2_4;
    QHBoxLayout *E_3;
    QLineEdit *e_3_0;
    QLineEdit *e_3_1;
    QLineEdit *e_3_2;
    QLineEdit *e_3_3;
    QLineEdit *e_3_4;
    QHBoxLayout *E_0;
    QLineEdit *e_0_0;
    QLineEdit *e_0_1;
    QLineEdit *e_0_2;
    QLineEdit *e_0_3;
    QLineEdit *e_0_4;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btnLeft;
    QPushButton *btnRight;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_20;
    QPushButton *btnDilation;
    QPushButton *btnErosion;
    QPushButton *btnOpening;
    QPushButton *btnClosing;
    QSpacerItem *verticalSpacer_4;
    QGraphicsView *histograma;
    QLabel *origin;
    QSpacerItem *verticalSpacer_8;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuConvert;
    QMenu *menuFilter;
    QMenu *menuContrast;
    QMenu *menuSettings;
    QMenu *menuMask;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2424, 712);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral("background-color: #f2f2f2;"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionRGB_to_RGB = new QAction(MainWindow);
        actionRGB_to_RGB->setObjectName(QStringLiteral("actionRGB_to_RGB"));
        actionRGB_to_YUV = new QAction(MainWindow);
        actionRGB_to_YUV->setObjectName(QStringLiteral("actionRGB_to_YUV"));
        actionRGB_to_CMY = new QAction(MainWindow);
        actionRGB_to_CMY->setObjectName(QStringLiteral("actionRGB_to_CMY"));
        actionRGB_to_HSV = new QAction(MainWindow);
        actionRGB_to_HSV->setObjectName(QStringLiteral("actionRGB_to_HSV"));
        actionRGB_to_HSL = new QAction(MainWindow);
        actionRGB_to_HSL->setObjectName(QStringLiteral("actionRGB_to_HSL"));
        actionRGB_to_XYZ = new QAction(MainWindow);
        actionRGB_to_XYZ->setObjectName(QStringLiteral("actionRGB_to_XYZ"));
        actionRGB_to_YIQ = new QAction(MainWindow);
        actionRGB_to_YIQ->setObjectName(QStringLiteral("actionRGB_to_YIQ"));
        actionRGB_to_O1O2O3 = new QAction(MainWindow);
        actionRGB_to_O1O2O3->setObjectName(QStringLiteral("actionRGB_to_O1O2O3"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionRGB_to_YYY = new QAction(MainWindow);
        actionRGB_to_YYY->setObjectName(QStringLiteral("actionRGB_to_YYY"));
        actionNormalizeHistograma = new QAction(MainWindow);
        actionNormalizeHistograma->setObjectName(QStringLiteral("actionNormalizeHistograma"));
        actionDemo = new QAction(MainWindow);
        actionDemo->setObjectName(QStringLiteral("actionDemo"));
        actionConvert_to_YYY = new QAction(MainWindow);
        actionConvert_to_YYY->setObjectName(QStringLiteral("actionConvert_to_YYY"));
        actionConvert_to_YYY->setEnabled(false);
        actionNew_Convertion = new QAction(MainWindow);
        actionNew_Convertion->setObjectName(QStringLiteral("actionNew_Convertion"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionConfusion_table = new QAction(MainWindow);
        actionConfusion_table->setObjectName(QStringLiteral("actionConfusion_table"));
        actionSave_Step = new QAction(MainWindow);
        actionSave_Step->setObjectName(QStringLiteral("actionSave_Step"));
        actionShow_Step = new QAction(MainWindow);
        actionShow_Step->setObjectName(QStringLiteral("actionShow_Step"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionApply = new QAction(MainWindow);
        actionApply->setObjectName(QStringLiteral("actionApply"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QStringLiteral("actionSave_2"));
        actionChannel1 = new QAction(MainWindow);
        actionChannel1->setObjectName(QStringLiteral("actionChannel1"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setSizeIncrement(QSize(-1, 0));
        centralWidget->setBaseSize(QSize(-1, 0));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_16 = new QVBoxLayout(centralWidget);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setMaximumSize(QSize(230, 640));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideRight);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        convert = new QWidget();
        convert->setObjectName(QStringLiteral("convert"));
        QFont font;
        font.setKerning(true);
        convert->setFont(font);
        convert->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout_7 = new QVBoxLayout(convert);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btn_origin = new QPushButton(convert);
        btn_origin->setObjectName(QStringLiteral("btn_origin"));
        btn_origin->setMinimumSize(QSize(0, 20));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        btn_origin->setFont(font1);
        btn_origin->setCursor(QCursor(Qt::PointingHandCursor));
        btn_origin->setFocusPolicy(Qt::NoFocus);
        btn_origin->setContextMenuPolicy(Qt::NoContextMenu);
        btn_origin->setToolTipDuration(-1);
        btn_origin->setAutoFillBackground(false);
        btn_origin->setStyleSheet(QStringLiteral(""));
        btn_origin->setFlat(true);

        verticalLayout_2->addWidget(btn_origin);

        after = new QLabel(convert);
        after->setObjectName(QStringLiteral("after"));
        after->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(after->sizePolicy().hasHeightForWidth());
        after->setSizePolicy(sizePolicy1);
        after->setMaximumSize(QSize(200, 100));
        after->setBaseSize(QSize(100, 100));
        after->setMouseTracking(false);
        after->setStyleSheet(QStringLiteral(""));
        after->setFrameShape(QFrame::Box);
        after->setScaledContents(true);
        after->setAlignment(Qt::AlignCenter);
        after->setWordWrap(true);

        verticalLayout_2->addWidget(after);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btn_transform = new QPushButton(convert);
        btn_transform->setObjectName(QStringLiteral("btn_transform"));
        btn_transform->setEnabled(false);
        btn_transform->setMinimumSize(QSize(0, 20));
        btn_transform->setCursor(QCursor(Qt::PointingHandCursor));
        btn_transform->setFocusPolicy(Qt::NoFocus);
        btn_transform->setContextMenuPolicy(Qt::NoContextMenu);
        btn_transform->setToolTipDuration(-1);
        btn_transform->setAutoFillBackground(false);
        btn_transform->setStyleSheet(QStringLiteral(""));
        btn_transform->setFlat(true);

        verticalLayout_3->addWidget(btn_transform);

        before = new QLabel(convert);
        before->setObjectName(QStringLiteral("before"));
        sizePolicy1.setHeightForWidth(before->sizePolicy().hasHeightForWidth());
        before->setSizePolicy(sizePolicy1);
        before->setMaximumSize(QSize(200, 100));
        before->setBaseSize(QSize(100, 100));
        before->setStyleSheet(QStringLiteral(""));
        before->setFrameShape(QFrame::Box);
        before->setScaledContents(true);
        before->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(before);


        verticalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        btn_one = new QPushButton(convert);
        btn_one->setObjectName(QStringLiteral("btn_one"));
        btn_one->setEnabled(false);
        btn_one->setMinimumSize(QSize(0, 20));
        btn_one->setCursor(QCursor(Qt::PointingHandCursor));
        btn_one->setAutoFillBackground(false);
        btn_one->setStyleSheet(QStringLiteral(""));
        btn_one->setFlat(true);

        verticalLayout_4->addWidget(btn_one);

        r = new QLabel(convert);
        r->setObjectName(QStringLiteral("r"));
        sizePolicy1.setHeightForWidth(r->sizePolicy().hasHeightForWidth());
        r->setSizePolicy(sizePolicy1);
        r->setMaximumSize(QSize(200, 100));
        r->setBaseSize(QSize(100, 100));
        r->setStyleSheet(QStringLiteral(""));
        r->setFrameShape(QFrame::Box);
        r->setScaledContents(true);
        r->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(r);


        verticalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        btn_two = new QPushButton(convert);
        btn_two->setObjectName(QStringLiteral("btn_two"));
        btn_two->setEnabled(false);
        btn_two->setMinimumSize(QSize(0, 20));
        btn_two->setCursor(QCursor(Qt::PointingHandCursor));
        btn_two->setAutoFillBackground(false);
        btn_two->setStyleSheet(QStringLiteral(""));
        btn_two->setFlat(true);

        verticalLayout_5->addWidget(btn_two);

        g = new QLabel(convert);
        g->setObjectName(QStringLiteral("g"));
        sizePolicy1.setHeightForWidth(g->sizePolicy().hasHeightForWidth());
        g->setSizePolicy(sizePolicy1);
        g->setMaximumSize(QSize(200, 100));
        g->setBaseSize(QSize(100, 100));
        g->setStyleSheet(QStringLiteral(""));
        g->setFrameShape(QFrame::Box);
        g->setScaledContents(true);
        g->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(g);


        verticalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btn_three = new QPushButton(convert);
        btn_three->setObjectName(QStringLiteral("btn_three"));
        btn_three->setEnabled(false);
        btn_three->setMinimumSize(QSize(0, 20));
        btn_three->setCursor(QCursor(Qt::PointingHandCursor));
        btn_three->setAutoFillBackground(false);
        btn_three->setStyleSheet(QStringLiteral(""));
        btn_three->setFlat(true);

        verticalLayout_6->addWidget(btn_three);

        b = new QLabel(convert);
        b->setObjectName(QStringLiteral("b"));
        sizePolicy1.setHeightForWidth(b->sizePolicy().hasHeightForWidth());
        b->setSizePolicy(sizePolicy1);
        b->setMaximumSize(QSize(200, 100));
        b->setBaseSize(QSize(100, 100));
        b->setStyleSheet(QStringLiteral(""));
        b->setFrameShape(QFrame::Box);
        b->setScaledContents(true);
        b->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(b);


        verticalLayout->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(verticalLayout);

        tabWidget->addTab(convert, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_8 = new QVBoxLayout(tab_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        toolBox = new QToolBox(tab_2);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 168, 542));
        verticalLayout_10 = new QVBoxLayout(page);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, 0, -1, -1);
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_11->addWidget(label_6);

        kernelMinMedMax = new QComboBox(page);
        kernelMinMedMax->setObjectName(QStringLiteral("kernelMinMedMax"));

        horizontalLayout_11->addWidget(kernelMinMedMax);


        verticalLayout_10->addLayout(horizontalLayout_11);

        btnAverage = new QPushButton(page);
        btnAverage->setObjectName(QStringLiteral("btnAverage"));
        btnAverage->setEnabled(false);
        btnAverage->setMinimumSize(QSize(0, 50));
        btnAverage->setMaximumSize(QSize(16777215, 50));
        btnAverage->setCursor(QCursor(Qt::PointingHandCursor));
        btnAverage->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/average.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnAverage->setIcon(icon1);
        btnAverage->setIconSize(QSize(35, 35));
        btnAverage->setFlat(true);

        verticalLayout_10->addWidget(btnAverage);

        btnGaussiano = new QPushButton(page);
        btnGaussiano->setObjectName(QStringLiteral("btnGaussiano"));
        btnGaussiano->setEnabled(false);
        btnGaussiano->setMinimumSize(QSize(0, 50));
        btnGaussiano->setCursor(QCursor(Qt::PointingHandCursor));
        btnGaussiano->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/gauss.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnGaussiano->setIcon(icon2);
        btnGaussiano->setIconSize(QSize(35, 35));

        verticalLayout_10->addWidget(btnGaussiano);

        btnMinimum = new QPushButton(page);
        btnMinimum->setObjectName(QStringLiteral("btnMinimum"));
        btnMinimum->setEnabled(false);
        btnMinimum->setMinimumSize(QSize(0, 50));
        btnMinimum->setCursor(QCursor(Qt::PointingHandCursor));
        btnMinimum->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/minimum.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnMinimum->setIcon(icon3);
        btnMinimum->setIconSize(QSize(35, 35));

        verticalLayout_10->addWidget(btnMinimum);

        btnMedium = new QPushButton(page);
        btnMedium->setObjectName(QStringLiteral("btnMedium"));
        btnMedium->setEnabled(false);
        btnMedium->setMinimumSize(QSize(0, 50));
        btnMedium->setCursor(QCursor(Qt::PointingHandCursor));
        btnMedium->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/medium_rain-128.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnMedium->setIcon(icon4);
        btnMedium->setIconSize(QSize(35, 35));

        verticalLayout_10->addWidget(btnMedium);

        btnMaximum = new QPushButton(page);
        btnMaximum->setObjectName(QStringLiteral("btnMaximum"));
        btnMaximum->setEnabled(false);
        btnMaximum->setMinimumSize(QSize(0, 50));
        btnMaximum->setCursor(QCursor(Qt::PointingHandCursor));
        btnMaximum->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/max.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnMaximum->setIcon(icon5);
        btnMaximum->setIconSize(QSize(35, 35));

        verticalLayout_10->addWidget(btnMaximum);

        line_5 = new QFrame(page);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setStyleSheet(QStringLiteral("border: 1px solid #F05542;margin-top:3px;"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_5);

        groupBox_8 = new QGroupBox(page);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setStyleSheet(QStringLiteral("border: 1px solid #F05542;"));
        groupBox_8->setAlignment(Qt::AlignCenter);
        verticalLayout_22 = new QVBoxLayout(groupBox_8);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(-1, 14, -1, -1);
        numberSigma = new QSpinBox(groupBox_8);
        numberSigma->setObjectName(QStringLiteral("numberSigma"));
        numberSigma->setEnabled(true);
        numberSigma->setStyleSheet(QStringLiteral("border:none;"));
        numberSigma->setMaximum(255);

        verticalLayout_22->addWidget(numberSigma);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16, 16));
        label_4->setStyleSheet(QStringLiteral("border:none;"));
        label_4->setTextFormat(Qt::PlainText);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/img/sigma.ico")));
        label_4->setScaledContents(true);

        horizontalLayout_6->addWidget(label_4);

        sliderSigma = new QSlider(groupBox_8);
        sliderSigma->setObjectName(QStringLiteral("sliderSigma"));
        sliderSigma->setStyleSheet(QStringLiteral("border:none;"));
        sliderSigma->setMaximum(255);
        sliderSigma->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(sliderSigma);


        verticalLayout_22->addLayout(horizontalLayout_6);

        btnSigma = new QPushButton(groupBox_8);
        btnSigma->setObjectName(QStringLiteral("btnSigma"));
        btnSigma->setMinimumSize(QSize(0, 30));
        btnSigma->setCursor(QCursor(Qt::PointingHandCursor));
        btnSigma->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 2px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 2px solid #F6863A;\n"
"}\n"
""));

        verticalLayout_22->addWidget(btnSigma);


        verticalLayout_10->addWidget(groupBox_8);

        btnNagao = new QPushButton(page);
        btnNagao->setObjectName(QStringLiteral("btnNagao"));
        btnNagao->setMinimumSize(QSize(0, 50));
        btnNagao->setCursor(QCursor(Qt::PointingHandCursor));
        btnNagao->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/nagao.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnNagao->setIcon(icon6);
        btnNagao->setIconSize(QSize(35, 35));
        btnNagao->setAutoDefault(false);
        btnNagao->setFlat(false);

        verticalLayout_10->addWidget(btnNagao);

        toolBox->addItem(page, QStringLiteral("Low pass"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 152, 462));
        verticalLayout_11 = new QVBoxLayout(page_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("border: 1px solid #F05542;margin-top:5px"));
        groupBox->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_13 = new QVBoxLayout(groupBox);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(9, -1, 9, -1);
        threshold = new QSpinBox(groupBox);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setEnabled(true);
        threshold->setMinimumSize(QSize(0, 25));
        threshold->setStyleSheet(QStringLiteral("border:none;"));
        threshold->setMaximum(255);

        verticalLayout_13->addWidget(threshold);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("border:none;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setStyleSheet(QStringLiteral("border:none;"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider);


        verticalLayout_13->addLayout(horizontalLayout_5);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("border:none;"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_5);

        btnThreshold = new QPushButton(groupBox);
        btnThreshold->setObjectName(QStringLiteral("btnThreshold"));
        btnThreshold->setMinimumSize(QSize(0, 50));
        btnThreshold->setCursor(QCursor(Qt::PointingHandCursor));
        btnThreshold->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));

        verticalLayout_13->addWidget(btnThreshold);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(0, 0));
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(line);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 30));
        groupBox_4->setStyleSheet(QStringLiteral("border:none"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        horizontalLayout_9 = new QHBoxLayout(groupBox_4);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(9, 0, -1, 0);
        white = new QRadioButton(groupBox_4);
        white->setObjectName(QStringLiteral("white"));
        white->setStyleSheet(QStringLiteral("border:none;"));
        white->setChecked(true);

        horizontalLayout_9->addWidget(white);

        black = new QRadioButton(groupBox_4);
        black->setObjectName(QStringLiteral("black"));
        black->setStyleSheet(QStringLiteral("border:none;"));

        horizontalLayout_9->addWidget(black);


        verticalLayout_13->addWidget(groupBox_4);

        btnRobert = new QPushButton(groupBox);
        btnRobert->setObjectName(QStringLiteral("btnRobert"));
        btnRobert->setMinimumSize(QSize(0, 50));
        btnRobert->setCursor(QCursor(Qt::PointingHandCursor));
        btnRobert->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/roberts.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnRobert->setIcon(icon7);
        btnRobert->setIconSize(QSize(35, 35));

        verticalLayout_13->addWidget(btnRobert);

        btnPrewitt = new QPushButton(groupBox);
        btnPrewitt->setObjectName(QStringLiteral("btnPrewitt"));
        btnPrewitt->setMinimumSize(QSize(0, 50));
        btnPrewitt->setCursor(QCursor(Qt::PointingHandCursor));
        btnPrewitt->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/prewitt.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnPrewitt->setIcon(icon8);
        btnPrewitt->setIconSize(QSize(35, 35));

        verticalLayout_13->addWidget(btnPrewitt);

        btnSobel = new QPushButton(groupBox);
        btnSobel->setObjectName(QStringLiteral("btnSobel"));
        btnSobel->setMinimumSize(QSize(0, 50));
        btnSobel->setCursor(QCursor(Qt::PointingHandCursor));
        btnSobel->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/sobel.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnSobel->setIcon(icon9);
        btnSobel->setIconSize(QSize(35, 35));

        verticalLayout_13->addWidget(btnSobel);

        btnEdgeDetection = new QPushButton(groupBox);
        btnEdgeDetection->setObjectName(QStringLiteral("btnEdgeDetection"));
        btnEdgeDetection->setMinimumSize(QSize(0, 30));
        btnEdgeDetection->setCursor(QCursor(Qt::PointingHandCursor));
        btnEdgeDetection->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 2px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 2px solid #F6863A;\n"
"}\n"
""));

        verticalLayout_13->addWidget(btnEdgeDetection);


        verticalLayout_11->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_2);

        toolBox->addItem(page_2, QStringLiteral("High pass"));

        verticalLayout_8->addWidget(toolBox);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_15 = new QVBoxLayout(tab);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        btn_histograma = new QPushButton(tab);
        btn_histograma->setObjectName(QStringLiteral("btn_histograma"));
        btn_histograma->setCursor(QCursor(Qt::PointingHandCursor));
        btn_histograma->setFlat(true);

        verticalLayout_12->addWidget(btn_histograma);

        minHistograma = new QGraphicsView(tab);
        minHistograma->setObjectName(QStringLiteral("minHistograma"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(minHistograma->sizePolicy().hasHeightForWidth());
        minHistograma->setSizePolicy(sizePolicy2);
        minHistograma->setMinimumSize(QSize(0, 200));
        minHistograma->setMaximumSize(QSize(16777214, 200));
        minHistograma->setContextMenuPolicy(Qt::DefaultContextMenu);
        minHistograma->setLayoutDirection(Qt::LeftToRight);
        minHistograma->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        minHistograma->setLocale(QLocale(QLocale::English, QLocale::Kenya));
        minHistograma->setFrameShape(QFrame::Box);
        minHistograma->setFrameShadow(QFrame::Plain);
        minHistograma->setLineWidth(1);
        minHistograma->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        minHistograma->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        minHistograma->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        minHistograma->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        minHistograma->setTransformationAnchor(QGraphicsView::NoAnchor);
        minHistograma->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
        minHistograma->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        minHistograma->setRubberBandSelectionMode(Qt::ContainsItemBoundingRect);
        minHistograma->setOptimizationFlags(QGraphicsView::IndirectPainting);

        verticalLayout_12->addWidget(minHistograma);

        selectChannelHistograma = new QComboBox(tab);
        selectChannelHistograma->setObjectName(QStringLiteral("selectChannelHistograma"));

        verticalLayout_12->addWidget(selectChannelHistograma);


        verticalLayout_9->addLayout(verticalLayout_12);

        equalizarHistograma = new QPushButton(tab);
        equalizarHistograma->setObjectName(QStringLiteral("equalizarHistograma"));
        equalizarHistograma->setMinimumSize(QSize(0, 50));
        equalizarHistograma->setMaximumSize(QSize(16777215, 50));
        equalizarHistograma->setCursor(QCursor(Qt::PointingHandCursor));
        equalizarHistograma->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/equalizer.ico"), QSize(), QIcon::Normal, QIcon::On);
        equalizarHistograma->setIcon(icon10);
        equalizarHistograma->setIconSize(QSize(35, 35));

        verticalLayout_9->addWidget(equalizarHistograma);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QStringLiteral("border: 1px solid #F05542;"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout_14 = new QVBoxLayout(groupBox_2);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("border:none;"));

        horizontalLayout_4->addWidget(label);

        gamma = new QSlider(groupBox_2);
        gamma->setObjectName(QStringLiteral("gamma"));
        gamma->setStyleSheet(QStringLiteral("border:none;"));
        gamma->setMaximum(3000);
        gamma->setPageStep(10);
        gamma->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(gamma);


        verticalLayout_14->addLayout(horizontalLayout_4);

        btnGamma = new QPushButton(groupBox_2);
        btnGamma->setObjectName(QStringLiteral("btnGamma"));
        btnGamma->setMinimumSize(QSize(0, 30));
        btnGamma->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_14->addWidget(btnGamma);

        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setEnabled(true);
        line_2->setMaximumSize(QSize(16777215, 1));
        line_2->setStyleSheet(QStringLiteral(""));
        line_2->setLineWidth(1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_14->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("border:none;"));

        horizontalLayout_2->addWidget(label_2);

        const_2 = new QDoubleSpinBox(groupBox_2);
        const_2->setObjectName(QStringLiteral("const_2"));
        const_2->setStyleSheet(QStringLiteral("border:1px solid #F05542;"));
        const_2->setDecimals(3);
        const_2->setMaximum(255);

        horizontalLayout_2->addWidget(const_2);


        verticalLayout_14->addLayout(horizontalLayout_2);

        btnSubstract = new QPushButton(groupBox_2);
        btnSubstract->setObjectName(QStringLiteral("btnSubstract"));
        btnSubstract->setMinimumSize(QSize(0, 50));
        btnSubstract->setMaximumSize(QSize(16777215, 50));
        btnSubstract->setCursor(QCursor(Qt::PointingHandCursor));
        btnSubstract->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/substract.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnSubstract->setIcon(icon11);
        btnSubstract->setIconSize(QSize(35, 35));

        verticalLayout_14->addWidget(btnSubstract);

        btnPlus = new QPushButton(groupBox_2);
        btnPlus->setObjectName(QStringLiteral("btnPlus"));
        btnPlus->setMinimumSize(QSize(0, 50));
        btnPlus->setMaximumSize(QSize(16777215, 50));
        btnPlus->setCursor(QCursor(Qt::PointingHandCursor));
        btnPlus->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/plus.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnPlus->setIcon(icon12);
        btnPlus->setIconSize(QSize(35, 35));

        verticalLayout_14->addWidget(btnPlus);

        btnPlus->raise();
        btnSubstract->raise();
        line_2->raise();
        btnGamma->raise();

        verticalLayout_9->addWidget(groupBox_2);


        verticalLayout_15->addLayout(verticalLayout_9);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_17 = new QVBoxLayout(tab_3);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(-1, 0, -1, -1);
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(0, 240));
        groupBox_6->setMaximumSize(QSize(16777215, 400));
        groupBox_6->setStyleSheet(QStringLiteral("border: 1px solid #F05542;"));
        groupBox_6->setAlignment(Qt::AlignCenter);
        verticalLayout_19 = new QVBoxLayout(groupBox_6);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(-1, 20, -1, -1);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        sizeEstruc = new QComboBox(groupBox_6);
        sizeEstruc->setObjectName(QStringLiteral("sizeEstruc"));
        sizeEstruc->setStyleSheet(QStringLiteral("border: 1px solid grey"));

        horizontalLayout_8->addWidget(sizeEstruc);

        optionsEstruc = new QComboBox(groupBox_6);
        optionsEstruc->setObjectName(QStringLiteral("optionsEstruc"));
        optionsEstruc->setStyleSheet(QStringLiteral("border: 1px solid grey"));

        horizontalLayout_8->addWidget(optionsEstruc);


        verticalLayout_19->addLayout(horizontalLayout_8);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_6);

        structure = new QFrame(groupBox_6);
        structure->setObjectName(QStringLiteral("structure"));
        structure->setMinimumSize(QSize(0, 0));
        structure->setStyleSheet(QStringLiteral("border: none"));
        structure->setFrameShape(QFrame::StyledPanel);
        structure->setFrameShadow(QFrame::Raised);
        verticalLayout_21 = new QVBoxLayout(structure);
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        grid = new QGridLayout();
        grid->setSpacing(6);
        grid->setObjectName(QStringLiteral("grid"));
        E_1 = new QHBoxLayout();
        E_1->setSpacing(6);
        E_1->setObjectName(QStringLiteral("E_1"));
        e_1_0 = new QLineEdit(structure);
        e_1_0->setObjectName(QStringLiteral("e_1_0"));
        e_1_0->setEnabled(false);
        e_1_0->setMinimumSize(QSize(0, 0));
        e_1_0->setMaximumSize(QSize(20, 20));
        e_1_0->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_1_0->setAlignment(Qt::AlignCenter);

        E_1->addWidget(e_1_0);

        e_1_1 = new QLineEdit(structure);
        e_1_1->setObjectName(QStringLiteral("e_1_1"));
        e_1_1->setEnabled(false);
        e_1_1->setMinimumSize(QSize(0, 0));
        e_1_1->setMaximumSize(QSize(20, 20));
        e_1_1->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_1_1->setAlignment(Qt::AlignCenter);

        E_1->addWidget(e_1_1);

        e_1_2 = new QLineEdit(structure);
        e_1_2->setObjectName(QStringLiteral("e_1_2"));
        e_1_2->setEnabled(false);
        e_1_2->setMinimumSize(QSize(0, 0));
        e_1_2->setMaximumSize(QSize(20, 20));
        e_1_2->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_1_2->setAlignment(Qt::AlignCenter);

        E_1->addWidget(e_1_2);

        e_1_3 = new QLineEdit(structure);
        e_1_3->setObjectName(QStringLiteral("e_1_3"));
        e_1_3->setEnabled(false);
        e_1_3->setMinimumSize(QSize(0, 0));
        e_1_3->setMaximumSize(QSize(20, 20));
        e_1_3->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_1_3->setAlignment(Qt::AlignCenter);

        E_1->addWidget(e_1_3);

        e_1_4 = new QLineEdit(structure);
        e_1_4->setObjectName(QStringLiteral("e_1_4"));
        e_1_4->setEnabled(false);
        e_1_4->setMinimumSize(QSize(0, 0));
        e_1_4->setMaximumSize(QSize(20, 20));
        e_1_4->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_1_4->setAlignment(Qt::AlignCenter);

        E_1->addWidget(e_1_4);


        grid->addLayout(E_1, 2, 0, 1, 1);

        E_4 = new QHBoxLayout();
        E_4->setSpacing(6);
        E_4->setObjectName(QStringLiteral("E_4"));
        e_4_0 = new QLineEdit(structure);
        e_4_0->setObjectName(QStringLiteral("e_4_0"));
        e_4_0->setEnabled(false);
        e_4_0->setMinimumSize(QSize(0, 0));
        e_4_0->setMaximumSize(QSize(20, 20));
        e_4_0->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_4_0->setAlignment(Qt::AlignCenter);

        E_4->addWidget(e_4_0);

        e_4_1 = new QLineEdit(structure);
        e_4_1->setObjectName(QStringLiteral("e_4_1"));
        e_4_1->setEnabled(false);
        e_4_1->setMinimumSize(QSize(0, 0));
        e_4_1->setMaximumSize(QSize(20, 20));
        e_4_1->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_4_1->setAlignment(Qt::AlignCenter);

        E_4->addWidget(e_4_1);

        e_4_2 = new QLineEdit(structure);
        e_4_2->setObjectName(QStringLiteral("e_4_2"));
        e_4_2->setEnabled(false);
        e_4_2->setMinimumSize(QSize(0, 0));
        e_4_2->setMaximumSize(QSize(20, 20));
        e_4_2->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_4_2->setAlignment(Qt::AlignCenter);

        E_4->addWidget(e_4_2);

        e_4_3 = new QLineEdit(structure);
        e_4_3->setObjectName(QStringLiteral("e_4_3"));
        e_4_3->setEnabled(false);
        e_4_3->setMinimumSize(QSize(0, 0));
        e_4_3->setMaximumSize(QSize(20, 20));
        e_4_3->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_4_3->setAlignment(Qt::AlignCenter);

        E_4->addWidget(e_4_3);

        e_4_4 = new QLineEdit(structure);
        e_4_4->setObjectName(QStringLiteral("e_4_4"));
        e_4_4->setEnabled(false);
        e_4_4->setMinimumSize(QSize(0, 0));
        e_4_4->setMaximumSize(QSize(20, 20));
        e_4_4->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_4_4->setAlignment(Qt::AlignCenter);

        E_4->addWidget(e_4_4);


        grid->addLayout(E_4, 5, 0, 1, 1);

        E_2 = new QHBoxLayout();
        E_2->setSpacing(6);
        E_2->setObjectName(QStringLiteral("E_2"));
        e_2_0 = new QLineEdit(structure);
        e_2_0->setObjectName(QStringLiteral("e_2_0"));
        e_2_0->setEnabled(false);
        e_2_0->setMinimumSize(QSize(0, 0));
        e_2_0->setMaximumSize(QSize(20, 20));
        e_2_0->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_2_0->setAlignment(Qt::AlignCenter);

        E_2->addWidget(e_2_0);

        e_2_1 = new QLineEdit(structure);
        e_2_1->setObjectName(QStringLiteral("e_2_1"));
        e_2_1->setEnabled(false);
        e_2_1->setMinimumSize(QSize(0, 0));
        e_2_1->setMaximumSize(QSize(20, 20));
        e_2_1->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_2_1->setAlignment(Qt::AlignCenter);

        E_2->addWidget(e_2_1);

        e_2_2 = new QLineEdit(structure);
        e_2_2->setObjectName(QStringLiteral("e_2_2"));
        e_2_2->setEnabled(false);
        e_2_2->setMinimumSize(QSize(0, 0));
        e_2_2->setMaximumSize(QSize(20, 20));
        e_2_2->setStyleSheet(QStringLiteral("border: 1px solid #F05542;"));
        e_2_2->setAlignment(Qt::AlignCenter);

        E_2->addWidget(e_2_2);

        e_2_3 = new QLineEdit(structure);
        e_2_3->setObjectName(QStringLiteral("e_2_3"));
        e_2_3->setEnabled(false);
        e_2_3->setMinimumSize(QSize(0, 0));
        e_2_3->setMaximumSize(QSize(20, 20));
        e_2_3->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_2_3->setAlignment(Qt::AlignCenter);

        E_2->addWidget(e_2_3);

        e_2_4 = new QLineEdit(structure);
        e_2_4->setObjectName(QStringLiteral("e_2_4"));
        e_2_4->setEnabled(false);
        e_2_4->setMinimumSize(QSize(0, 0));
        e_2_4->setMaximumSize(QSize(20, 20));
        e_2_4->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_2_4->setAlignment(Qt::AlignCenter);

        E_2->addWidget(e_2_4);


        grid->addLayout(E_2, 3, 0, 1, 1);

        E_3 = new QHBoxLayout();
        E_3->setSpacing(6);
        E_3->setObjectName(QStringLiteral("E_3"));
        e_3_0 = new QLineEdit(structure);
        e_3_0->setObjectName(QStringLiteral("e_3_0"));
        e_3_0->setEnabled(false);
        e_3_0->setMinimumSize(QSize(0, 0));
        e_3_0->setMaximumSize(QSize(20, 20));
        e_3_0->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_3_0->setAlignment(Qt::AlignCenter);

        E_3->addWidget(e_3_0);

        e_3_1 = new QLineEdit(structure);
        e_3_1->setObjectName(QStringLiteral("e_3_1"));
        e_3_1->setEnabled(false);
        e_3_1->setMinimumSize(QSize(0, 0));
        e_3_1->setMaximumSize(QSize(20, 20));
        e_3_1->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_3_1->setAlignment(Qt::AlignCenter);

        E_3->addWidget(e_3_1);

        e_3_2 = new QLineEdit(structure);
        e_3_2->setObjectName(QStringLiteral("e_3_2"));
        e_3_2->setEnabled(false);
        e_3_2->setMinimumSize(QSize(0, 0));
        e_3_2->setMaximumSize(QSize(20, 20));
        e_3_2->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_3_2->setAlignment(Qt::AlignCenter);

        E_3->addWidget(e_3_2);

        e_3_3 = new QLineEdit(structure);
        e_3_3->setObjectName(QStringLiteral("e_3_3"));
        e_3_3->setEnabled(false);
        e_3_3->setMinimumSize(QSize(0, 0));
        e_3_3->setMaximumSize(QSize(20, 20));
        e_3_3->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_3_3->setAlignment(Qt::AlignCenter);

        E_3->addWidget(e_3_3);

        e_3_4 = new QLineEdit(structure);
        e_3_4->setObjectName(QStringLiteral("e_3_4"));
        e_3_4->setEnabled(false);
        e_3_4->setMinimumSize(QSize(0, 0));
        e_3_4->setMaximumSize(QSize(20, 20));
        e_3_4->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_3_4->setAlignment(Qt::AlignCenter);

        E_3->addWidget(e_3_4);


        grid->addLayout(E_3, 4, 0, 1, 1);

        E_0 = new QHBoxLayout();
        E_0->setSpacing(6);
        E_0->setObjectName(QStringLiteral("E_0"));
        e_0_0 = new QLineEdit(structure);
        e_0_0->setObjectName(QStringLiteral("e_0_0"));
        e_0_0->setEnabled(false);
        e_0_0->setMinimumSize(QSize(0, 0));
        e_0_0->setMaximumSize(QSize(20, 20));
        e_0_0->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_0_0->setAlignment(Qt::AlignCenter);

        E_0->addWidget(e_0_0);

        e_0_1 = new QLineEdit(structure);
        e_0_1->setObjectName(QStringLiteral("e_0_1"));
        e_0_1->setEnabled(false);
        e_0_1->setMinimumSize(QSize(0, 0));
        e_0_1->setMaximumSize(QSize(20, 20));
        e_0_1->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_0_1->setAlignment(Qt::AlignCenter);

        E_0->addWidget(e_0_1);

        e_0_2 = new QLineEdit(structure);
        e_0_2->setObjectName(QStringLiteral("e_0_2"));
        e_0_2->setEnabled(false);
        e_0_2->setMinimumSize(QSize(0, 0));
        e_0_2->setMaximumSize(QSize(20, 20));
        e_0_2->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_0_2->setAlignment(Qt::AlignCenter);

        E_0->addWidget(e_0_2);

        e_0_3 = new QLineEdit(structure);
        e_0_3->setObjectName(QStringLiteral("e_0_3"));
        e_0_3->setEnabled(false);
        e_0_3->setMinimumSize(QSize(0, 0));
        e_0_3->setMaximumSize(QSize(20, 20));
        e_0_3->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_0_3->setAlignment(Qt::AlignCenter);

        E_0->addWidget(e_0_3);

        e_0_4 = new QLineEdit(structure);
        e_0_4->setObjectName(QStringLiteral("e_0_4"));
        e_0_4->setEnabled(false);
        e_0_4->setMinimumSize(QSize(0, 0));
        e_0_4->setMaximumSize(QSize(20, 20));
        e_0_4->setStyleSheet(QStringLiteral("border: 1px solid grey"));
        e_0_4->setAlignment(Qt::AlignCenter);

        E_0->addWidget(e_0_4);


        grid->addLayout(E_0, 1, 0, 1, 1);


        verticalLayout_21->addLayout(grid);


        verticalLayout_19->addWidget(structure);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 0, -1, -1);
        btnLeft = new QPushButton(groupBox_6);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        btnLeft->setEnabled(false);
        btnLeft->setMinimumSize(QSize(0, 20));
        btnLeft->setCursor(QCursor(Qt::PointingHandCursor));
        btnLeft->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));

        horizontalLayout_10->addWidget(btnLeft);

        btnRight = new QPushButton(groupBox_6);
        btnRight->setObjectName(QStringLiteral("btnRight"));
        btnRight->setMinimumSize(QSize(0, 20));
        btnRight->setCursor(QCursor(Qt::PointingHandCursor));
        btnRight->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));

        horizontalLayout_10->addWidget(btnRight);


        verticalLayout_19->addLayout(horizontalLayout_10);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_19->addItem(verticalSpacer_3);


        verticalLayout_18->addWidget(groupBox_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer);

        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setStyleSheet(QStringLiteral("border: 1px solid #F05542;margin-top:3px;"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_18->addWidget(line_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_5);

        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 50));
        groupBox_7->setCursor(QCursor(Qt::PointingHandCursor));
        groupBox_7->setStyleSheet(QStringLiteral("border: 1px solid #F05542;"));
        groupBox_7->setAlignment(Qt::AlignCenter);
        verticalLayout_20 = new QVBoxLayout(groupBox_7);
        verticalLayout_20->setSpacing(12);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(-1, 20, -1, -1);
        btnDilation = new QPushButton(groupBox_7);
        btnDilation->setObjectName(QStringLiteral("btnDilation"));
        btnDilation->setEnabled(false);
        btnDilation->setMinimumSize(QSize(0, 50));
        btnDilation->setCursor(QCursor(Qt::PointingHandCursor));
        btnDilation->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/img/dilation.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnDilation->setIcon(icon13);
        btnDilation->setIconSize(QSize(35, 35));
        btnDilation->setFlat(true);

        verticalLayout_20->addWidget(btnDilation);

        btnErosion = new QPushButton(groupBox_7);
        btnErosion->setObjectName(QStringLiteral("btnErosion"));
        btnErosion->setEnabled(false);
        btnErosion->setMinimumSize(QSize(0, 50));
        btnErosion->setCursor(QCursor(Qt::PointingHandCursor));
        btnErosion->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/img/erosion.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnErosion->setIcon(icon14);
        btnErosion->setIconSize(QSize(35, 35));
        btnErosion->setFlat(true);

        verticalLayout_20->addWidget(btnErosion);

        btnOpening = new QPushButton(groupBox_7);
        btnOpening->setObjectName(QStringLiteral("btnOpening"));
        btnOpening->setEnabled(false);
        btnOpening->setMinimumSize(QSize(0, 50));
        btnOpening->setCursor(QCursor(Qt::PointingHandCursor));
        btnOpening->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/img/opening.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnOpening->setIcon(icon15);
        btnOpening->setIconSize(QSize(35, 35));

        verticalLayout_20->addWidget(btnOpening);

        btnClosing = new QPushButton(groupBox_7);
        btnClosing->setObjectName(QStringLiteral("btnClosing"));
        btnClosing->setEnabled(false);
        btnClosing->setMinimumSize(QSize(0, 50));
        btnClosing->setCursor(QCursor(Qt::PointingHandCursor));
        btnClosing->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/img/closing.ico"), QSize(), QIcon::Normal, QIcon::On);
        btnClosing->setIcon(icon16);
        btnClosing->setIconSize(QSize(35, 35));

        verticalLayout_20->addWidget(btnClosing);


        verticalLayout_18->addWidget(groupBox_7);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_4);


        verticalLayout_17->addLayout(verticalLayout_18);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        histograma = new QGraphicsView(centralWidget);
        histograma->setObjectName(QStringLiteral("histograma"));
        histograma->setMinimumSize(QSize(1100, 640));
        histograma->setMaximumSize(QSize(1100, 640));
        histograma->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        histograma->setFrameShape(QFrame::StyledPanel);
        histograma->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::NoBrush);
        histograma->setBackgroundBrush(brush);
        histograma->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        histograma->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        histograma->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        histograma->setRubberBandSelectionMode(Qt::IntersectsItemShape);

        horizontalLayout->addWidget(histograma);

        origin = new QLabel(centralWidget);
        origin->setObjectName(QStringLiteral("origin"));
        origin->setMinimumSize(QSize(1100, 640));
        origin->setMaximumSize(QSize(1100, 640));
        origin->setFrameShape(QFrame::Box);
        origin->setScaledContents(true);
        origin->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(origin);


        verticalLayout_16->addLayout(horizontalLayout);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_8);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 2424, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuConvert = new QMenu(menuBar);
        menuConvert->setObjectName(QStringLiteral("menuConvert"));
        menuFilter = new QMenu(menuBar);
        menuFilter->setObjectName(QStringLiteral("menuFilter"));
        menuContrast = new QMenu(menuBar);
        menuContrast->setObjectName(QStringLiteral("menuContrast"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuMask = new QMenu(menuSettings);
        menuMask->setObjectName(QStringLiteral("menuMask"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        sizePolicy.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy);
        statusBar->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(11);
        statusBar->setFont(font2);
        statusBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        statusBar->setLayoutDirection(Qt::RightToLeft);
        statusBar->setStyleSheet(QStringLiteral(""));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConvert->menuAction());
        menuBar->addAction(menuFilter->menuAction());
        menuBar->addAction(menuContrast->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuConvert->addAction(actionRGB_to_RGB);
        menuConvert->addAction(actionRGB_to_YYY);
        menuConvert->addAction(actionRGB_to_YUV);
        menuConvert->addAction(actionRGB_to_YIQ);
        menuConvert->addAction(actionRGB_to_CMY);
        menuConvert->addAction(actionRGB_to_HSV);
        menuConvert->addAction(actionRGB_to_HSL);
        menuConvert->addAction(actionRGB_to_XYZ);
        menuConvert->addAction(actionRGB_to_O1O2O3);
        menuConvert->addAction(actionConvert_to_YYY);
        menuFilter->addAction(actionSettings);
        menuContrast->addAction(actionNormalizeHistograma);
        menuContrast->addAction(actionDemo);
        menuSettings->addAction(actionNew_Convertion);
        menuSettings->addAction(menuMask->menuAction());
        menuSettings->addAction(actionConfusion_table);
        menuSettings->addSeparator();
        menuSettings->addAction(actionSave_Step);
        menuSettings->addAction(actionShow_Step);
        menuMask->addAction(actionNew);
        menuMask->addAction(actionSave_2);
        menuMask->addSeparator();
        menuMask->addAction(actionLoad);
        menuMask->addAction(actionApply);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), threshold, SLOT(setValue(int)));
        QObject::connect(sliderSigma, SIGNAL(valueChanged(int)), numberSigma, SLOT(setValue(int)));
        QObject::connect(threshold, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(numberSigma, SIGNAL(valueChanged(int)), sliderSigma, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(6);
        btnAverage->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Convertidor Imagenes", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionRGB_to_RGB->setText(QApplication::translate("MainWindow", "RGB to RGB", 0));
        actionRGB_to_YUV->setText(QApplication::translate("MainWindow", "RGB to YUV", 0));
        actionRGB_to_CMY->setText(QApplication::translate("MainWindow", "RGB to CMY", 0));
        actionRGB_to_HSV->setText(QApplication::translate("MainWindow", "RGB to HSV", 0));
        actionRGB_to_HSL->setText(QApplication::translate("MainWindow", "RGB to HSI", 0));
        actionRGB_to_XYZ->setText(QApplication::translate("MainWindow", "RGB to XYZ", 0));
        actionRGB_to_YIQ->setText(QApplication::translate("MainWindow", "RGB to YIQ", 0));
        actionRGB_to_O1O2O3->setText(QApplication::translate("MainWindow", "RGB to O1O2O3", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionRGB_to_YYY->setText(QApplication::translate("MainWindow", "RGB to YYY", 0));
        actionNormalizeHistograma->setText(QApplication::translate("MainWindow", "Normalize", 0));
        actionDemo->setText(QApplication::translate("MainWindow", "demo", 0));
        actionConvert_to_YYY->setText(QApplication::translate("MainWindow", "Convert to YYY", 0));
        actionNew_Convertion->setText(QApplication::translate("MainWindow", "New Convertion", 0));
        actionNew_Convertion->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionConfusion_table->setText(QApplication::translate("MainWindow", "Confusion Table", 0));
        actionConfusion_table->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0));
        actionSave_Step->setText(QApplication::translate("MainWindow", "Save Step", 0));
        actionSave_Step->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionShow_Step->setText(QApplication::translate("MainWindow", "Show Step", 0));
        actionShow_Step->setShortcut(QApplication::translate("MainWindow", "F2", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionApply->setText(QApplication::translate("MainWindow", "Apply", 0));
        actionNew->setText(QApplication::translate("MainWindow", "Create", 0));
        actionSave_2->setText(QApplication::translate("MainWindow", "Save", 0));
        actionChannel1->setText(QApplication::translate("MainWindow", "Channel1", 0));
        actionChannel1->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", 0));
#ifndef QT_NO_TOOLTIP
        btn_origin->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_origin->setText(QApplication::translate("MainWindow", "ORIGIN", 0));
#ifndef QT_NO_TOOLTIP
        btn_transform->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btn_transform->setText(QApplication::translate("MainWindow", "TRANSFORM", 0));
        before->setText(QString());
        btn_one->setText(QApplication::translate("MainWindow", "CHANNEL ONE", 0));
        r->setText(QString());
        btn_two->setText(QApplication::translate("MainWindow", "CHANNEL TWO", 0));
        g->setText(QString());
        btn_three->setText(QApplication::translate("MainWindow", "CHANNEL THREE", 0));
        b->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(convert), QApplication::translate("MainWindow", "Convert", 0));
        label_6->setText(QApplication::translate("MainWindow", "Size of Kernel", 0));
        kernelMinMedMax->clear();
        kernelMinMedMax->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select", 0)
         << QApplication::translate("MainWindow", "3x3", 0)
         << QApplication::translate("MainWindow", "5x5", 0)
         << QApplication::translate("MainWindow", "7x7", 0)
         << QApplication::translate("MainWindow", "9x9", 0)
        );
        btnAverage->setText(QApplication::translate("MainWindow", "Average", 0));
        btnGaussiano->setText(QApplication::translate("MainWindow", "Gaussiano", 0));
        btnMinimum->setText(QApplication::translate("MainWindow", "Minimum", 0));
        btnMedium->setText(QApplication::translate("MainWindow", "Medium", 0));
        btnMaximum->setText(QApplication::translate("MainWindow", "Maximum", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Sigma", 0));
        label_4->setText(QString());
        btnSigma->setText(QApplication::translate("MainWindow", "Guardar", 0));
        btnNagao->setText(QApplication::translate("MainWindow", "Nagao", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Low pass", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Edge Detection", 0));
        label_3->setText(QApplication::translate("MainWindow", "Threshold Manual", 0));
        label_5->setText(QApplication::translate("MainWindow", "Threshold Auto", 0));
        btnThreshold->setText(QApplication::translate("MainWindow", "Calculate Otsu", 0));
        groupBox_4->setTitle(QString());
        white->setText(QApplication::translate("MainWindow", "Black", 0));
        black->setText(QApplication::translate("MainWindow", "White", 0));
        btnRobert->setText(QApplication::translate("MainWindow", "Roberts", 0));
        btnPrewitt->setText(QApplication::translate("MainWindow", "Prewitt", 0));
        btnSobel->setText(QApplication::translate("MainWindow", "Sobel", 0));
        btnEdgeDetection->setText(QApplication::translate("MainWindow", "Guardar", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "High pass", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Filters", 0));
        btn_histograma->setText(QApplication::translate("MainWindow", "Histograma", 0));
        selectChannelHistograma->clear();
        selectChannelHistograma->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select Channel", 0)
         << QApplication::translate("MainWindow", "Channel One", 0)
         << QApplication::translate("MainWindow", "Channel Two", 0)
         << QApplication::translate("MainWindow", "Channel Three", 0)
        );
        equalizarHistograma->setText(QApplication::translate("MainWindow", "Equalizer Histograma", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Elementary operations", 0));
        label->setText(QApplication::translate("MainWindow", "Gamma", 0));
        btnGamma->setStyleSheet(QApplication::translate("MainWindow", "QPushButton\n"
"{\n"
"border: 1px solid #F05542;\n"
"}\n"
"QPushButton:hover:!pressed\n"
"{\n"
"  border: 1px solid #F6863A;\n"
"}", 0));
        btnGamma->setText(QApplication::translate("MainWindow", "Guardar", 0));
        label_2->setText(QApplication::translate("MainWindow", "Input const", 0));
        btnSubstract->setText(QApplication::translate("MainWindow", "Const", 0));
        btnPlus->setText(QApplication::translate("MainWindow", "Const", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Histograma", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Structure", 0));
        sizeEstruc->clear();
        sizeEstruc->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select", 0)
         << QApplication::translate("MainWindow", "3x3", 0)
         << QApplication::translate("MainWindow", "5x5", 0)
        );
        optionsEstruc->clear();
        optionsEstruc->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select", 0)
         << QApplication::translate("MainWindow", "option 1", 0)
         << QApplication::translate("MainWindow", "option 2", 0)
         << QApplication::translate("MainWindow", "option 3", 0)
         << QApplication::translate("MainWindow", "option 4", 0)
         << QApplication::translate("MainWindow", "option 5", 0)
         << QApplication::translate("MainWindow", "option 6", 0)
         << QApplication::translate("MainWindow", "option 7", 0)
         << QApplication::translate("MainWindow", "option 8", 0)
         << QApplication::translate("MainWindow", "option 9", 0)
         << QApplication::translate("MainWindow", "option 10", 0)
         << QApplication::translate("MainWindow", "option 11", 0)
         << QApplication::translate("MainWindow", "option 12", 0)
        );
        btnLeft->setText(QApplication::translate("MainWindow", "<", 0));
        btnRight->setText(QApplication::translate("MainWindow", ">", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Operations", 0));
        btnDilation->setText(QApplication::translate("MainWindow", " Dilation", 0));
        btnErosion->setText(QApplication::translate("MainWindow", " Erosion", 0));
        btnOpening->setText(QApplication::translate("MainWindow", " Opening", 0));
        btnClosing->setText(QApplication::translate("MainWindow", " Closing", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Morphologics OP", 0));
        origin->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuConvert->setTitle(QApplication::translate("MainWindow", "Convert", 0));
        menuFilter->setTitle(QApplication::translate("MainWindow", "Filter", 0));
        menuContrast->setTitle(QApplication::translate("MainWindow", "Histogram", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuMask->setTitle(QApplication::translate("MainWindow", "Mask", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
