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

void Sorting::choice()
{
    const int size = 5000;
    double massive[size];

    parcing(massive, size);

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

    print(massive, size);
}

void Sorting::print(double massive[], int size)
{
    qDebug() << "\nМассив:\n";
    for (int i = 0; i < size; i++) {
        qDebug() << massive[i];
    }
    qDebug() << "\n";
}


void Sorting::bubble()
{
    const int size = 5000;
    double massive[size];

    parcing(massive, size);

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
    print(massive, size);
}


void Sorting::insertion()
{
    const int size = 5000;
    double massive[size];

    parcing(massive, size);

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

    print(massive, size);
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

void Sorting::heapify(double massive[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && massive[l] > massive[largest])
        largest = l;

    if (r < size && massive[r] > massive[largest])
        largest = r;

    if (largest != i) {
        double temp = massive[i];
        massive[i] = massive[largest];
        massive[largest] = temp;
        heapify(massive, size, largest);
    }
}


void Sorting::heap()
{
    const int size = 5000;
    double massive[size];

    parcing(massive, size);

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(massive, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        double temp = massive[0];
        massive[0] = massive[i];
        massive[i] = temp;
        heapify(massive, i, 0);
    }

    print(massive, size);
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
