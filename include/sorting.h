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
    void all_kind();
    void next_page();
    void next_diagram();;
    void back_to_diagrams();
    void back_to_menu();
    void bubble_alone();
    void select_alone();
    void insert_alone();
    void heap_alone();
    void merge_alone();
    void quick_alone();

private:
    Ui::MainWindow *ui;
    QChartView *chartView;

    void parcing_txt(char** words, int maxSize);
    void parcing(double ages[], int size);
    template<typename T>
    void choice(T* massive, int size);
    template<typename T>
    void bubble(T* massive, int size);
    template<typename T>
    void insertion(T* massive, int size);
    template<typename T>
    void heap(T* massive, int size);
    template<typename T>
    void heapify(T* massive, int size, int i) ;
    template<typename T>
    void merge_(T* massive, int l, int m, int r);
    template<typename T>
    void mergeSort(T* massive, int l, int r);
    template<typename T>
    void quickSort(T* arr, int low, int high);

    template<typename T>
    QVector<qint64> sortItems_select();
    template<typename T>
    QVector<qint64> sortItems_bubble();
    template<typename T>
    QVector<qint64> sortItems_insertion();
    template<typename T>
    QVector<qint64> sortItems_heap();
    template<typename T>
    QVector<qint64> sortItems_merge();
    template<typename T>
    QVector<qint64> sortItems_quickSort();


    QChartView* sortingHelper(std::function<QList<long long>()> sortingFunction, const QString& title);

    template<typename T>
    QVector<qint64> sortItems(std::function<void(T*, int)> sortFunction);

    void displaySortingResults(
        const std::vector<std::function<QList<long long>()>>& sortingFunctions,
        const QStringList& titles);
};

#endif // SORTING_H
