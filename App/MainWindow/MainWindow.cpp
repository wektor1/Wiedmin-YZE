#include "MainWindow.hpp"
#include "./ui_MainWindow.h"
#include <algorithm>
#include <set>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    charList = new QListWidget;
    charList->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->charArea->setWidget(charList);
    connect(ui->addCharButton, &QPushButton::clicked, this,
        &MainWindow::addCharacter);
    connect(ui->deleteCharsButton, &QPushButton::clicked, this,
        &MainWindow::removeCharacters);

    // connect(charList, &QListWidget::itemClicked, this, QListWidget::setCurrentItem);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete charList;
}

void MainWindow::addCharacter()
{
    QString label { "added char: " };
    label.push_back(QString::number(++n));
    charList->addItem(label);
}

void MainWindow::removeCharacters()
{
    std::set<int> rows {};
    for (auto character : charList->selectedItems()) {
        rows.insert(charList->row(character));
    }
    std::for_each(rows.rbegin(), rows.rend(), [this](auto row) {
        charList->takeItem(row);
    });
}
