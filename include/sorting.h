#ifndef SORTING_H
#define SORTING_H

#include <QObject>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QElapsedTimer>
#include <QtCharts>

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
    void all_kind();
    void parcing(double ages[], int size);
    int sort500Items_select();
    int sort1000Items_select();
    int sort5000Items_select();
    int choice(double massive[], int size);
    int sort500Items_bubble();
    int sort1000Items_bubble();
    int sort5000Items_bubble();
    int bubble(double massive[], int size);
    int sort500Items_insertion();
    int sort1000Items_insertion();
    int sort5000Items_insertion();
    int insertion(double massive[], int size);
    //void merge_();
    //void mergeSort();
    int sort500Items_heap();
    int sort1000Items_heap();
    int sort5000Items_heap();
    void heapify(double massive[], int size, int i) ;
    int heap(double massive[], int size);
    //void quickSort();
    //bool compareWords();
    //void lex_bubbleSort();
    //void sortWords();

private:
    Ui::MainWindow *ui;
    QChartView *chartView;

    void print(double massive[], int size);
};

#endif // SORTING_H
