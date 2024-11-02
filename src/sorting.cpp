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
    QVector<QPair<QString, std::function<QList<long long>()>> > sortingMethods;

    sortingMethods.push_back(qMakePair(QString("dВыбором"), [this]() { return sortItems_select<double>(); }));
    sortingMethods.push_back(qMakePair(QString("Пузырьком"), [this]() { return sortItems_bubble<double>(); }));
    sortingMethods.push_back(qMakePair(QString("Вставками"), [this]() { return sortItems_insertion<double>(); }));
    sortingMethods.push_back(qMakePair(QString("Пирамидальная"), [this]() { return sortItems_heap<double>(); }));
    sortingMethods.push_back(qMakePair(QString("Слиянием"), [this]() { return sortItems_merge<double>(); }));
    sortingMethods.push_back(qMakePair(QString("Быстрая"), [this]() { return sortItems_quickSort<double>(); }));

    sortingMethods.push_back(qMakePair(QString("cВыбором"), [this]() { return sortItems_select<char*>(); }));
    sortingMethods.push_back(qMakePair(QString("Пузырьком"), [this]() { return sortItems_bubble<char*>(); }));
    sortingMethods.push_back(qMakePair(QString("Вставками"), [this]() { return sortItems_insertion<char*>(); }));
    sortingMethods.push_back(qMakePair(QString("Пирамидальная"), [this]() { return sortItems_heap<char*>(); }));
    sortingMethods.push_back(qMakePair(QString("Слиянием"), [this]() { return sortItems_merge<char*>(); }));
    sortingMethods.push_back(qMakePair(QString("Быстрая"), [this]() { return sortItems_quickSort<char*>(); }));

    QStringList chartTitles = {"500 элементов", "1к элементов", "5к элементов"};

    QVector<QVBoxLayout*> layouts = {
        ui->verticalLayout_500_double,
        ui->verticalLayout_500_char,
        ui->verticalLayout_1k_double,
        ui->verticalLayout_1k_char,
        ui->verticalLayout_5k_double,
        ui->verticalLayout_5k_char
    };

    for (auto layout : layouts)
    {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr)
        {
            if (item->widget()) delete item->widget();
            delete item;
        }
    }

    int layoutIndex = 0;

    for (int sizeIndex = 0; sizeIndex < 3; ++sizeIndex)
    {
        for (int typeIndex = 0; typeIndex < 2; ++typeIndex)
        {
            QBarSeries *series = new QBarSeries;

            for (int methodIndex = 0; methodIndex < 6; ++methodIndex)
            {
                QList<long long> times;
                if (typeIndex == 0)
                {
                    times = sortingMethods[methodIndex].second();
                }
                else
                {
                    times = sortingMethods[methodIndex + 6].second();
                }

                auto *barSet = new QBarSet(sortingMethods[methodIndex + typeIndex * 6].first);
                *barSet << times[sizeIndex];
                series->append(barSet);
            }

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle(chartTitles[sizeIndex]);
            chart->setAnimationOptions(QChart::SeriesAnimations);

            QBarCategoryAxis *axisX = new QBarCategoryAxis();
            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

            QValueAxis *axisY = new QValueAxis();
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);

            if (typeIndex == 0)
            {
                layouts[layoutIndex]->addWidget(new QChartView(chart));
            }
            else
            {
                layouts[layoutIndex]->addWidget(new QChartView(chart));
            }

            layoutIndex++;
        }
    }

    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
    ui->pushButton_next->show();
}


