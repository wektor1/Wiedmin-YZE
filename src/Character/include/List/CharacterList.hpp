#pragma once
#include "Data/CharacterData.hpp"
#include <QListWidget>
#include <vector>

class CharacterList : public QObject {
  Q_OBJECT

public:
  CharacterList();
  ~CharacterList();
  QListWidget *getListWidget() const { return charList; }

public slots:
  void addCharacter();
  void removeCharacters();

private:
  QListWidget *charList;
  std::vector<CharacterData> characters;
};