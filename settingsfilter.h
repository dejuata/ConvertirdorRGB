#ifndef SETTINGSFILTER_H
#define SETTINGSFILTER_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

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

    void on_filterByDefault_currentIndexChanged(int index);

    void on_btnLoad_clicked();

private:

    void show_value_kernel(QStringList lists, int value);

    void enable_Input(bool disabled = true);

};

#endif // SETTINGSFILTER_H
