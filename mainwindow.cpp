#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsfilter.h"
#include "ui_settingsfilter.h"
#include "convertImage.h"
#include "filter.h"
#include "histograma.h"
#include "AuxFunctions.h"
#include "threshold.h"
#include "morphological.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    ui->histograma->hide();
    ui->structure->hide();


    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Función para cargar la imagen
void MainWindow::on_actionOpen_triggered()
{
   QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.png *.jpg *.bmp)"));

   origin.load(file);

   if(origin.width() >= 3000)
   {
       image = origin.scaled(resizeImage(origin.width(),origin.height()),Qt::KeepAspectRatio,Qt::SmoothTransformation);
   }
   else
   {
       image = origin;
   }

   // convertir la imagen a formato rgb 8 bits;
   //image = image.convertToFormat(QImage::Format_RGB888);
   /************************************/
   //imageLabel = image;
   /************************************/
   if (!file.isEmpty())
   {
       if (!origin.load(file))
       {
           QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
           return;
       }       
    }

    ui->after->setPixmap(QPixmap::fromImage(image));
    ui->origin->setPixmap(QPixmap::fromImage(image));

    // Funcion que limpia los label cada vez que se abre una nueva imagen
    clear_Label_Miniature_Image();

    //qDebug()<<image.isGrayscale();

    // almaceno el tamaño de la imagen en una variable global para poder usarla en el algoritmo de otsu
    sizeImage = image.width() * image.height();
}
// Función para guardar la imagen transformada
void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "", tr("Images (*.png)"));

    if (!fileName.isEmpty())
    {
        if (!image.save(fileName))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        imageT.save(fileName);
    }
}

/*-----------------------------------------------------------------------------------------------------------/*
 * Metodos que llaman a las funciones de convercion de formatos RGB -> RGB, YUV, YIQ, CMY, HSV, HSL, XYZ, O1O2O3
 *-----------------------------------------------------------------------------------------------------------*/
void MainWindow::on_actionRGB_to_RGB_triggered()
{
    convert_Image_To_Space_Color("Red","Green","Blue",0);
}
void MainWindow::on_actionRGB_to_YYY_triggered()
{
   convert_Image_To_Space_Color("Y","Y","Y",1);
}
void MainWindow::on_actionRGB_to_YUV_triggered()
{
    convert_Image_To_Space_Color("Y","U","V",2);
}
void MainWindow::on_actionRGB_to_YIQ_triggered()
{
    convert_Image_To_Space_Color("Y","I","Q",3);
}
void MainWindow::on_actionRGB_to_CMY_triggered()
{
    convert_Image_To_Space_Color("Cyan","Magenta","Yellow",4);
}
void MainWindow::on_actionRGB_to_HSV_triggered()
{
    convert_Image_To_Space_Color("Hue","Saturation","Value",5);
}
void MainWindow::on_actionRGB_to_HSL_triggered()
{
    convert_Image_To_Space_Color("Hue","Saturation","Ligntness",6);
}
void MainWindow::on_actionRGB_to_XYZ_triggered()
{
    convert_Image_To_Space_Color("X","Y","Z",7);
}
void MainWindow::on_actionRGB_to_O1O2O3_triggered()
{
    convert_Image_To_Space_Color("O1","O2","O3",8);
}
/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------/*
 * Muestro la imagen en el label origin (label principal) cada vez que se da clic al btn de la miniatura
 *-----------------------------------------------------------------------------------------------------------*/
void MainWindow::on_btn_origin_clicked()
{    
    ui->origin->setPixmap(QPixmap::fromImage(image));
    show_Label_Image_Hide_Histograma(0);    
}
void MainWindow::on_btn_transform_clicked()
{    
    show_Image_In_Label(imageT, 0);
}
void MainWindow::on_btn_one_clicked()
{
    show_Image_In_Label(imageR, 1);
}
void MainWindow::on_btn_two_clicked()
{
    show_Image_In_Label(imageG, 2);
}
void MainWindow::on_btn_three_clicked()
{
    show_Image_In_Label(imageB, 3);
}
/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------/*
 * Ventana del menu Filter
 *-----------------------------------------------------------------------------------------------------------*/
