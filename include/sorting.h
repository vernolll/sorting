#ifndef SORTING_H
#define SORTING_H

#include <QObject>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QStringList>

#include "../ui/ui_mainwindow.h"

namespace Ui
{
class MainWindow;
}

class Sorting : public QObject
{
    Q_OBJECT
public:
    explicit Sorting(Ui::MainWindow *ui, QObject *parent = nullptr);
    ~Sorting();

public slots:
    void parcing(double ages[], int size);
    void choice();
    void bubble();
    void insertion();
    //void merge_();
    //void mergeSort();
    void heapify(double massive[], int size, int i) ;
    void heap();
    //void quickSort();
    //bool compareWords();
    //void lex_bubbleSort();
    //void sortWords();

private:
    Ui::MainWindow *ui;


    void print(double massive[], int size);
};

#endif // SORTING_H
