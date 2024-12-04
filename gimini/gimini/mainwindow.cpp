#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QFile"
#include "filedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createMenus() {
    QMenuBar *topbar = new QMenuBar(this);

    QAction *openact = new QAction(tr("Open file"));
    connect(openact, &QAction::triggered, this, [=](){FileDialog::open(this);});


    QAction *saveact = new QAction(tr("Save to file"));

    QMenu *filebar = menuBar()->addMenu(tr("File"));
    filebar->addAction(openact);
    filebar->addAction(saveact);


    topbar->addMenu(filebar);
}
