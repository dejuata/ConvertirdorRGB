#ifndef SETTINGSFILTER_H
#define SETTINGSFILTER_H

#include <QDialog>

namespace Ui {
class SettingsFilter;
}

class SettingsFilter : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsFilter(QWidget *parent = 0);
    ~SettingsFilter();
     Ui::SettingsFilter *ui;

private slots:

    void on_selectFilter_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:

};

#endif // SETTINGSFILTER_H
