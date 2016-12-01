#ifndef PROGRESS_H
#define PROGRESS_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class Progress;
}

class Progress : public QDialog
{
    Q_OBJECT

public:
    explicit Progress(QWidget *parent = 0);
    ~Progress();

    QMovie *movie = new QMovie(":/img/loading.gif");

    void insertMessage(QString message = "Loading...");

    Ui::Progress *ui;

private:

};

#endif // PROGRESS_H