//  Crea y muestra la ventana de configuracion de filtros
void MainWindow::on_actionSettings_triggered()
{
    SettingsFilter *averange = new SettingsFilter(this);
    averange->setModal(true);
    averange->show();
}
// Funcion que muestra los valores de los kernel para el filtro promedio o gaussiano
void SettingsFilter::on_filterByDefault_currentIndexChanged(int index)
{
    // Filtro Promedio
    if(index == 1)
    {
        // Desplegar las casillas vacias correspondientes al tamaño del filtro en pantalla
        on_selectFilter_currentIndexChanged(1);
        // Insertar los valores que trae el filtro por defecto
        show_value_kernel(listAverage, 1);
        // Muestra los input desahabilitados
        enable_Input();
    }
    // Filtro Gaussiano
    if(index == 2)
    {
        on_selectFilter_currentIndexChanged(1);
        show_value_kernel(listGaussiano, 1);
        enable_Input();
    }
}
// Funcion que lee un filtro de un archivo txt, el filtro puede contener un kernel de 3x3, 5x5, 7x7 y 9x9
void SettingsFilter::on_btnLoad_clicked()
{
    QString text;
    QString filter;
    QStringList lists;    

    // cargo el txt con el filtro
    QFile file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.txt)"));
    enable_Input();
    file.open(QIODevice::ReadOnly);

    QTextStream result(&file);

    text = result.readAll();

    // Limpiar el string
    QStringList list = text.split("\r\n");

    // almaceno el nombre del filtro
    filter = list[0];

    for(int i = 1; i < list.length(); i++)
    {
        lists.append(list[i].split(' '));
    }

    if (lists.length() == 9)
    {
        on_selectFilter_currentIndexChanged(1);
        show_value_kernel(lists, 1);
    }
    if (lists.length() == 25)
    {
        on_selectFilter_currentIndexChanged(2);
        show_value_kernel(lists, 2);
    }
    if (lists.length() == 49)
    {
        on_selectFilter_currentIndexChanged(3);
        show_value_kernel(lists, 3);
    }
    if (lists.length() == 81)
    {
        on_selectFilter_currentIndexChanged(4);
        show_value_kernel(lists, 4);
    }


    if(filter == "average")listAverage = lists;
    if(filter == "gaussiano")listGaussiano = lists;
    if(filter != "average" || filter != "gaussiano")
    {
        QMessageBox::critical(this, tr("Error"), tr("Invalid filter"));
        return;
    }

    ui->loaded->show();

    qDebug()<<"CARGO FILTRO";

    file.close();

}

/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------/*
 * Filtros configurados como botones
 *-----------------------------------------------------------------------------------------------------------*/

/******************** Paso bajo ********************/

void MainWindow::on_btnAverage_clicked()
{    
    createMatriz(listAverage);    
    *imageLabel = filterAverageAndGaussiano(*imageLabel, sqrt(listAverage.length()), "average");
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));    
    render_Miniature_Image();
}
void MainWindow::on_btnGaussiano_clicked()
{
    createMatriz(listGaussiano);
    *imageLabel = filterAverageAndGaussiano(*imageLabel, sqrt(listGaussiano.length()), "gaussiano");
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    render_Miniature_Image();
}
void MainWindow::on_btnMinimum_clicked()
{
    *imageLabel = filterMinMedMax(*imageLabel, 0);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    render_Miniature_Image();
}
void MainWindow::on_btnMedium_clicked()
{
    *imageLabel = filterMinMedMax(*imageLabel, 1);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    render_Miniature_Image();
}
void MainWindow::on_btnMaximum_clicked()
{
    *imageLabel = filterMinMedMax(*imageLabel, 2);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    render_Miniature_Image();
}
// Retorna el numero sigma que ingresa el usuario
int MainWindow::sigma()
{
    return ui->numberSigma->value();
}
void MainWindow::on_sliderSigma_sliderReleased()
{
    numberSigma = sigma();    
    ui->origin->setPixmap(QPixmap::fromImage(filterSigma(*imageLabel,numberSigma)));
}
// guardar los cambios de la imagen cuando se escoja un sigma satisfactorio, es decir
// no se sobreescribe los cambios cada vez que se cambia el sigma, sino que estos se
// aplican a la imagen original
void MainWindow::on_btnSigma_clicked()
{
    numberSigma = sigma();
    *imageLabel = filterSigma(*imageLabel,numberSigma);
    render_Miniature_Image();
}
void MainWindow::on_btnNagao_clicked()
{
    *imageLabel = filterNagao(*imageLabel);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    render_Miniature_Image();
}

/*********************** Fin ***********************/

/******************** Paso alto ********************/