void Sorting::displaySortingResults(
    const std::vector<std::function<QList<long long>()>>& sortingFunctions,
    const QStringList& titles)
{
    QVBoxLayout *layoutDouble = ui->verticalLayout_500_double;
    QVBoxLayout *layoutChar = ui->verticalLayout_500_char;
    QLayoutItem *item;

    while ((item = layoutDouble->takeAt(0)) != nullptr)
    {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    while ((item = layoutChar->takeAt(0)) != nullptr)
    {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }

    QHBoxLayout *hLayoutDouble = new QHBoxLayout();
    QHBoxLayout *hLayoutChar = new QHBoxLayout();

    if (sortingFunctions.size() >= 1)
    {
        auto chartViewDouble = sortingHelper(sortingFunctions[0], titles[0]);
        hLayoutDouble->addWidget(chartViewDouble);
    }

    if (sortingFunctions.size() >= 2)
    {
        auto chartViewChar = sortingHelper(sortingFunctions[1], titles[1]);
        hLayoutChar->addWidget(chartViewChar);
    }

    layoutDouble->addLayout(hLayoutDouble);
    layoutChar->addLayout(hLayoutChar);

    ui->stackedWidget->setCurrentWidget(ui->page_diagrams);
    ui->pushButton_next->hide();
}

template<typename T>
QVector<qint64> Sorting::sortItems(std::function<void(T*, int)> sortFunction)
{
    const QVector<int>& sizes = {500, 1000, 500};
    QVector<qint64> arr;

    for (int size : sizes) {
        T* massive = new T[size];

        if constexpr (std::is_same<T, double>::value)
        {
            parcing(massive, size);
        } else if constexpr (std::is_same<T, char*>::value)
        {
            parcing_txt(massive, size);
        }

        QElapsedTimer timer;
        timer.start();
        sortFunction(massive, size);
        qint64 elapsed = timer.nsecsElapsed();
        arr.append(elapsed);

        delete[] massive;
    }

    return arr;
}

template<typename T>
QVector<qint64> Sorting::sortItems_select()
{
    if constexpr (std::is_same<T, double>::value)
    {
        return sortItems<double>([this](double* massive, int size) { choice(massive, size); });
    }
    else if constexpr (std::is_same<T, char*>::value)
    {
        return sortItems<char*>([this](char** massive, int size) { choice(massive, size); });
    }
    else
    {
        static_assert(std::is_same<T, double>::value || std::is_same<T, char*>::value, "Unsupported type for sortItems_select");
    }
}


void Sorting::select_alone()
{
    std::vector<std::function<QList<long long>()>> sortingFunctions =
        {
            [this]() -> QList<long long> { return sortItems_select<double>(); },
            [this]() -> QList<long long> { return sortItems_select<char*>(); }
        };

    QStringList titles =
        {
            "Сортировка выбором для чисел (double)",
            "Сортировка выбором для строк (char*)"
        };

    displaySortingResults(sortingFunctions, titles);
}


template<typename T>
void Sorting::choice(T* massive, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if constexpr (std::is_same<T, double>::value)
            {
                if (massive[j] < massive[minIndex])
                {
                    minIndex = j;
                }
            } else if constexpr (std::is_same<T, char*>::value)
            {
                if (strcmp(massive[j], massive[minIndex]) < 0)
                {
                    minIndex = j;
                }
            }
        }

        T temp = massive[minIndex];
        massive[minIndex] = massive[i];
        massive[i] = temp;
    }
}

template<typename T>
QVector<qint64> Sorting::sortItems_bubble()
{
    if constexpr (std::is_same<T, double>::value)
    {
        return sortItems<double>([this](double* massive, int size) { bubble(massive, size); });
    }
    else if constexpr (std::is_same<T, char*>::value)
    {
        return sortItems<char*>([this](char** massive, int size) { bubble(massive, size); });
    }
    else
    {
        static_assert(std::is_same<T, double>::value || std::is_same<T, char*>::value, "Unsupported type for sortItems_select");
    }
}

template<typename T>
void Sorting::bubble(T* massive, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (massive[j] > massive[j + 1])
            {
                T temp = massive[j];
                massive[j] = massive[j + 1];
                massive[j + 1] = temp;
            }
        }
    }
}

void Sorting::bubble_alone()
{
    std::vector<std::function<QList<long long>()>> sortingFunctions =
        {
            [this]() -> QList<long long> { return sortItems_bubble<double>(); },
            [this]() -> QList<long long> { return sortItems_bubble<char*>(); }
        };

    QStringList titles =
        {
            "Сортировка пузырьком для чисел (double)",
            "Сортировка пузырьком для строк (char*)"
        };

    displaySortingResults(sortingFunctions, titles);
}

template<typename T>
QVector<qint64> Sorting::sortItems_insertion()
{
    if constexpr (std::is_same<T, double>::value)
    {
        return sortItems<double>([this](double* massive, int size) { insertion(massive, size); });
    }
    else if constexpr (std::is_same<T, char*>::value)
    {
        return sortItems<char*>([this](char** massive, int size) { insertion(massive, size); });
    }
    else
    {
        static_assert(std::is_same<T, double>::value || std::is_same<T, char*>::value, "Unsupported type for sortItems_select");
    }
}

template<typename T>
void Sorting::insertion(T* massive, int size)
{
    T key;
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


void Sorting::insert_alone()
{
    std::vector<std::function<QList<long long>()>> sortingFunctions =
        {
            [this]() -> QList<long long> { return sortItems_insertion<double>(); },
            [this]() -> QList<long long> { return sortItems_insertion<char*>(); }
        };

    QStringList titles =
        {
            "Сортировка вставками для чисел (double)",
            "Сортировка вставками для строк (char*)"
        };

    displaySortingResults(sortingFunctions, titles);
}

template<typename T>
QVector<qint64> Sorting::sortItems_heap()
{
    if constexpr (std::is_same<T, double>::value)
    {
        return sortItems<double>([this](double* massive, int size) { heap(massive, size); });
    }
    else if constexpr (std::is_same<T, char*>::value)
    {
        return sortItems<char*>([this](char** massive, int size) { heap(massive, size); });
    }
    else
    {
        static_assert(std::is_same<T, double>::value || std::is_same<T, char*>::value, "Unsupported type for sortItems_select");
    }
}

template<typename T>
void Sorting::heapify(T* massive, int size, int i)
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
        T temp = massive[i];
        massive[i] = massive[largest];
        massive[largest] = temp;
        heapify(massive, size, largest);
    }
}

