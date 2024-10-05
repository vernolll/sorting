#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "../include/sorting.h"

class Sorting;

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void on_pushButton_choic_clicked();
    void on_pushButton_bubble_clicked();
    void on_pushButton_heap_clicked();
    void on_pushButton_all_kind_clicked();

private:
    Ui::MainWindow *ui;
    Sorting *CSort;
};
#endif // MAINWINDOW_H
