#include "MainWindow.hpp"
#include "./ui_MainWindow.h"
#include <algorithm>
#include <set>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->charArea->setWidget(charList.getListWidget());
  connect(ui->addCharButton, &QPushButton::clicked, &charList,
          &CharacterList::addCharacter);
  connect(ui->deleteCharsButton, &QPushButton::clicked, &charList,
          &CharacterList::removeCharacters);
}

MainWindow::~MainWindow() { delete ui; }
