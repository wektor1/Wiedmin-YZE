#pragma once

#include <QWidget>

namespace Ui {
class CharacterWindow;
}

class CharacterWindow : public QWidget {
  Q_OBJECT

public:
  explicit CharacterWindow(QWidget *parent = nullptr);
  ~CharacterWindow();

private:
  Ui::CharacterWindow *ui;
};