template<typename T>
void Sorting::heap(T* massive, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(massive, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        T temp = massive[0];
        massive[0] = massive[i];
        massive[i] = temp;
        heapify(massive, i, 0);
    }
}


void Sorting::heap_alone()
{
    std::vector<std::function<QList<long long>()>> sortingFunctions =
        {
            [this]() -> QList<long long> { return sortItems_insertion<double>(); },
            [this]() -> QList<long long> { return sortItems_insertion<char*>(); }
        };

    QStringList titles =
        {
            "Пирамидальная сортировка для чисел (double)",
            "Пирамидальная сортировка для строк (char*)"
        };

    displaySortingResults(sortingFunctions, titles);
}

template<typename T>
QVector<qint64> Sorting::sortItems_merge()
{
    if constexpr (std::is_same<T, double>::value)
    {
        return sortItems<double>([this](double* massive, int size) { mergeSort(massive, 0, size - 1); });
    }
    else if constexpr (std::is_same<T, char*>::value)
    {
        return sortItems<char*>([this](char** massive, int size) { mergeSort(massive, 0, size - 1); });
    }
    else
    {
        static_assert(std::is_same<T, double>::value || std::is_same<T, char*>::value, "Unsupported type for sortItems_merge");
    }
}

template<typename T>
void Sorting::merge_(T* massive, int l, int m, int r)
{
    int i, j, k;
    // вычисление длины левой части массива
    int n1 = m - l + 1;
    // вычисление длины правой части массива
    int n2 = r - m;

    T* L = new T[n1];
    T* R = new T[n2];

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

template<typename T>
void Sorting::mergeSort(T* massive, int l, int r)
{
    const int threshold = 1000;  // Порог для однопоточной сортировки
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Используем многопоточность только для крупных подмассивов
        if (r - l > threshold)
        {
            // Запускаем левую часть в отдельном потоке
            auto leftFuture = std::async(std::launch::async, &Sorting::mergeSort<T>, this, massive, l, m);

            // Выполняем правую часть текущим потоком
            mergeSort(massive, m + 1, r);

            // Ожидаем завершения левой части
            leftFuture.get();
        }
        else
        {
            // Однопоточная сортировка для небольших массивов
            mergeSort(massive, l, m);
            mergeSort(massive, m + 1, r);
        }

        // Слияние отсортированных подмассивов
        merge_(massive, l, m, r);
    }
}


void Sorting::merge_alone()
{
    std::vector<std::function<QList<long long>()>> sortingFunctions =
        {
            [this]() -> QList<long long> { return sortItems_merge<double>(); },
            [this]() -> QList<long long> { return sortItems_merge<char*>(); }
        };

    QStringList titles =
        {
            "Сортировка слиянием для чисел (double)",
            "Сортировка слиянием для строк (char*)"
        };

    displaySortingResults(sortingFunctions, titles);
}


template<typename T>
QVector<qint64> Sorting::sortItems_quickSort()
{
    if constexpr (std::is_same<T, double>::value)
    {
        return sortItems<double>([this](double* massive, int size) { quickSort(massive, 0, size - 1); });
    }
    else if constexpr (std::is_same<T, char*>::value)
    {
        return sortItems<char*>([this](char** massive, int size) { quickSort(massive, 0, size - 1); });
    }
    else
    {
        static_assert(std::is_same<T, double>::value || std::is_same<T, char*>::value, "Unsupported type for sortItems_quickSort");
    }
}

template<typename T>
void Sorting::quickSort(T* arr, int low, int high)
{
    const int threshold = 1000; // Порог для включения многопоточности

    if (low < high)
    {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;

        // Если размер подмассива больше порога, выполняем многопоточную сортировку
        if (high - low > threshold)
        {
            auto leftFuture = std::async(std::launch::async, &Sorting::quickSort<T>, this, arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
            leftFuture.get(); // Ждем завершения левой части
        }
        else
        {
            // Однопоточная сортировка для небольших массивов
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }
}

void Sorting::quick_alone()
{
    std::vector<std::function<QVector<qint64>()>> sortingFunctions =
        {
            [this]() -> QVector<qint64> { return sortItems_quickSort<double>(); },
            [this]() -> QVector<qint64> { return sortItems_quickSort<char*>(); }
        };

    QStringList titles =
        {
            "Быстрая сортировка для чисел (double)",
            "Быстрая сортировка для строк (char*)"
        };

    displaySortingResults(sortingFunctions, titles);
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


void Sorting::next_diagram()
{
    ui->stackedWidget->setCurrentWidget(ui->page_diagrams3);
}


QChartView* Sorting::sortingHelper(std::function<QList<long long>()> sortingFunction, const QString& title)
{
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
    return chartView;
}
