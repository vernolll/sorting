#include "../include/sorting.h"


Sorting::Sorting(Ui::MainWindow *ui, QObject *parent) :
    QObject(parent),
    ui(ui)
{
}


Sorting::~Sorting()
{
}


void Sorting::parcing_txt(char** words, int maxSize)
{
    std::ifstream file("D:/university/3 semestr/laba1_algos/build/1984-george-orwell.txt", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: D:/university/3 semestr/laba1_algos/build/1984-george-orwell.txt" << std::endl;
        return;
    }

    std::string line;
    int currentIndex = 0;

    while (std::getline(file, line) && currentIndex < maxSize) {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
        std::u16string utf16Line = converter.from_bytes(line);

        std::wistringstream wiss(std::wstring(utf16Line.begin(), utf16Line.end()));
        std::wstring word;

        while (wiss >> word) {
            const char* cstr = reinterpret_cast<const char*>(word.c_str());
            if (currentIndex < maxSize) {
                words[currentIndex] = const_cast<char*>(cstr);
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
    QList<long long> items_select = sortItems_select();
    QList<long long> items_bubble = sortItems_bubble();
    QList<long long> items_insertion = sortItems_insertion();
    QList<long long> items_heap = sortItems_heap();
    QList<long long> items_merge = sortItems_merge();
    QList<long long> items_quick = sortItems_quickSort();
    QList<long long> items_words = sortWords();

    QBarSeries *series = new QBarSeries;

    auto set0 = new QBarSet("Выбором");
    auto set1 = new QBarSet("Пузырьком");
    auto set2 = new QBarSet("Вставками");
    auto set3 = new QBarSet("Пирамидальная");
    auto set4 = new QBarSet("Слиянием");
    auto set5 = new QBarSet("Быстрая");
    auto set6 = new QBarSet("Лексикографическая");

    *set0 << items_select[2];
    *set1 << items_bubble[2];
    *set2 << items_insertion[2];
    *set3 << items_heap[2];
    *set4 << items_merge[2];
    *set5 << items_quick[2];
    *set6 << items_words[2];

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

    *set01 << items_select[1];
    *set11 << items_bubble[1];
    *set21 << items_insertion[1];
    *set31 << items_heap[1];
    *set41 << items_merge[1];
    *set51 << items_quick[1];
    *set61 << items_words[1];

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

    *set02 << items_select[0];
    *set12 << items_bubble[0];
    *set22 << items_insertion[0];
    *set32 << items_heap[0];
    *set42 << items_merge[0];
    *set52 << items_quick[0];
    *set62 << items_words[0];

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

    ui->pushButton_next->show();
}


QVector<qint64> Sorting::sortItems(std::function<void(double*, int)> sortFunction)
{
    const QVector<int>& sizes = {500, 1000, 500};
    QVector<qint64> arr;

    for (int size : sizes) {
        double* massive = new double[size];
        parcing(massive, size);

        QElapsedTimer timer;
        timer.start();
        sortFunction(massive, size);
        qint64 elapsed = timer.nsecsElapsed();
        arr.append(elapsed);

        delete[] massive;
    }

    return arr;
}


QVector<qint64> Sorting::sortItems_select()
{
    return sortItems([this](double* massive, int size) { choice(massive, size); });
}


QVector<qint64> Sorting::sortItems_bubble()
{
    return sortItems([this](double* massive, int size) { bubble(massive, size); });
}


void Sorting::choice(double massive[], int size)
{
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
}


void Sorting::bubble(double massive[], int size)
{
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
}


QVector<qint64> Sorting::sortItems_insertion()
{
    return sortItems([this](double* massive, int size) { insertion(massive, size); });
}


void Sorting::insertion(double massive[], int size)
{
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
}


QVector<qint64> Sorting::sortItems_merge()
{
    return sortItems([this](double* massive, int size) { mergeSort(massive, 0, size - 1); });
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


QVector<qint64> Sorting::sortItems_heap()
{
    return sortItems([this](double* massive, int size) { heap(massive, size); });
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

void Sorting::heap(double massive[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(massive, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        double temp = massive[0];
        massive[0] = massive[i];
        massive[i] = temp;
        heapify(massive, i, 0);
    }
}


QVector<qint64> Sorting::sortItems_quickSort()
{
    return sortItems([this](double* massive, int size) { quickSort(massive, 0, size - 1); });
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
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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


bool Sorting::compareWords(const char* word1, const char* word2)
{
    while (*word1 && *word2 && *word1 == *word2)
    {
        ++word1;
        ++word2;
    }

    return (*word1 - *word2) > 0;
}


void Sorting::lex_quickSort(char** words, int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        const char* pivot = words[(left + right) / 2];

        while (i <= j)
        {
            while (compareWords(words[i], pivot)) i++;
            while (compareWords(pivot, words[j])) j--;

            if (i <= j)
            {
                char* temp = words[i];
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


QVector<qint64> Sorting::sortWords()
{
    QVector<qint64> arr;

    const int size = 500;
    char* massive[size];
    parcing_txt(massive, size);

    QElapsedTimer timer;
    timer.start();
    lex_quickSort(massive, 0, size - 1);
    qint64 elapsed = timer.nsecsElapsed();
    arr.append(elapsed);

    const int size1 = 1000;
    char* massive1[size];
    parcing_txt(massive1, size1);

    QElapsedTimer timer1;
    timer1.start();
    lex_quickSort(massive1, 0, size1 - 1);
    qint64 elapsed1 = timer1.nsecsElapsed();
    arr.append(elapsed1);

    const int size2 = 5000;
    char* massive2[size2];
    parcing_txt(massive2, size2);

    QElapsedTimer timer2;
    timer2.start();
    lex_quickSort(massive1, 0, size1 - 1);
    qint64 elapsed2 = timer2.nsecsElapsed();
    arr.append(elapsed2);

    return arr;
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
    ui->stackedWidget->setCurrentWidget(ui->page_main);
}


void Sorting::sortingHelper(std::function<QList<long long>()> sortingFunction, const QString& title)
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

    QList<long long> items = sortingFunction();
    long long w500 = items[0];
    long long w1000 = items[1];
    long long w5000 = items[2];

    auto set0 = new QBarSet("500");
    auto set1 = new QBarSet("1к");
    auto set2 = new QBarSet("5к");

    *set0 << w500;
    *set1 << w1000;
    *set2 << w5000;

    QBarSeries *series = new QBarSeries;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
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
    ui->pushButton_next->hide();
}


void Sorting::lexic_alone()
{
    sortingHelper([this]() { return sortWords(); }, "Лексикографическая быстрая сортировка");
}


void Sorting::quick_alone()
{
    sortingHelper([this]() { return sortItems_quickSort(); }, "Быстрая сортировка");
}


void Sorting::heap_alone()
{
    sortingHelper([this]() { return sortItems_heap(); }, "Пирамидальная сортировка");
}


void Sorting::merge_alone()
{
    sortingHelper([this]() { return sortItems_merge(); }, "Сортировка слиянием");
}


void Sorting::insert_alone()
{
    sortingHelper([this]() { return sortItems_insertion(); }, "Сортировка выставками");
}


void Sorting::bubble_alone()
{
    sortingHelper([this]() { return sortItems_bubble(); }, "Сортировка пузырьком");
}


void Sorting::select_alone()
{
    sortingHelper([this]() { return sortItems_select(); }, "Сортировка выбором");
}
