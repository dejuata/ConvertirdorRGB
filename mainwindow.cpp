#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsfilter.h"
#include "ui_settingsfilter.h"
#include "convertImage.h"
#include "filter.h"
#include "histograma.h"
#include "resources.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->histograma->hide();
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

   image.load(file);
   // convertir la imagen a formato rgb 8 bits;
   image = image.convertToFormat(QImage::Format_RGB888);

   if (!file.isEmpty())
   {
       if (!image.load(file))
       {
           QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
           return;
       }
    }

    ui->after->setPixmap(QPixmap::fromImage(image));
    ui->origin->setPixmap(QPixmap::fromImage(image));    

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

/*
 * Metodos que llaman a las funciones de convercion de formatos RGB -> RGB, YUV, YIQ, CMY, HSV, HSL, XYZ, O1O2O3
 */
void MainWindow::on_actionRGB_to_RGB_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        /* Renderizo imagenes en label miniatura, ademas las almaceno en variables globales
         * para poderlas renderizar en el label origin ademas de que se puedan enviar como parametros
         * a distintas funciones
         */
        channelR = "Red", channelG = "Green", channelB = "Blue";

        futureRGB();

        render_Miniature_Image();
        show_Text_UI("R","G","B");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_YYY_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "Red", channelG = "Green", channelB = "Blue";

        futureYYY();

        render_Miniature_Image();
        show_Text_UI("Y","Y","Y");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_YUV_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "Y", channelG = "U", channelB = "V";

        // Renderizo imagenes en label
        futureYUV();

        render_Miniature_Image();
        show_Text_UI("Y","U","V");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_YIQ_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "Y", channelG = "I", channelB = "Q";

        // Renderizo imagenes en label
        futureYIQ();

        render_Miniature_Image();
        show_Text_UI("Y","I","Q");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_CMY_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "Cyan", channelG = "Magenta", channelB = "Yellow";

        // Renderizo imagenes en label
        futureCMY();

        render_Miniature_Image();
        show_Text_UI("C","M","Y");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_HSV_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "Hue", channelG = "Saturation", channelB = "Value";

        // Renderizo imagenes en label
        futureHSV();

        render_Miniature_Image();
        show_Text_UI("H","S","V");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_HSL_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "Hue", channelG = "Saturation", channelB = "Ligntness";

        // Renderizo imagenes en label
        futureHSL();

        render_Miniature_Image();
        show_Text_UI("H","S","L");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_XYZ_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "X", channelG = "Y", channelB = "Z";

        // Renderizo imagenes en label
        futureXYZ();

        render_Miniature_Image();
        show_Text_UI("X","Y","Z");
        show_Label_Image_Hide_Histograma(0);
    }
}
void MainWindow::on_actionRGB_to_O1O2O3_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        channelR = "O1", channelG = "O2", channelB = "O3";

        // Ejecuto las funciones de procesamiento para cada canal en un hilo respectivo
        futureOOO();

        render_Miniature_Image();
        show_Text_UI("O1","O2","O3");
        show_Label_Image_Hide_Histograma(0);
    }
}

/*
 * Muestro la imagen en el label origin cada vez que se da clic al btn de la miniatura
 */
void MainWindow::on_btn_origin_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(image));
    imageLabel = &image;
    show_Label_Image_Hide_Histograma(0);
}
void MainWindow::on_btn_transform_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageT));
    imageLabel = &imageT;
    show_Label_Image_Hide_Histograma(0);
}
void MainWindow::on_btn_one_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageR));
    imageLabel = &imageR;
    show_Label_Image_Hide_Histograma(1);
}
void MainWindow::on_btn_two_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageG));
    imageLabel = &imageG;
    show_Label_Image_Hide_Histograma(2);
}
void MainWindow::on_btn_three_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageB));
    imageLabel = &imageB;
    show_Label_Image_Hide_Histograma(3);
}

/*
 *  Crea y muestra la ventana de configuracion de filtros
 */
void MainWindow::on_actionSettings_triggered()
{
    SettingsFilter *averange = new SettingsFilter(this);
    averange->setModal(true);
    averange->show();
}

/*
 * CONFIGURACIÓN DE FILTROS POR DEFAULT -> VENTANA SETTINGSFILTER
 *
 * Si la variable int selectFilter esta inicialida con estos valores, corresponde a:
 * 0 -> Filtro promedio
 * 1 -> Filtro Gaussiano
 * 2 -> Filtro Minimo
 * 3 -> Filtro Mediano
 * 4 -> Filtro Maximo
 */
