

#include <iostream>
#include "board.cpp"
#include "player.cpp"


int main() {
  
  Gameboard board;

  Player one;
  Player two;

  one.promptName();
  one.setLetter('x');

  two.promptName();
  two.setLetter('o');

  board.setPlayers(one.getName(), two.getName());
  board.printInfo();

  while (!board.isComplete()) {
    one.go();
    board.letterOn(one.getX(), one.getY(), one.getLetter());
    board.printInfo();

    board.checkAll();
    if (board.isComplete()) {
      board.winner();
      break;
    }
    two.go();
    board.letterOn(two.getX(), two.getY(), two.getLetter());
    board.checkAll();
    board.printInfo();
    if (board.isComplete()) {
      board.winner();
      break;
    }

    if (board.full()) {
      break;
    }
  }

  return 0;
}