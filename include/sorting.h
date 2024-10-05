#ifndef SORTING_H
#define SORTING_H

#include <QObject>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QElapsedTimer>
#include <QtCharts>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <cctype>
#include <QLegend>

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
    void next_page();
    void back_to_diagrams();
    void back_to_menu();
    void choosed_pattern();
    void lexic_alone();
    void quick_alone();
    void heap_alone();
    void merge_alone();
    void insert_alone();
    void bubble_alone();
    void select_alone();

private:
    Ui::MainWindow *ui;
    QChartView *chartView;

    void parcing(double ages[], int size);
    int choice(double massive[], int size);
    int bubble(double massive[], int size);
    int insertion(double massive[], int size);
    void merge_(double massive[], int l, int m, int r);
    void mergeSort(double massive[], int l, int r);
    void heapify(double massive[], int size, int i) ;
    int heap(double massive[], int size);
    void quickSort(double arr[], int low, int high);
    void parcing_txt(QString* words, int maxSize);
    bool compareWords(const QString& word1, const QString& word2);
    void lex_quickSort(QString* words, int left, int right);


    int sort500Items_select();
    int sort1000Items_select();
    int sort5000Items_select();
    int sort500Items_bubble();
    int sort1000Items_bubble();
    int sort5000Items_bubble();
    int sort500Items_insertion();
    int sort1000Items_insertion();
    int sort5000Items_insertion();
    int sort500Items_merge();
    int sort1000Items_merge();
    int sort5000Items_merge();
    int sort500Items_heap();
    int sort1000Items_heap();
    int sort5000Items_heap();
    int sort500Items_quickSort();
    int sort1000Items_quickSort();
    int sort5000Items_quickSort();
    int sortWords1000();
    int sortWords500();
    int sortWords5000();
};

#endif // SORTING_H