void SettingsFilter::on_filterByDefault_currentIndexChanged(int index)
{
    // Filtro Promedio
    if(index == 1)
    {
        clear_options();
        // por default trabaja con el kernel promedio
        selectFilter = 0;
        // Desplegar las casillas vacias correspondientes al tamaño del filtro en pantalla
        on_selectFilter_currentIndexChanged(1);
        // Insertar los valores que trae el filtro por defecto
        show_value_kernel(listAverage, 1);
    }
    // Filtro Gaussiano
    if(index == 2)
    {
        clear_options();
        selectFilter = 1;
        qDebug()<<"Seleccione kernel gaussiano";
        on_selectFilter_currentIndexChanged(1);
        show_value_kernel(listGaussiano, 1);
    }
    // Filtro Minimo
    if(index == 3)
    {
        clear_options();
        selectFilter = 2;
        qDebug()<<"Seleccione minimo";
    }
    // Filtro Mediano
    if(index == 4)
    {
        clear_options();
        selectFilter = 3;
        qDebug()<<"Seleccione mediano";
    }
    // Filtro Maximo
    if(index == 5)
    {
        clear_options();
        selectFilter = 4;
        qDebug()<<"Seleccione maximo";
    }
    // Filtro Sigma
    if(index == 6)
    {
        selectFilter = 5;
        qDebug()<<"Seleccione sigma";
        ui->optionsLabel->show();
        ui->optionsNumber->show();
    }
    // Filtro Nagao
    if(index == 7)
    {
        selectFilter = 6;
        qDebug()<<"Seleccione nagao";
    }
}

// cargar filtros externos en archivos txt
void SettingsFilter::on_pushButton_clicked()
{
    QString text;
    QStringList lists;

    // cargo el txt con el filtro
    QFile file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.txt)"));
    file.open(QIODevice::ReadOnly);

    QTextStream result(&file);

    text = result.readAll();

    // Limpiar el string
    lists = cleanMatriz(text);

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
        on_selectFilter_currentIndexChanged(3);
        show_value_kernel(lists, 3);
    }

    qDebug()<<"list: "<<lists;

    // Asignar a la matriz los valores del string
    createMatriz(lists);

    // Asigno este valor para indicar que el programa trabaje con la matriz cargada
    selectFilter = 9;

    ui->loaded->show();

    qDebug()<<"CARGO FILTRO";

    file.close();

}

// Si el usuario selecciona en el menu filter -> channel T
void MainWindow::on_actionTransform_triggered()
{
    action_Filter_Select(imageT);
}
void MainWindow::on_actionChannel_One_triggered()
{
    action_Filter_Select(imageR);
}
void MainWindow::on_actionChannel_Two_triggered()
{
   action_Filter_Select(imageG);
}
void MainWindow::on_actionChannel_Three_triggered()
{
    action_Filter_Select(imageB);
}

// Metodo que renderiza el histograma en su tamaño maximo al ser clickeado el btn
void MainWindow::on_btn_histograma_clicked()
{
    ui->origin->hide();
    ui->histograma->show();

    render_Histograma_Min_Or_Max(true);
}

// Metodo que me muestra la miniatura del histograma, dependiendo de la opcion del combo box
void MainWindow::on_selectChannelHistograma_currentIndexChanged(int index)
{
    selectChannelHistograma = index;

    render_Histograma_Min_Or_Max(false);
}

// evento del btn que llama a la funcion equalizar histograma
void MainWindow::on_equalizarHistograma_clicked()
{
    // asignar a las imagenes el resultado correspondendiente de equalizar el histograma para cada canal
    if(selectChannelHistograma == 0)
    {
        imageT = equalization_Histograma(imageT,selectChannelHistograma);
        imageLabel = &imageT;
    }
    if(selectChannelHistograma == 1)
    {
        imageR = equalization_Histograma(imageR,selectChannelHistograma);
        imageLabel = &imageR;
    }
    if(selectChannelHistograma == 2)
    {
        imageG = equalization_Histograma(imageG,selectChannelHistograma);
        imageLabel = &imageG;
    }
    if(selectChannelHistograma == 3)
    {
        imageB = equalization_Histograma(imageB,selectChannelHistograma);
        imageLabel = &imageB;
    }

    // renderizar imagenes en miniatura
    render_Miniature_Image();

    // Renderizar la imagen si el histograma cambia, este efecto sucede si el label esta activo -> show()
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));

    // Crear y mostrar el histograma en el QGraphicsScene Maximum
    create_Histograma(*imageLabel,selectChannelHistograma,true);
    // Crear y mostrar el histograma en el QGraphicsScene Minimum
    create_Histograma(*imageLabel,selectChannelHistograma,false);
}





// Filtros configurados como botones
void MainWindow::on_btnAverage_clicked()
{
    createMatriz(listAverage);
    ui->origin->setPixmap(QPixmap::fromImage(filterAverageAndGaussiano(*imageLabel, 3, "average")));
}
void MainWindow::on_btnGaussiano_clicked()
{
    createMatriz(listGaussiano);
    ui->origin->setPixmap(QPixmap::fromImage(filterAverageAndGaussiano(*imageLabel, 3, "gaussiano")));
}
void MainWindow::on_btnMinimum_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(filterMinMedMax(*imageLabel, 0)));
}
void MainWindow::on_btnMedium_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(filterMinMedMax(*imageLabel, 1)));
}
void MainWindow::on_btnMaximum_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(filterMinMedMax(*imageLabel, 2)));
}
void MainWindow::on_btnSigma_clicked()
{
     ui->origin->setPixmap(QPixmap::fromImage(filterSigma(*imageLabel,numberSigma)));
}
void MainWindow::on_btnNagao_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(filterNagao(*imageLabel)));
}
