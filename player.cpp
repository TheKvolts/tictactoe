

#include <iostream>
#include <string>
using namespace std;


// player
class Player {
  string name;
  char letter;
  int x;
  int y;

  public: 
    Player();
    void promptName();
    void setLetter(char letterIn);
    string getName();
    void go();

    char getX();
    char getY();
    char getLetter();

};
Player::Player() {
  name = "";
};

void Player::promptName() {
  cout << "What's your name?" << " ";
  cin >> name;
  cout << "Welcome, " << name << "." << endl;
};

void Player::setLetter(char letterIn) {
  letter = letterIn;
};

string Player::getName() {
  return name;
}

void Player::go() {
  
  cout << name << ", (x,y) coordinate: " << endl;
  cin >> x;
  cin >> y;
}

char Player::getX() {
  return x;
}

char Player::getY() {
  return y;
}
char Player::getLetter() {
  return letter;
}