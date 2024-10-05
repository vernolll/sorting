#include "../include/sorting.h"


Sorting::Sorting(Ui::MainWindow *ui, QObject *parent) :
    QObject(parent),
    ui(ui)
{
}


Sorting::~Sorting()
{

}


void Sorting::parcing_txt(QString* words, int maxSize)
{
    std::ifstream file("D:/university/3 semestr/laba1_algos/build/1984-george-orwell.txt", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: D:/university/3 semestr/laba1_algos/build/1984-george-orwell.txt" << std::endl;
        return;
    }

    std::string line;
    int currentIndex = 0;

    while (std::getline(file, line) && currentIndex < maxSize)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring wideLine = converter.from_bytes(line);

        std::wistringstream wiss(wideLine);
        std::wstring word;

        while (wiss >> word)
        {
            QString qConvertedWord = QString::fromStdWString(word);
            if (!qConvertedWord.isEmpty() && currentIndex < maxSize)
            {
                words[currentIndex] = qConvertedWord;
                currentIndex++;
            }
        }
    }

    file.close();
}


void Sorting::parcing(double ages[], int size)
{
    QString filePath = "D:/university/3 semestr/laba1_algos/build/adult.data.csv";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Cannot open file:" << file.errorString();
        return;
    }

    int count = 0;

    QTextStream in(&file);

    while (!in.atEnd() && count < size)
    {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() > 1)
        {
            bool ok;
            int age = fields[0].toDouble(&ok);
            if (ok)
            {
                ages[count++] = age;
            }
        }
    }

    file.close();
}


void Sorting::all_kind()
{
    int select500 = sort500Items_select();
    int select1000 = sort1000Items_select();
    int select5000 = sort5000Items_select();
    int bubble500 = sort500Items_bubble();
    int bubble1000 = sort1000Items_bubble();
    int bubble5000 = sort5000Items_bubble();
    int insert500 = sort500Items_insertion();
    int insert1000 = sort1000Items_insertion();
    int insert5000 = sort5000Items_insertion();
    int heap500 = sort500Items_heap();
    int heap1000 = sort1000Items_heap();
    int heap5000 = sort5000Items_heap();
    int merge500 = sort500Items_merge();
    int merge1000 = sort1000Items_merge();
    int merge5000 = sort5000Items_merge();
    int quick500 = sort500Items_quickSort();
    int quick1000 = sort1000Items_quickSort();
    int quick5000 = sort5000Items_quickSort();
    int lexic500 = sortWords500();
    int lexic1000 = sortWords1000();
    int lexic5000 = sortWords5000();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("Выбором");
    auto set1 = new QBarSet("Пузырьком");
    auto set2 = new QBarSet("Вставками");
    auto set3 = new QBarSet("Пирамидальная");
    auto set4 = new QBarSet("Слиянием");
    auto set5 = new QBarSet("Быстрая");
    auto set6 = new QBarSet("Лексикографическая");

    *set0 << select5000;
    *set1 << bubble5000;
    *set2 << insert5000;
    *set3 << heap5000;
    *set4 << merge5000;
    *set5 << quick5000;
    *set6 << lexic5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("5к элементов");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QBarSeries *series1 = new QBarSeries;

    auto set01 = new QBarSet("Выбором");
    auto set11 = new QBarSet("Пузырьком");
    auto set21 = new QBarSet("Вставками");
    auto set31 = new QBarSet("Пирамидальная");
    auto set41 = new QBarSet("Слиянием");
    auto set51 = new QBarSet("Быстрая");
    auto set61 = new QBarSet("Лексикографическая");

    *set01 << select1000;
    *set11 << bubble1000;
    *set21 << insert1000;
    *set31 << heap1000;
    *set41 << merge1000;
    *set51 << quick1000;
    *set61 << lexic1000;

    series1->append(set01);
    series1->append(set11);
    series1->append(set21);
    series1->append(set31);
    series1->append(set41);
    series1->append(set51);
    series1->append(set61);

    QChart *chart1 = new QChart();
    chart1->addSeries(series1);
    chart1->setTitle("1к элементов");
    chart1->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX1 = new QBarCategoryAxis();
    chart1->addAxis(axisX1, Qt::AlignBottom);
    series1->attachAxis(axisX1);

    QValueAxis *axisY1 = new QValueAxis();
    chart1->addAxis(axisY1, Qt::AlignLeft);
    series1->attachAxis(axisY1);

    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);


    QBarSeries *series2 = new QBarSeries;

    auto set02 = new QBarSet("Выбором");
    auto set12 = new QBarSet("Пузырьком");
    auto set22 = new QBarSet("Вставками");
    auto set32 = new QBarSet("Пирамидальная");
    auto set42 = new QBarSet("Слиянием");
    auto set52 = new QBarSet("Быстрая");
    auto set62 = new QBarSet("Лексикографическая");

    *set02 << select500;
    *set12 << bubble500;
    *set22 << insert500;
    *set32 << heap500;
    *set42 << merge500;
    *set52 << quick500;
    *set62 << lexic500;

    series2->append(set02);
    series2->append(set12);
    series2->append(set22);
    series2->append(set32);
    series2->append(set42);
    series2->append(set52);
    series2->append(set62);

    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("500 элементов");
    chart2->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX2 = new QBarCategoryAxis();
    chart2->addAxis(axisX2, Qt::AlignBottom);
    series2->attachAxis(axisX2);

    QValueAxis *axisY2 = new QValueAxis();
    chart2->addAxis(axisY2, Qt::AlignLeft);
    series2->attachAxis(axisY2);

    QLegend* legend = chart->legend();
    legend->setMinimumWidth(500);

    chart2->setMinimumSize(605, 567);
    chart1->setMinimumSize(605, 567);
    chart->setMinimumSize(605*2, 567);

    QLayoutItem *item2, *item3, *item;

    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QVBoxLayout *layout2 = ui->verticalLayout_4;
    QVBoxLayout *layout = ui->verticalLayout_5;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    while ((item2 = layout2->takeAt(0)) != nullptr)
    {
        if (item2->widget())
        {
            delete item2->widget();
        }
        delete item2;
    }

    while ((item3 = layout->takeAt(0)) != nullptr)
    {
        if (item3->widget())
        {
            delete item3->widget();
        }
        delete item3;
    }


    QChartView *chartView3 = new QChartView(chart2);
    layout3->addWidget(chartView3);

    QChartView *chartView1 = new QChartView(chart1);
    layout2->addWidget(chartView1);

    QChartView *chartView = new QChartView(chart);
    layout->addWidget(chartView);
}