// Metodo que retorna el valor del threshold del spin box seleccionado por el usuario
int MainWindow::threshold()
{
    return ui->threshold->value();
}
// calcula el threshold con el algoritmo de otsu o isodata
// dependienda de la opcion del radio button que halla escogido el usuario
void MainWindow::on_btnThreshold_clicked()
{
    int threshold = 0;

    switch(channel)
    {
        case 0: threshold = thresholdOtsu(histogramaT, sizeImage);
        break;
        case 1: threshold = thresholdOtsu(histogramaR, sizeImage);
        break;
        case 2: threshold = thresholdOtsu(histogramaG, sizeImage);
        break;
        case 3: threshold = thresholdOtsu(histogramaB, sizeImage);
        break;
        default: qDebug()<<"Error threshold";
    }

    ui->threshold->setValue(threshold);
    ui->horizontalSlider->setValue(threshold);    
}
// Metodo que retorna true o false si el fondo es blanco o negro
bool MainWindow::background()
{
    return ui->white->isChecked() ? true : false;
}
void MainWindow::on_btnSobel_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(filterEdgeDetection(*imageLabel,sobelX,sobelY,3,threshold(), background())));
    edgeDetection = "Sobel";
}
void MainWindow::on_btnRobert_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(filterEdgeDetection(*imageLabel,robertX,robertY,2,threshold(), background())));
    edgeDetection = "Robert";
}
void MainWindow::on_btnPrewitt_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(filterEdgeDetection(*imageLabel,prewittX,prewittY,3,threshold(), background())));
    edgeDetection = "Prewitt";
}
// Guardo los cambios de la imagen al aplicar Sobel, Robert o Prewitt
void MainWindow::on_btnEdgeDetection_clicked()
{
    bool grayscale = imageT.isGrayscale();

    if(edgeDetection == "Sobel")
    {
        *imageLabel = filterEdgeDetection(*imageLabel, sobelX, sobelY, 3, threshold(), background());
        render_Miniature_Image(!grayscale);
    }
    if(edgeDetection == "Robert")
    {
        *imageLabel = filterEdgeDetection(*imageLabel, robertX, robertY, 2, threshold(), background());
        render_Miniature_Image(!grayscale);
    }
    if(edgeDetection == "Prewitt")
    {
        *imageLabel = filterEdgeDetection(*imageLabel, prewittX, prewittY, 3, threshold(), background());
        render_Miniature_Image(!grayscale);
    }
}

/*********************** Fin ***********************/

/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------/*
 * Histograma
 *-----------------------------------------------------------------------------------------------------------*/
// Metodo que almacena en una variable global el indice del combo box el cual me indica
// que canal RGB quiero que cree el histograma y lo renderize en una miniatura
void MainWindow::on_selectChannelHistograma_activated(int index)
{
    switch(index)
    {
        case 0: imageLabel = &imageT;
        break;
        case 1: imageLabel = &imageR;
        break;
        case 2: imageLabel = &imageG;
        break;
        case 3: imageLabel = &imageB;
        break;
        default: qDebug()<<"No hay imagen";
    }

    channel = index;
    render_Histograma_Min_Or_Max(false,index);
    render_Histograma_Min_Or_Max(true,index);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
}
// Metodo que renderiza el histograma en su tamaño maximo al ser clickeado el btn
void MainWindow::on_btn_histograma_clicked()
{
    ui->origin->hide();
    ui->histograma->show();
    render_Histograma_Min_Or_Max(true,channel);
}
// Metodo que normaliza el histograma en valores de 0 a 1
void MainWindow::on_actionNormalizeHistograma_triggered()
{
    normalizeHistograma();
    render_Histograma_Min_Or_Max(true,channel);
}
// Metodo que ecualiza el histograma de la imagen dependiendo del valor almacenado
// en la variable global selectChannelHistograma
void MainWindow::on_equalizarHistograma_clicked()
{    
    //cuidado con selectChannelHistograma ya que desde ahi lo controlo desde el combo box, cambiar esto por channel
    *imageLabel = equalization_Histograma(*imageLabel, channel);
    // limpiar los valores del array histograma para cada canal para evitar que se sobreescriba
    setearHistograma(channel);
    // crear histograma equalizado
    createHistograma(*imageLabel,channel);
    // Renderizar el histograma tanto maximo como minimo
    render_Histograma_Min_Or_Max(true,channel);
    render_Histograma_Min_Or_Max(false,channel);
    // Renderizar la imagen si el histograma cambia, este efecto sucede si el label esta activo -> show()
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    // renderizar imagenes en miniatura
    render_Miniature_Image();
}

/*************** Operaciones con histogramas ***************/

