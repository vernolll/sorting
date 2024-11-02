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
    void on_pushButton_next_clicked();
    void on_pushButton_menu_clicked();
    void on_pushButton_quick_clicked();
    void on_pushButton_merge_clicked();
    void on_pushButton_insertion_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_next_2_clicked();
    void on_pushButton_back_2_clicked();

private:
    Ui::MainWindow *ui;
    Sorting *CSort;
};
#endif // MAINWINDOW_H
