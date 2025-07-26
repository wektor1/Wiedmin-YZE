#pragma once

#include <QListWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void addCharacter();
  void removeCharacters();

private:
  Ui::MainWindow *ui;
  QListWidget *charList;
  int n{0};
};
