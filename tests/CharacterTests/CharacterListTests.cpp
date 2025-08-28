#include "List/CharacterList.hpp"
#include <QTest>

class CharacterListTests : public QObject {
  Q_OBJECT

private slots:
  void initTestCase() { qDebug("Called before everything else."); }

  void myFirstTest() {
    CharacterList charList;
    QCOMPARE(charList.getListWidget()->count(), 0);
    charList.addCharacter();
    QCOMPARE(charList.getListWidget()->count(), 1);
    charList.addCharacter();
    QCOMPARE(charList.getListWidget()->count(), 2);
  }

  void cleanupTestCase() { qDebug("Called after test."); }
};

QTEST_MAIN(CharacterListTests)
#include "CharacterListTests.moc"