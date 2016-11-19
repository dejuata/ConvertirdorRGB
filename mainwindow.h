#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QPixmap>
#include <QColor>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QGraphicsScene>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QGraphicsView>
#include <QFuture>
#include <QtConcurrent>
#include <QtWidgets>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QImage origin;
    QImage image;
    QImage imageT;
    QImage imageR;
    QImage imageG;
    QImage imageB;
    QImage *imageLabel;

    QString channelR;
    QString channelG;
    QString channelB;
    QString channel;
    QString edgeDetection;

    QChart *chart;
    QGraphicsScene *scene;

    QFuture<QImage> futureT;
    QFuture<QImage> futureR;
    QFuture<QImage> futureG;
    QFuture<QImage> futureB;



    void show_histograma();//que es esto verificar si puedo eliminarlo

    void render_Histograma(bool maximum,  QColor color, QString channel, int spaceColor);


    Ui::MainWindow *ui;

private slots:

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void convert_Image_To_Space_Color(QString r, QString g, QString b, int spaceColor);

    void select_Space_Colors_Convert(int index);

    void on_actionRGB_to_RGB_triggered();

    void on_actionRGB_to_YUV_triggered();

    void on_actionRGB_to_CMY_triggered();

    void on_actionRGB_to_HSV_triggered();

    void on_btn_origin_clicked();

    void on_btn_transform_clicked();

    void on_btn_one_clicked();

    void on_btn_two_clicked();

    void on_btn_three_clicked();

    void on_actionRGB_to_HSL_triggered();

    void on_actionRGB_to_XYZ_triggered();

    void on_actionRGB_to_YIQ_triggered();

    void on_actionRGB_to_O1O2O3_triggered();    

    void on_actionTransform_triggered();

    void on_actionChannel_One_triggered();

    void on_actionChannel_Two_triggered();

    void on_actionChannel_Three_triggered();

    void on_actionSettings_triggered();

    void on_btn_histograma_clicked();

    void on_selectChannelHistograma_currentIndexChanged(int index);    

    void on_equalizarHistograma_clicked();

    void on_actionRGB_to_YYY_triggered();

    void on_btnAverage_clicked();

    void on_btnGaussiano_clicked();

    void on_btnMinimum_clicked();

    void on_btnMedium_clicked();

    void on_btnMaximum_clicked();    

    void on_btnNagao_clicked();

    void on_btnPlus_clicked();

    void on_btnSubstract_clicked();    

    void on_const_2_valueChanged(double arg1);

    void on_btnSobel_clicked();

    void on_btnRobert_clicked();

    void on_btnPrewitt_clicked();

    void on_gamma_sliderMoved(int position);

    void on_gamma_sliderReleased();

    void on_horizontalSlider_sliderReleased();

    void on_sliderSigma_sliderReleased();

    void on_btnThreshold_clicked();

    void on_btnDilation_clicked();

    void on_sizeEstruc_currentIndexChanged(int index);

    void on_optionsEstruc_currentIndexChanged(int index);

    void on_btnErosion_clicked();



    void on_btnOpening_clicked();

    void on_btnClosing_clicked();

    void on_btnSigma_clicked();

    void on_btnEdgeDetection_clicked();

    void on_actionNormalizeHistograma_triggered();

private:

    void clear_Label_Miniature_Image();

    void render_Miniature_Image(bool NoGrayscale = true);

    void show_Text_UI(QString r, QString g, QString b);

    void action_Filter_Select(QImage image);

    int create_Histograma(QImage image, int channel, bool maximum);

    void show_Label_Image_Hide_Histograma(int index);

    void show_Image_In_Label(QImage &image,int channel);

    void render_Histograma_Min_Or_Max(bool maximum, int spaceColor);

    QImage equalization_Histograma(QImage image, int channel);

    // metodo que me retorna el valor del threshold
    int threshold();
    // obtener el numero sigma
    int sigma();
    // devuelve true o false si el fondo es blanco o negro
    bool background();

    //Funcion para mostrar los QInput de las operaciones morfologicas
    // dependiendo del tamaño que seleccione el usuario 3x3 5x5
    void show_hide_Input_Morphologic(int index);

    //Muestra las diferentes estructuras en los inputs
    void show_Structure(QStringList lists);

    void clean_Input();

};







#endif // MAINWINDOW_H
