#include "List/CharacterList.hpp"

CharacterList::CharacterList() {
  charList = new QListWidget;
  charList->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

CharacterList::~CharacterList() { delete charList; }

void CharacterList::addCharacter() {
  QString label{"New Character"};
  charList->addItem(label);
  characters.emplace_back(label.toStdString());
}

void CharacterList::removeCharacters() {
  const auto selectedCharacters = charList->selectedItems();
  std::set<int> rows{};
  for (const auto &character : selectedCharacters) {
    rows.insert(charList->row(character));
  }
  std::for_each(rows.rbegin(), rows.rend(),
                [this](auto row) { charList->takeItem(row); });
}