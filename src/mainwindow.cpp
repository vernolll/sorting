#include "../include/mainwindow.h"
#include "../ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CSort = new Sorting(ui, this);

    connect(this, SIGNAL(on_pushButton_choic_clicked()), CSort, SLOT(choice()));
    connect(this, SIGNAL(on_pushButton_bubble_clicked()), CSort, SLOT(bubble()));
    connect(this, SIGNAL(on_pushButton_heap_clicked()), CSort, SLOT(heap()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
