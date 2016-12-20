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
#include "segmentation.h"
#include "progress.h"
#include "ui_progress.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    ui->histograma->hide();
    ui->structure->hide();    
    createShorcuts();
    this->setWindowState(Qt::WindowMaximized);     
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Función para cargar la imagen
void MainWindow::on_actionOpen_triggered()
{

    // Show Message status bar Opening...
    show_Message_Status_Bar(0);
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.png *.jpg *.bmp *.tif *.gif)"));

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

    // Show Message status bar Loaded
    show_Message_Status_Bar(1);

    // Funcion que limpia los label cada vez que se abre una nueva imagen
    clear_Label_Miniature_Image();

    //qDebug()<<image.isGrayscale();

    // almaceno el tamaño de la imagen en una variable global para poder usarla en el algoritmo de otsu
    sizeImage = image.width() * image.height();

    //mostrar especificamente las imagenes de retina
//    if(sizeImage == (565*584))
//    {
//        ui->origin->setScaledContents(false);
//    }
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
        QImage saveImage = *imageLabel;
        saveImage.save(fileName);
    }
    // Show Message status bar Save
    show_Message_Status_Bar(2);
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
void MainWindow::on_actionConvert_to_YYY_triggered()
{
    *imageLabel = convertToYYY(*imageLabel);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    // crear el histograma para esa imagen
    run(createHistograma,*imageLabel,channel).result();
    // pintar el histograma
    render_Histograma_Min_Or_Max(true,channel);
    render_Histograma_Min_Or_Max(false,channel);
    // renderizar la miniatura
    render_Miniature_Image();
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
    // Show Message status bar Origin image
    show_Message_Status_Bar(5);
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
void SettingsFilter::on_selectFilter_currentTextChanged(QString arg1)
{
    QString index = ui->filterByDefault->currentText();
    int size = 0;

    if(arg1 == "3 x 3")size = 1;
    if(arg1 == "5 x 5")size = 2;
    if(arg1 == "7 x 7")size = 3;
    if(arg1 == "9 x 9")size = 4;

    if(index == "Average")
    {
        // Creo la lista correspondiente al tamaño seleccionado
        listAverage = sizeKernelAverageOrGaussiano(size,"average");
        // Desplegar las casillas vacias correspondientes al tamaño del filtro en pantalla
        on_selectFilter_currentIndexChanged(size);
        // Insertar los valores que trae el filtro por defecto
        show_value_kernel(listAverage, size);
    }
    if(index == "Gaussiano")
    {
        // Creo la lista correspondiente al tamaño seleccionado
        listGaussiano = sizeKernelAverageOrGaussiano(size,"gaussiano");
        // Desplegar las casillas vacias correspondientes al tamaño del filtro en pantalla
        on_selectFilter_currentIndexChanged(size);
        // Insertar los valores que trae el filtro por defecto
        show_value_kernel(listGaussiano, size);
    }
}
void SettingsFilter::on_filterByDefault_currentIndexChanged(int index)
{
    if(index == 1)
    {
        // Habilitar comboBox
        ui->selectFilter->setEnabled(true);
        // Muestra los input desahabilitados
        enable_Input();
    }
    // Filtro Gaussiano
    if(index == 2)
    {
        // Habilitar comboBox
        ui->selectFilter->setEnabled(true);
        // Muestra los input desahabilitados
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

// Retorna el tamaño del kernel seleccionado del comboBox
int MainWindow::sizeKernel()
{
    int index = ui->kernelMinMedMax->currentIndex();    

    switch(index)
    {
        case 1: return 3;
        break;
        case 2: return 5;
        break;
        case 3: return 7;
        break;
        case 4: return 9;
        break;
        default: return 3;
        break;
    }
}
// Funcion que activa los botones al escoger un kernel
void MainWindow::on_kernelMinMedMax_currentIndexChanged(int index)
{
    if(index != 0)
    {
        ui->btnAverage->setEnabled(true);
        ui->btnGaussiano->setEnabled(true);
        ui->btnMinimum->setEnabled(true);
        ui->btnMedium->setEnabled(true);
        ui->btnMaximum->setEnabled(true);
    }
    if(index == 0)
    {
        ui->btnAverage->setEnabled(false);
        ui->btnGaussiano->setEnabled(false);
        ui->btnMinimum->setEnabled(false);
        ui->btnMedium->setEnabled(false);
        ui->btnMaximum->setEnabled(false);
    }
}
void MainWindow::on_btnAverage_clicked()
{    
    // Show Message status bar Applying filter..
    show_Message_Status_Bar(10);

    int sizeKernel = ui->kernelMinMedMax->currentIndex();    

    listAverage = sizeKernelAverageOrGaussiano(sizeKernel,"average");
    createMatriz(listAverage);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = filterAverageAndGaussiano(*imageLabel,sqrt(listAverage.length()) , "average");
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));    
    render_Miniature_Image();

    // Update histograma
    updateHistograma();

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
void MainWindow::on_btnGaussiano_clicked()
{
    // Show Message status bar Applying filter..
    show_Message_Status_Bar(10);

    int sizeKernel = ui->kernelMinMedMax->currentIndex();

    listGaussiano = sizeKernelAverageOrGaussiano(sizeKernel,"gaussiano");
    createMatriz(listGaussiano);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = filterAverageAndGaussiano(*imageLabel, sqrt(listGaussiano.length()), "gaussiano");
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    // Update histograma
    updateHistograma();

    render_Miniature_Image();
    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
void MainWindow::on_btnMinimum_clicked()
{   
    // Show Message status bar Applying filter..
    show_Message_Status_Bar(10);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = filterMinMedMax(*imageLabel,sizeKernel(),0);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    render_Miniature_Image();

    // Update histograma
    updateHistograma();

    // Show Message status bar Applying Ready!
    show_Message_Status_Bar(4);
}
void MainWindow::on_btnMedium_clicked()
{
    // Show Message status bar Applying filter..
    show_Message_Status_Bar(10);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = filterMinMedMax(*imageLabel,sizeKernel(), 1);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    render_Miniature_Image();

    // Update histograma
    updateHistograma();

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
void MainWindow::on_btnMaximum_clicked()
{
    // Show Message status bar Applying filter..
    show_Message_Status_Bar(10);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = filterMinMedMax(*imageLabel,sizeKernel(), 2);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    render_Miniature_Image();

    // Update histograma
    updateHistograma();

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
// Retorna el numero sigma que ingresa el usuario
int MainWindow::sigma()
{
    return ui->numberSigma->value();
}
void MainWindow::on_sliderSigma_sliderReleased()
{
    // Show Message status bar Applying filter..
    show_Message_Status_Bar(10);
    numberSigma = sigma();    

    ui->origin->setPixmap(QPixmap::fromImage(filterSigma(*imageLabel,numberSigma)));

    // Update histograma
    updateHistograma();

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
// guardar los cambios de la imagen cuando se escoja un sigma satisfactorio, es decir
// no se sobreescribe los cambios cada vez que se cambia el sigma, sino que estos se
// aplican a la imagen original
void MainWindow::on_btnSigma_clicked()
{
    // Show Message status bar Saving..
    show_Message_Status_Bar(11);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    numberSigma = sigma();
    *imageLabel = filterSigma(*imageLabel,numberSigma);

    render_Miniature_Image();

    // Update histograma
    updateHistograma();

    // Show Message status bar Saved..
    show_Message_Status_Bar(12);
}
void MainWindow::on_btnNagao_clicked()
{
    // Show Message status bar Applying filter..
    show_Message_Status_Bar(10);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = filterNagao(*imageLabel);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    render_Miniature_Image();

    // Update histograma
    updateHistograma();

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
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
    // Show Message status bar Calculated..
    show_Message_Status_Bar(13);

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

    render_Histograma_Min_Or_Max(true,channel,threshold);

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
// Metodo que retorna true o false si el fondo es blanco o negro
bool MainWindow::background()
{
    return ui->white->isChecked() ? false : true;
}
void MainWindow::on_btnRobert_clicked()
{
    edgeOperation = 0;

    if(imageLabel->isGrayscale())
    {
        // Show Message status bar Calculated..
        show_Message_Status_Bar(10);

        //Guardar imagen de respaldo antes de que se aplique el filtro
        imageRestore = *imageLabel;

        ui->origin->setPixmap(QPixmap::fromImage(filterEdgeDetection(*imageLabel,robertX,robertY,2,threshold(), background())));
        edgeDetection = "Robert";

        // Show Message status bar Ready!
        show_Message_Status_Bar(4);
    }
    else
    {
        messageBoxGrayscale("grayscale");
    }

}
void MainWindow::on_btnPrewitt_clicked()
{
    edgeOperation = 1;

    if(imageLabel->isGrayscale())
    {
        // Show Message status bar Calculated..
        show_Message_Status_Bar(10);

        //Guardar imagen de respaldo antes de que se aplique el filtro
        imageRestore = *imageLabel;

        ui->origin->setPixmap(QPixmap::fromImage(filterEdgeDetection(*imageLabel,prewittX,prewittY,3,threshold(), background())));
        edgeDetection = "Prewitt";

        // Show Message status bar Ready!
        show_Message_Status_Bar(4);
    }
    else
    {
        messageBoxGrayscale("grayscale");
    }

}
void MainWindow::on_btnSobel_clicked()
{
    edgeOperation = 2;

    if(imageLabel->isGrayscale())
    {
        // Show Message status bar Calculated..
        show_Message_Status_Bar(10);

        //Guardar imagen de respaldo antes de que se aplique el filtro
        imageRestore = *imageLabel;

        ui->origin->setPixmap(QPixmap::fromImage(filterEdgeDetection(*imageLabel,sobelX,sobelY,3,threshold(), background())));
        edgeDetection = "Sobel";

        // Show Message status bar Ready!
        show_Message_Status_Bar(4);
    }
    else
    {
        messageBoxGrayscale("grayscale");
    }

}
// Guardo los cambios de la imagen al aplicar Sobel, Robert o Prewitt
void MainWindow::on_btnEdgeDetection_clicked()
{
    // Show Message status bar Saving..
    show_Message_Status_Bar(11);

    bool grayscale = false;

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

    // Update histograma
    updateHistograma();

    // Show Message status bar Saving..
    show_Message_Status_Bar(12);
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
        case 0: {imageLabel = &imageT;show_Message_Status_Bar(6);}
        break;
        case 1: {imageLabel = &imageR;show_Message_Status_Bar(7);}
        break;
        case 2: {imageLabel = &imageG;show_Message_Status_Bar(8);}
        break;
        case 3: {imageLabel = &imageB;show_Message_Status_Bar(9);}
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
    show_Message_Status_Bar(19);
    normalizeHistograma();
    render_Histograma_Min_Or_Max(true,channel);
    show_Message_Status_Bar(4);
}
// Metodo que ecualiza el histograma de la imagen dependiendo del valor almacenado
// en la variable global selectChannelHistograma
void MainWindow::on_equalizarHistograma_clicked()
{    
    // Show Message status bar Processing..
    show_Message_Status_Bar(16);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

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

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
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
    // Show Message status bar Calculated gamma...
    show_Message_Status_Bar(17);

    QImage gamma = gammaConstImage(*imageLabel,constOperationHistograma);

    // setear los valores del histograma en 0 dependiendo del canal
    qDebug()<<channel;
    setearHistograma(channel);
    createHistograma(gamma,channel);
    render_Histograma_Min_Or_Max(true,channel);
    render_Histograma_Min_Or_Max(false,channel);
    ui->origin->setPixmap(QPixmap::fromImage(gamma));

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
// Funcion que setea en el spinbox el valor del slider que corresponde al numero gamma
void MainWindow::on_gamma_sliderMoved(int position)
{
    ui->const_2->setValue(position*0.001);
}
// Guarda los cambios aplicados a la imagen sobre el gamma
void MainWindow::on_btnGamma_clicked()
{
    // Show Message status bar Saving...
    show_Message_Status_Bar(11);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = gammaConstImage(*imageLabel,constOperationHistograma);
    render_Miniature_Image();
    // Show Message status bar Saved!
    show_Message_Status_Bar(12);
}
// Funcion que suma una constante al histograma
void MainWindow::on_btnPlus_clicked()
{   
    // Show Message status bar Applying...
    show_Message_Status_Bar(18);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = sumConstImage(*imageLabel,constOperationHistograma,channel);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    // Update histograma
    updateHistograma();

    render_Miniature_Image();

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
}
// Funcion que resta una constante al histograma
void MainWindow::on_btnSubstract_clicked()
{
    // Show Message status bar Applying
    show_Message_Status_Bar(18);

    //Guardar imagen de respaldo antes de que se aplique el filtro
    imageRestore = *imageLabel;

    *imageLabel = susbtractConstImage(*imageLabel,constOperationHistograma,channel);
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    // Update histograma
    updateHistograma();

    render_Miniature_Image();

    // Show Message status bar Ready!
    show_Message_Status_Bar(4);
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
       QStringList listStructure = arrayStructure3x3[index-1].split(' ');
       // Funcion que muestra en pantalla los datos de la estructura
       show_Structure(listStructure);
       // Funcion que rellena una matriz con los valores de la estructura
       createMatrizStructure(listStructure);
       // Activo el btnDilation
       ui->btnDilation->setEnabled(true);
       ui->btnErosion->setEnabled(true);
       ui->btnOpening->setEnabled(true);
       ui->btnClosing->setEnabled(true);
//       ui->btnMorphologic->setEnabled(true);
    }
    if(ui->sizeEstruc->currentIndex() == 2 && index > 0)
    {
        // selecciono la estructura de un array y la convierto a una lista
        QStringList listStructure = arrayStructure5x5[index-1].split(' ');
        // Funcion que muestra en pantalla los datos de la estructura
        show_Structure(listStructure);
        // Funcion que rellena una matriz con los valores de la estructura
        createMatrizStructure(listStructure);
        // Activo el btnDilation
        ui->btnDilation->setEnabled(true);
        ui->btnErosion->setEnabled(true);
        ui->btnOpening->setEnabled(true);
        ui->btnClosing->setEnabled(true);
//        ui->btnMorphologic->setEnabled(true);
    }
}
void MainWindow::on_btnLeft_clicked()
{
    int index = ui->optionsEstruc->currentIndex();

    if(index <= 0)
    {
        ui->optionsEstruc->setCurrentIndex(7);
    }

    ui->optionsEstruc->setCurrentIndex(index-1);
}
void MainWindow::on_btnRight_clicked()
{
    int index = ui->optionsEstruc->currentIndex();

    if(index > 0)
    {
        ui->btnLeft->setEnabled(true);
    }

    if(index == 7)
    {
        ui->optionsEstruc->setCurrentIndex(1);
    }

    ui->optionsEstruc->setCurrentIndex(index+1);
}

// retornar un numero que corresponde al tamaño del kernel segun lo seleccionado en el comboBox
int MainWindow::sizeKernelOperatiosMorphologics()
{
    int index = ui->sizeEstruc->currentIndex();
    int size;

    if(index == 1)size = 3;
    if(index == 2)size = 5;

    return size;
}

/*************** Operaciones Morfologicas ***************/

void MainWindow::on_btnDilation_clicked()
{    
    if(imageBinaria(*imageLabel))
    {
        show_Message_Status_Bar(18);
        //Guardar imagen de respaldo antes de que se aplique el filtro
        imageRestore = *imageLabel;

        morphologic = 0;

        if(background())
        {
            *imageLabel = dilationOrErosion(*imageLabel,false,sizeKernelOperatiosMorphologics());
        }
        else
        {
            *imageLabel = dilationOrErosion(*imageLabel,true,sizeKernelOperatiosMorphologics());
        }

        ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

        // Update histograma
        updateHistograma();

        show_Message_Status_Bar(4);
    }
    else
    {
         messageBoxGrayscale("binaria");
    }

}
void MainWindow::on_btnErosion_clicked()
{
    if(imageBinaria(*imageLabel))
    {
        show_Message_Status_Bar(18);

        //Guardar imagen de respaldo antes de que se aplique el filtro
        imageRestore = *imageLabel;

        morphologic = 1;

        if(background())
        {
            *imageLabel = dilationOrErosion(*imageLabel,true,sizeKernelOperatiosMorphologics());
        }
        else
        {
            *imageLabel = dilationOrErosion(*imageLabel,false,sizeKernelOperatiosMorphologics());
        }

        ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

        // Update histograma
        updateHistograma();

        show_Message_Status_Bar(4);
    }
    else
    {
         messageBoxGrayscale("binaria");
    }
}
void MainWindow::on_btnOpening_clicked()
{

    if(imageBinaria(*imageLabel))
    {
        show_Message_Status_Bar(18);

        QImage transicion;

        //Guardar imagen de respaldo antes de que se aplique el filtro
        imageRestore = *imageLabel;

        morphologic = 2;

        if(background())
        {
            transicion = dilationOrErosion(*imageLabel,true,sizeKernelOperatiosMorphologics());
            *imageLabel = dilationOrErosion(transicion,false,sizeKernelOperatiosMorphologics());
        }
        else
        {
            transicion = dilationOrErosion(*imageLabel,false,sizeKernelOperatiosMorphologics());
            *imageLabel = dilationOrErosion(transicion,true,sizeKernelOperatiosMorphologics());
        }

        ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

        // Update histograma
        updateHistograma();

        show_Message_Status_Bar(4);
    }
    else
    {
         messageBoxGrayscale("binaria");
    }
}
void MainWindow::on_btnClosing_clicked()
{

    if(imageBinaria(*imageLabel))
    {
        show_Message_Status_Bar(18);

        QImage transicion;

        //Guardar imagen de respaldo antes de que se aplique el filtro
        imageRestore = *imageLabel;
        morphologic = 3;

        if(background())
        {
            transicion = dilationOrErosion(*imageLabel,false,sizeKernelOperatiosMorphologics());
            *imageLabel = dilationOrErosion(transicion,true,sizeKernelOperatiosMorphologics());
        }
        else
        {
            transicion = dilationOrErosion(*imageLabel,true,sizeKernelOperatiosMorphologics());
            *imageLabel = dilationOrErosion(transicion,false,sizeKernelOperatiosMorphologics());
        }

        ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

        // Update histograma
        updateHistograma();

        show_Message_Status_Bar(4);
    }
    else
    {
         messageBoxGrayscale("binaria");
    }
}

/********************** Fin **********************/

/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/

void MainWindow::on_actionDemo_triggered()
{


//      ui->origin->setPixmap(QPixmap::fromImage(segmentationKMeans(*imageLabel,2)));
//    int threshold = ui->threshold->value();
//      ui->origin->setPixmap(QPixmap::fromImage(segmentationThreshold(*imageLabel,threshold)));
// filtro laplaciano
//    listLaplaciano = sizeKernelAverageOrGaussiano(sizeKernel,"average");
//    int threshold = ui->threshold->value();
//    listLaplaciano = stringLaplaciano5x5.split(' ');
//    createMatriz(listLaplaciano);
//    ui->origin->setPixmap(QPixmap::fromImage(filterLaplaciano(*imageLabel,3,threshold)));

    // filtro norte y este
//    *imageLabel = filterEdgeDetection(*imageLabel,este,norte,3,threshold,background());
//    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
}





/*-----------------------------------------------------------------------------------------------------------/*
 * Options
 *-----------------------------------------------------------------------------------------------------------*/
// Seteo la variable image con el valor actual de imageLabel
// para inciar una nueva conversion de espacios de color
void MainWindow::on_actionNew_Convertion_triggered()
{

    image = *imageLabel;
    // renderizar miniaturas vacias
    render_Miniature_Image(false);
    // Deshabilitar botones
    enable_BtnImage(false);
    // Seteo los valores para el histograma
    setearHistograma(5);
    // pintar el histograma
    render_Histograma_Min_Or_Max(true,channel);
    render_Histograma_Min_Or_Max(false,channel);
    // Desahabilitar la opcion de convertir a YYY
    ui->actionConvert_to_YYY->setEnabled(false);

    ui->before->clear();
    ui->after->setPixmap(QPixmap::fromImage(*imageLabel));
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

}

void MainWindow::on_actionUndo_triggered()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageRestore));

    switch(channel)
    {
        case 0: {imageT = imageRestore; imageLabel = &imageT;}
        break;
        case 1: {imageR = imageRestore; imageLabel = &imageR;}
        break;
        case 2: {imageG = imageRestore; imageLabel = &imageG;}
        break;
        case 3: {imageB = imageRestore; imageLabel = &imageB;}
        break;
    }

    // pinto nuevamente las miniaturas
    render_Miniature_Image();

    // Update histograma
    updateHistograma();

}

void MainWindow::on_actionConfusion_table_triggered()
{
    Progress *progress = new Progress(this);
    progress->show();
    progress->setModal(true);
    progress->showImageA(*imageLabel);
}

void MainWindow::on_actionSave_Step_triggered()
{
    step = *imageLabel;
}

void MainWindow::on_actionShow_Step_triggered()
{
    imageLabel = &step;    
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    on_actionNew_Convertion_triggered();
}
/********************* Options Masks *******************/
// Crear mascara
void MainWindow::on_actionNew_triggered()
{
    mask = imageLabel->createHeuristicMask();
    ui->origin->setPixmap(QPixmap::fromImage(mask));
}
// Guardar mascara
void MainWindow::on_actionSave_2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "", tr("Images (*.png)"));

    if (!fileName.isEmpty())
    {
        if (!mask.save(fileName))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        else
        {
            mask.save(fileName);
        }
    }
    // Show Message status bar Save
    show_Message_Status_Bar(2);
}
// Cargar mascara
void MainWindow::on_actionLoad_triggered()
{
    show_Message_Status_Bar(0);

    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.png *.jpg *.bmp *.tif *.gif)"));

    mask.load(file);

    if (!file.isEmpty())
    {
        if (!mask.load(file))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            show_Message_Status_Bar(4);
        }
    }

}
// Aplicar mascara
void MainWindow::on_actionApply_triggered()
{
    show_Message_Status_Bar(18);

    *imageLabel = applyMask(*imageLabel,mask);
    render_Miniature_Image();
    updateHistograma();
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    show_Message_Status_Bar(4);
}
/*-----------------------------------------------------------------------------------------------------------/*
 * Fin
 *-----------------------------------------------------------------------------------------------------------*/






