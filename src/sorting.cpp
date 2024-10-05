#include "../include/sorting.h"


Sorting::Sorting(Ui::MainWindow *ui, QObject *parent) :
    QObject(parent),
    ui(ui)
{
}


Sorting::~Sorting()
{

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

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("Выбором");
    auto set1 = new QBarSet("Пузырьком");
    auto set2 = new QBarSet("Вставками");
    auto set3 = new QBarSet("Пирамидальная");

    *set0 << select5000;
    *set1 << bubble5000;
    *set2 << insert5000;
    *set3 << heap5000;

    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

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

    *set01 << select1000;
    *set11 << bubble1000;
    *set21 << insert1000;
    *set31 << heap1000;

    series1->append(set01);
    series1->append(set11);
    series1->append(set21);
    series1->append(set31);

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

    *set02 << select500;
    *set12 << bubble500;
    *set22 << insert500;
    *set32 << heap500;

    series2->append(set02);
    series2->append(set12);
    series2->append(set22);
    series2->append(set32);

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

    chart->setMinimumSize(248, 380);
    chart1->setMinimumSize(248, 380);
    chart2->setMinimumSize(248, 380);

    QVBoxLayout *layout3 = ui->verticalLayout_3;
    QChartView *chartView3 = new QChartView(chart2);
    layout3->addWidget(chartView3);

    QVBoxLayout *layout2 = ui->verticalLayout_4;
    QChartView *chartView1 = new QChartView(chart1);
    layout2->addWidget(chartView1);

    QVBoxLayout *layout = ui->verticalLayout_5;
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


void Sorting::print(double massive[], int size)
{
    qDebug() << "\nМассив:\n";
    for (int i = 0; i < size; i++) {
        qDebug() << massive[i];
    }
    qDebug() << "\n";
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

/*
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
*/


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
    //print(massive, size);
}
/*

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
*/
/*
bool Sorting::compareWords(const char* word1, const char* word2)
{
    int i = 0;
    while (word1[i] != '\0' && word2[i] != '\0' && word1[i] == word2[i])
    {
        i++;
    }
    return word1[i] < word2[i];
}


void Sorting::lex_bubbleSort(char** words, int numWords)
{
    for (int i = 0; i < numWords - 1; i++)
    {
        for (int j = 0; j < numWords - i - 1; j++)
        {
            if (compareWords(words[j], words[j + 1]))
            {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}


void Sorting::sortWords(char** words, int numWords)
{
    lex_bubbleSort(words, numWords);

    std::cout << "Sorted words from the article:" << std::endl;
    for (int i = 0; i < numWords; i++)
    {
        std::cout << words[i] << std::endl;
    }
}
*/
