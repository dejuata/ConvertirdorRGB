#include "progress.h"
#include "ui_progress.h"

Progress::Progress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Progress)
{
    ui->setupUi(this);

    ui->loadingLabel->setMovie(movie);
    movie->start();
}

Progress::~Progress()
{
    delete ui;
}

// Inserto mensaje en el label
void Progress::insertMessage(QString message)
{
    ui->message->setText(message);
}