int Sorting::sort500Items_select()
{
    const int size = 500;
    double massive[size];
    parcing(massive, size);

    return choice(massive, size);
}


int Sorting::sort1000Items_select()
{
    const int size = 1000;
    double massive[size];
    parcing(massive, size);

    return choice(massive, size);
}


int Sorting::sort5000Items_select()
{
    const int size = 5000;
    double massive[size];
    parcing(massive, size);

    return choice(massive, size);
}


int Sorting::sort500Items_bubble()
{
    const int size = 500;
    double massive[size];
    parcing(massive, size);

    return bubble(massive, size);
}


int Sorting::sort1000Items_bubble()
{
    const int size = 1000;
    double massive[size];
    parcing(massive, size);

    return bubble(massive, size);
}


int Sorting::sort5000Items_bubble()
{
    const int size = 5000;
    double massive[size];
    parcing(massive, size);

    return bubble(massive, size);
}


int Sorting::choice(double massive[], int size)
{
    QElapsedTimer timer;
    timer.start();

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (massive[j] < massive[minIndex])
            {
                minIndex = j;
            }
        }

        double temp = massive[minIndex];
        massive[minIndex] = massive[i];
        massive[i] = temp;
    }

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Time taken to sort the array of size(select) " << size << ": " << elapsed << " nsecs";

    return elapsed;
}


int Sorting::bubble(double massive[], int size)
{
    QElapsedTimer timer;
    timer.start();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (massive[j] > massive[j + 1])
            {
                double temp = massive[j];
                massive[j] = massive[j + 1];
                massive[j + 1] = temp;
            }
        }
    }

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Time taken to sort the array of size(bubble) " << size << ": " << elapsed << " nsecs";

    return elapsed;
}


int Sorting::sort500Items_insertion()
{
    const int size = 500;
    double massive[size];
    parcing(massive, size);

    return insertion(massive, size);
}


int Sorting::sort1000Items_insertion()
{
    const int size = 1000;
    double massive[size];
    parcing(massive, size);

    return insertion(massive, size);
}


int Sorting::sort5000Items_insertion()
{
    const int size = 5000;
    double massive[size];
    parcing(massive, size);

    return insertion(massive, size);
}


int Sorting::insertion(double massive[], int size)
{
    QElapsedTimer timer;
    timer.start();

    double key;
    for (int i = 1; i < size; i++)
    {
        key = massive[i];
        int j = i - 1;

        while (j >= 0 && massive[j] > key)
        {
            massive[j + 1] = massive[j];
            j = j - 1;
        }
        massive[j + 1] = key;
    }

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Time taken to sort the array of size(insertion) " << size << ": " << elapsed << " nsecs";

    return elapsed;
}


