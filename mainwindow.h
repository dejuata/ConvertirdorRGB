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
#include <QMovie>
#include "progress.h"
//#include "ui_progress.h"

#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

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

    // Almacena las Imagenes a procesar
    QImage origin;    
    QImage image; // imagen original
    QImage imageT;// imagen en el canal RGB
    QImage imageR;// imagen solo en el canal R
    QImage imageG;// imagen solo en el canal G
    QImage imageB;// imagen solo en el canal B
    QImage *imageLabel;// puntero que puede contener la direccion de las imagenes anteriores

    // Almacena los resultados de la conversion de imagenes que se realiza asincronicamente
    // estas variables se setean en las variable QImage normal, esto es necesario por el
    // modulo Qtconcurrent
    QFuture<QImage> futureT;
    QFuture<QImage> futureR;
    QFuture<QImage> futureG;
    QFuture<QImage> futureB;

    // Almacena los nombres de los canales cuando la imagen es convertida a un espacio de color
    QString channelR;
    QString channelG;
    QString channelB;

    // Almacena que filtro se aplica a la imagen para mostrarlo en la statusBar
    QString filter;

    // me permite llevar un control de que imagen quiero que
    // se guarde cuando sea procesado por sobel, robert o prewitt
    QString edgeDetection;

    // Guarda que canal estoy procesando para pasarselo a las diferentes funciones
    // 0 -> T, 1 -> R, 2 -> G, 3 -> B
    int channel = 0;
    // Guarda la operacion morfologica que he aplicado
    // 0 -> Dilation, 1 -> Erosion, 2 -> opening, 3-> closing
    int morphologic = 0;
    // Almacena el tamaño de la imagen
    int sizeImage;
    // Almacena el valor de una constante, la cual es utilizada para aplicarla
    // en la funcion de substraer o sumar en la pestaña de histograma
    int constOperationHistograma;

    // puntero que almacena el grafico de QtCharts
    QChart *chart;
    // puntero que almacena la escena para poder renderizar el grafico de QtCharts
    QGraphicsScene *scene;

    QMovie *movie = new QMovie(":/img/loading.gif");
    QLabel *statusLabel;

    Ui::MainWindow *ui;

private slots:

    // Load y Save
    void on_actionOpen_triggered();
    void on_actionSave_triggered();

    // Converir de RGB to RGB, YYY, YUV, YIQ, CMY, HSV, HSL, XYZ, O1O2O3
    void convert_Image_To_Space_Color(QString r, QString g, QString b, int spaceColor);
    void select_Space_Colors_Convert(int index);

    void on_actionRGB_to_RGB_triggered();
    void on_actionRGB_to_YYY_triggered();
    void on_actionRGB_to_YUV_triggered();
    void on_actionRGB_to_YIQ_triggered();
    void on_actionRGB_to_CMY_triggered();
    void on_actionRGB_to_HSV_triggered();
    void on_actionRGB_to_HSL_triggered();
    void on_actionRGB_to_XYZ_triggered();
    void on_actionRGB_to_O1O2O3_triggered();

    // Renderizar las imagenes convertidas en el label principal
    void on_btn_origin_clicked();
    void on_btn_transform_clicked();
    void on_btn_one_clicked();
    void on_btn_two_clicked();
    void on_btn_three_clicked();


    // Crea y muestra la ventana de configuracion de filtros
    void on_actionSettings_triggered();

    // Filtros de paso bajo
    // funcion que retorna el tamaño del kernel para trabajar con
    // con los filtros Average, Gaussiano, Minimum, Medium, Maximum
    int sizeKernel();
    void on_kernelMinMedMax_currentIndexChanged(int index);
    void on_btnAverage_clicked();
    void on_btnGaussiano_clicked();    
    void on_btnMinimum_clicked();
    void on_btnMedium_clicked();
    void on_btnMaximum_clicked();
    void on_btnNagao_clicked();
    int sigma(); // Retorna el numero sigma
    void on_sliderSigma_sliderReleased(); // Aplica la funcion sigma cada vez que se mueve el slider
    void on_btnSigma_clicked();

    // Filtros de paso alto
    int threshold(); // Retorna el valor del threshold    
    void on_btnThreshold_clicked();
    bool background(); // Retorna true o false si el fondo es blanco o negro
    void on_btnSobel_clicked();
    void on_btnRobert_clicked();
    void on_btnPrewitt_clicked();
    void on_btnEdgeDetection_clicked(); // Almacena la imagen con el filtro aplicado

    // Histograma
    void on_selectChannelHistograma_activated(int index);
    void on_btn_histograma_clicked();
    void on_actionNormalizeHistograma_triggered();
    void on_equalizarHistograma_clicked();

    // Operaciones con histograma
    void on_const_2_valueChanged(double arg1);
    void on_gamma_sliderReleased();
    void on_gamma_sliderMoved(int position);
    void on_btnGamma_clicked();
    void on_btnPlus_clicked();
    void on_btnSubstract_clicked();    

    // Kernel para las operaciones morfologicas
    void on_sizeEstruc_currentIndexChanged(int index);
    void on_optionsEstruc_currentIndexChanged(int index);
    void on_btnLeft_clicked();
    void on_btnRight_clicked();

    // Operaciones morfologicas
    int sizeKernelOperatiosMorphologics();
    void on_btnDilation_clicked();
    void on_btnErosion_clicked();
    void on_btnOpening_clicked();
    void on_btnClosing_clicked();
//    void on_btnMorphologic_clicked();

    void on_actionDemo_triggered();

    void on_actionConvert_to_YYY_triggered();

    void on_actionNew_Convertion_triggered();

    void enable_BtnImage(bool enable = true);

private:

    void clear_Label_Miniature_Image();

    void render_Miniature_Image(bool NoGrayscale = true);

    void show_Text_UI(QString r, QString g, QString b);

    void action_Filter_Select(QImage image);

    int create_Histograma(QImage image, int channel, bool maximum);

    void show_Label_Image_Hide_Histograma(int index);

    void show_Image_In_Label(QImage &image, int index);

    void render_Histograma_Min_Or_Max(bool maximum, int spaceColor);

    QImage equalization_Histograma(QImage image, int channel);

    void render_Histograma(bool maximum,  QColor color, QString channel, int spaceColor);

    //Funcion para mostrar los QInput de las operaciones morfologicas
    // dependiendo del tamaño que seleccione el usuario 3x3 5x5
    void show_hide_Input_Morphologic(int index);

    //Muestra las diferentes estructuras en los inputs
    void show_Structure(QStringList lists);

    void clean_Input();


    // Funcion que retorna una mensaje
    QString MainWindow::stateMessage(int index);

    void show_Message_Status_Bar(int index);

    void show_Window_Message();

    // retroalimentacion
    void MainWindow::messageBoxGrayscale(QString option);

};






#endif // MAINWINDOW_H
