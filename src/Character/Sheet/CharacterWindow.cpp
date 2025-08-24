#include "Sheet/CharacterWindow.hpp"
#include "ui_CharacterWindow.h"

CharacterWindow::CharacterWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::CharacterWindow) {
  ui->setupUi(this);
}

CharacterWindow::~CharacterWindow() { delete ui; }
