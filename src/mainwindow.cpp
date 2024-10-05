#include "../include/mainwindow.h"
#include "../ui/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CSort = new Sorting(ui, this);

    ui->stackedWidget->setCurrentWidget(ui->page_main);

    connect(this, SIGNAL(on_pushButton_all_kind_clicked()), CSort, SLOT(all_kind()));
    connect(this, SIGNAL(on_pushButton_next_clicked()), CSort, SLOT(next_page()));
    connect(this, SIGNAL(on_pushButton_clicked()), CSort, SLOT(back_to_diagrams()));
    connect(this, SIGNAL(on_pushButton_menu_clicked()), CSort, SLOT(back_to_menu()));
    connect(this, SIGNAL(on_pushButton_pattern_clicked()), CSort, SLOT(choosed_pattern()));
    connect(this, SIGNAL(on_pushButton_lexic_clicked()), CSort, SLOT(lexic_alone()));
    connect(this, SIGNAL(on_pushButton_quick_clicked()), CSort, SLOT(quick_alone()));
    connect(this, SIGNAL(on_pushButton_heap_clicked()), CSort, SLOT(heap_alpne()));
    connect(this, SIGNAL(on_pushButton_merge_clicked()), CSort, SLOT(merge_alone()));
    connect(this, SIGNAL(on_pushButton_insertion_clicked()), CSort, SLOT(insert_alone()));
    connect(this, SIGNAL(on_pushButton_bubble_clicked()), CSort, SLOT(bubble_alone()));
    connect(this, SIGNAL(on_pushButton_choic_clicked()), CSort, SLOT(select_alone()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
