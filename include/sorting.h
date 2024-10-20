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
#include <QMessageBox>

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

    //void all_kind();
    void next_page();
    void back_to_diagrams();
    void back_to_menu();
    /*
    void lexic_alone();
    void quick_alone();
    void heap_alone();
    void merge_alone();
    void insert_alone();
    void bubble_alone();*/
    void select_alone();


private:
    Ui::MainWindow *ui;
    QChartView *chartView;

    void parcing_txt(char** words, int maxSize);
    void parcing(double ages[], int size);
    template<typename T>
    void choice(T* massive, int size);
    /*
    void bubble(double massive[], int size);
    void insertion(double massive[], int size);
    void merge_(double massive[], int l, int m, int r);
    void mergeSort(double massive[], int l, int r);
    void heapify(double massive[], int size, int i) ;
    void heap(double massive[], int size);
    void quickSort(double arr[], int low, int high)
    bool compareWords(const char* word1, const char* word2);
    void lex_quickSort(char** words, int left, int right);
*/

    template<typename T>
    QVector<qint64> sortItems_select();
    /*
    QVector<qint64> sortItems_bubble();
    QVector<qint64> sortItems_insertion();
    QVector<qint64> sortItems_merge();
    QVector<qint64> sortItems_heap();
    QVector<qint64> sortItems_quickSort();
    QVector<qint64> sortWords();
*/
    QChartView* sortingHelper(std::function<QList<long long>()> sortingFunction, const QString& title);

    template<typename T>
    QVector<qint64> sortItems(std::function<void(T*, int)> sortFunction);
};

#endif // SORTING_H
