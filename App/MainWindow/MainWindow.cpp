#include "MainWindow.hpp"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  charList = new QListWidget;
  ui->charArea->setWidget(charList);
  connect(ui->addCharButton, &QPushButton::clicked, this,
          &MainWindow::addCharacter);
}

MainWindow::~MainWindow() {
  delete ui;
  delete charList;
}

void MainWindow::addCharacter() {
  QString label{"added char"};
  charList->addItem(label);
}