int Sorting::sort500Items_merge()
{
    const int size = 500;
    double massive[size];
    parcing(massive, size);

    QElapsedTimer timer;
    timer.start();
    mergeSort(massive, 0, size - 1);
    qint64 elapsed = timer.nsecsElapsed();
    return elapsed;
}


int Sorting::sort1000Items_merge()
{
    const int size = 1000;
    double massive[size];
    parcing(massive, size);

    QElapsedTimer timer;
    timer.start();
    mergeSort(massive, 0, size - 1);
    qint64 elapsed = timer.nsecsElapsed();
    return elapsed;
}


int Sorting::sort5000Items_merge()
{
    const int size = 5000;
    double massive[size];
    parcing(massive, size);

    QElapsedTimer timer;
    timer.start();
    mergeSort(massive, 0, size - 1);
    qint64 elapsed = timer.nsecsElapsed();
    return elapsed;
}



void Sorting::merge_(double massive[], int l, int m, int r)
{
    int i, j, k;
    // вычисление длины левой части массива
    int n1 = m - l + 1;
    // вычисление длины правой части массива
    int n2 = r - m;

    double* L = new double[n1];
    double* R = new double[n2];

    for (i = 0; i < n1; i++)
        L[i] = massive[l + i];
    for (j = 0; j < n2; j++)
        R[j] = massive[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            massive[k] = L[i];
            i++;
        }
        else
        {
            massive[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        massive[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        massive[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


void Sorting::mergeSort(double massive[], int l, int r)
{
    // вычисление индекса середины массива
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(massive, l, m);
        mergeSort(massive, m + 1, r);

        merge_(massive, l, m, r);
    }
}


int Sorting::sort500Items_heap()
{
    const int size = 500;
    double massive[size];
    parcing(massive, size);

    return heap(massive, size);
}


int Sorting::sort1000Items_heap()
{
    const int size = 1000;
    double massive[size];
    parcing(massive, size);

    return heap(massive, size);
}


int Sorting::sort5000Items_heap()
{
    const int size = 5000;
    double massive[size];
    parcing(massive, size);

    return heap(massive, size);
}

void Sorting::heapify(double massive[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && massive[l] > massive[largest])
        largest = l;

    if (r < size && massive[r] > massive[largest])
        largest = r;

    if (largest != i)
    {
        double temp = massive[i];
        massive[i] = massive[largest];
        massive[largest] = temp;
        heapify(massive, size, largest);
    }
}


int Sorting::heap(double massive[], int size)
{
    QElapsedTimer timer;
    timer.start();

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(massive, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        double temp = massive[0];
        massive[0] = massive[i];
        massive[i] = temp;
        heapify(massive, i, 0);
    }

    qint64 elapsed = timer.nsecsElapsed();
    qDebug() << "Time taken to sort the array of size(heap) " << size << ": " << elapsed << " nsecs";

    return elapsed;
}


int Sorting::sort500Items_quickSort()
{
    const int size = 500;
    double massive[size];
    parcing(massive, size);

    QElapsedTimer timer;
    timer.start();
    quickSort(massive, 0, size - 1);
    qint64 elapsed = timer.nsecsElapsed();
    return elapsed;
}


int Sorting::sort1000Items_quickSort()
{
    const int size = 1000;
    double massive[size];
    parcing(massive, size);

    QElapsedTimer timer;
    timer.start();
    quickSort(massive, 0, size - 1);
    qint64 elapsed = timer.nsecsElapsed();
    return elapsed;
}


int Sorting::sort5000Items_quickSort()
{
    const int size = 5000;
    double massive[size];
    parcing(massive, size);

    QElapsedTimer timer;
    timer.start();
    quickSort(massive, 0, size - 1);
    qint64 elapsed = timer.nsecsElapsed();
    return elapsed;
}


void Sorting::quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        double pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        double temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}


bool Sorting::compareWords(const QString& word1, const QString& word2) {
    return word1 > word2;
}


void Sorting::lex_quickSort(QString* words, int left, int right) {
    if (left < right)
    {
        int i = left, j = right;
        QString pivot = words[(left + right) / 2];

        while (i <= j) {
            while (compareWords(words[i], pivot)) i++;
            while (compareWords(pivot, words[j])) j--;

            if (i <= j) {
                QString temp = words[i];
                words[i] = words[j];
                words[j] = temp;
                i++;
                j--;
            }
        }

        if (left < j) lex_quickSort(words, left, j);
        if (i < right) lex_quickSort(words, i, right);
    }
}


int Sorting::sortWords1000()
{
    const int maxSize = 1000;
    QString words[maxSize];

    parcing_txt(words, maxSize);

    QElapsedTimer timer;
    timer.start();

    lex_quickSort(words, 0, maxSize - 1);

    qint64 elapsed = timer.nsecsElapsed();

    return elapsed;
}



int Sorting::sortWords500()
{
    const int maxSize = 500;
    QString words[maxSize];

    parcing_txt(words, maxSize);

    QElapsedTimer timer;
    timer.start();

    lex_quickSort(words, 0, maxSize - 1);

    qint64 elapsed = timer.nsecsElapsed();

    return elapsed;
}


int Sorting::sortWords5000()
{
    const int maxSize = 5000;
    QString words[maxSize];

    parcing_txt(words, maxSize);

    QElapsedTimer timer;
    timer.start();

    lex_quickSort(words, 0, maxSize - 1);

    qint64 elapsed = timer.nsecsElapsed();

    return elapsed;
}


void Sorting::next_page()
{
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams2);
}


void Sorting::back_to_diagrams()
{
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}


void Sorting::back_to_menu()
{
    ui->stackedWidget->setCurrentWidget(ui->page_menu);
}


void Sorting::choosed_pattern()
{
     ui->stackedWidget->setCurrentWidget(ui->page_main);
}


void Sorting::lexic_alone()
{
    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QLayoutItem *item;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    QVBoxLayout *layout4 = ui->verticalLayout_4;
    QLayoutItem *item4;

    while ((item4 = layout4->takeAt(0)) != nullptr)
    {
        if (item4->widget())
        {
            delete item4->widget();
        }
        delete item4;
    }

    int w500 = sortWords500();
    int w1000 =sortWords1000();
    int w5000 =sortWords5000();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Лексикографическая быстрая сортировка");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout3->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}


void Sorting::quick_alone()
{
    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QLayoutItem *item;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    QVBoxLayout *layout4 = ui->verticalLayout_4;
    QLayoutItem *item4;

    while ((item4 = layout4->takeAt(0)) != nullptr)
    {
        if (item4->widget())
        {
            delete item4->widget();
        }
        delete item4;
    }

    int w500 = sort500Items_quickSort();
    int w1000 =sort1000Items_quickSort();
    int w5000 =sort5000Items_quickSort();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Быстрая сортировка");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout3->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}


void Sorting::heap_alone()
{
    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QLayoutItem *item;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    QVBoxLayout *layout4 = ui->verticalLayout_4;
    QLayoutItem *item4;

    while ((item4 = layout4->takeAt(0)) != nullptr)
    {
        if (item4->widget())
        {
            delete item4->widget();
        }
        delete item4;
    }

    int w500 = sort500Items_heap();
    int w1000 =sort1000Items_heap();
    int w5000 =sort5000Items_heap();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Пирамидальная сортировка");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout3->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}


void Sorting::merge_alone()
{
    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QLayoutItem *item;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    QVBoxLayout *layout4 = ui->verticalLayout_4;
    QLayoutItem *item4;

    while ((item4 = layout4->takeAt(0)) != nullptr)
    {
        if (item4->widget())
        {
            delete item4->widget();
        }
        delete item4;
    }

    int w500 = sort500Items_merge();
    int w1000 =sort1000Items_merge();
    int w5000 =sort5000Items_merge();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Cортировка слиянием");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout3->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}


void Sorting::insert_alone()
{
    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QLayoutItem *item;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    QVBoxLayout *layout4 = ui->verticalLayout_4;
    QLayoutItem *item4;

    while ((item4 = layout4->takeAt(0)) != nullptr)
    {
        if (item4->widget())
        {
            delete item4->widget();
        }
        delete item4;
    }

    int w500 = sort500Items_insertion();
    int w1000 =sort1000Items_insertion();
    int w5000 =sort5000Items_insertion();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Cортировка вставкаим");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout3->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}


void Sorting::bubble_alone()
{
    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QLayoutItem *item;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    QVBoxLayout *layout4 = ui->verticalLayout_4;
    QLayoutItem *item4;

    while ((item4 = layout4->takeAt(0)) != nullptr)
    {
        if (item4->widget())
        {
            delete item4->widget();
        }
        delete item4;
    }

    int w500 = sort500Items_bubble();
    int w1000 =sort1000Items_bubble();
    int w5000 =sort5000Items_bubble();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Пузырьковая сортировка");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout3->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}


void Sorting::select_alone()
{
    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QLayoutItem *item;

    while ((item = layout3->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    QVBoxLayout *layout4 = ui->verticalLayout_4;
    QLayoutItem *item4;

    while ((item4 = layout4->takeAt(0)) != nullptr)
    {
        if (item4->widget())
        {
            delete item4->widget();
        }
        delete item4;
    }

    int w500 = sort500Items_select();
    int w1000 =sort1000Items_select();
    int w5000 =sort5000Items_select();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Сортировка выбором");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    layout3->addWidget(chartView);
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
}