// Funcion que captura el valor del spin box cuando cambia
void MainWindow::on_const_2_valueChanged(double arg1)
{
    constOperationHistograma = arg1;
    ui->gamma->setValue((ui->const_2->value())/0.001);
}
// Funcion que aplica a la imagen el valor gamma del slider seleccionado automaticamente
void MainWindow::on_gamma_sliderReleased()
{
    QImage gamma = gammaConstImage(*imageLabel,constOperationHistograma);
    // setear los valores del histograma en 0 dependiendo del canal
    qDebug()<<channel;
    setearHistograma(channel);
    createHistograma(gamma,channel);
    render_Histograma_Min_Or_Max(true,channel);
    render_Histograma_Min_Or_Max(false,channel);
    ui->origin->setPixmap(QPixmap::fromImage(gamma));
}
// Funcion que setea en el spinbox el valor del slider que corresponde al numero gamma
void MainWindow::on_gamma_sliderMoved(int position)
{
    ui->const_2->setValue(position*0.001);
}
// Guarda los cambios aplicados a la imagen sobre el gamma
void MainWindow::on_btnGamma_clicked()
{
    *imageLabel = gammaConstImage(*imageLabel,constOperationHistograma);
    render_Miniature_Image();
}
// Funcion que suma una constante al histograma
void MainWindow::on_btnPlus_clicked()
{   
    *imageLabel = sumConstImage(*imageLabel,constOperationHistograma,channel);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    createHistograma(*imageLabel,channel);
    render_Histograma_Min_Or_Max(true,channel);
    render_Histograma_Min_Or_Max(false,channel);
    render_Miniature_Image();
}
// Funcion que resta una constante al histograma
void MainWindow::on_btnSubstract_clicked()
{
    *imageLabel = susbtractConstImage(*imageLabel,constOperationHistograma,channel);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    createHistograma(*imageLabel,channel);
    render_Histograma_Min_Or_Max(true,channel);
    render_Histograma_Min_Or_Max(false,channel);
    render_Miniature_Image();
}

/********************** Fin **********************/

/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------/*
 * Operaciones morfologicas
 *-----------------------------------------------------------------------------------------------------------*/
void MainWindow::on_sizeEstruc_currentIndexChanged(int index)
{
    //Ocultar las celdas dependiendo del tamaño de kernel que escoja 3x3 5x5
    show_hide_Input_Morphologic(index);
}
void MainWindow::on_optionsEstruc_currentIndexChanged(int index)
{
    if(ui->sizeEstruc->currentIndex() == 1 && index > 0)
    {
       // selecciono la estructura de un array y la convierto a una lista
       QStringList listStructure = arrayStructure[index-1].split(' ');
       // Funcion que muestra en pantalla los datos de la estructura
       show_Structure(listStructure);
       // Funcion que rellena una matriz con los valores de la estructura
       createMatrizStructure(listStructure);
       // Activo el btnDilation
       ui->btnDilation->setEnabled(true);
       ui->btnErosion->setEnabled(true);
       ui->btnOpening->setEnabled(true);
       ui->btnClosing->setEnabled(true);
    }
}

/*************** Operaciones Morfologicas ***************/

void MainWindow::on_btnDilation_clicked()
{    
    morphologic = 0;
    ui->origin->setPixmap(QPixmap::fromImage(dilationOrErosion(*imageLabel,true)));
}
void MainWindow::on_btnErosion_clicked()
{
    morphologic = 1;
    ui->origin->setPixmap(QPixmap::fromImage(dilationOrErosion(*imageLabel,false)));
}
void MainWindow::on_btnOpening_clicked()
{
    morphologic = 2;
    QImage opening = dilationOrErosion(*imageLabel,false);
    ui->origin->setPixmap(QPixmap::fromImage(dilationOrErosion(opening,true)));
}
void MainWindow::on_btnClosing_clicked()
{
    morphologic = 3;
    QImage closing = dilationOrErosion(*imageLabel,true);
    ui->origin->setPixmap(QPixmap::fromImage(dilationOrErosion(closing,false)));
}
// Funcion que guarda la imagen dependiendo de la operacion morfologica aplicada
void MainWindow::on_btnMorphologic_clicked()
{
    switch(morphologic)
    {
        case 0: *imageLabel = dilationOrErosion(*imageLabel,true);
        break;
        case 1: *imageLabel = dilationOrErosion(*imageLabel,false);
        break;
        case 2:
        {
            *imageLabel = dilationOrErosion(*imageLabel,false);
            *imageLabel = dilationOrErosion(*imageLabel,true);
        }
        break;
        case 3:
        {
            *imageLabel = dilationOrErosion(*imageLabel,true);
            *imageLabel = dilationOrErosion(*imageLabel,false);
        }
        break;
        default: qDebug()<<"No se puede guardar la operacion morfologica";
    }
    render_Miniature_Image();
}

/********************** Fin **********************/

/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/
