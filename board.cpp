#include <iostream>
#include <string>
using namespace std;


// board
class Gameboard {
  char gameSpace[4][4];
  bool complete;
  bool tied;
  string winnerDinner;
  string one;
  string two;


  public:
    Gameboard();
    void setPlayers(string oneIn, string twoIn);
    void letterOn(int x, int y, char letter);
    bool isComplete();
    bool full();
    string winner();

    bool checkInBounds(int x, int y);
    void checkRows();
    void checkColumns();
    void checkDiagonals();
    void checkAll();
    void printInfo();

};


Gameboard::Gameboard() {
  complete = false;
  for (int i = 0; i < 4;i++) {
    for (int j = 0; j < 4; j++) {
      gameSpace[i][j] = '-';
    }
  }
}

void Gameboard::setPlayers(string oneIn, string twoIn) {
  one = oneIn;
  two = twoIn;
}

void Gameboard::letterOn(int x, int y, char letter) {
  while (true) {
    if (gameSpace[x][y] == '-') {
      gameSpace[x][y] = letter;
      break;
    } else {
      bool valid = false;
      while (!valid) {
        cout << "Choose another (x,y) location: " << endl;
        cin >> x;
        cin >> y;
        valid = checkInBounds(x, y);
      }
    }
  }
}

bool Gameboard::isComplete() {
  return complete;
}

bool Gameboard::full() {
  int count = 0;
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++) {
      if (gameSpace[i][j] == 'x' || gameSpace[i][j] == 'o') {
        count += 1;
      }
    }
  }
  if (count == 16) {
    cout << "Tied game." << endl;
    return true;
  }
  return false;
}

bool Gameboard::checkInBounds(int x, int y) {
  return (x >= 0 && x < 4) && (y >= 0 && y < 4);

}

void Gameboard::checkRows() {
  for (int i = 0; i < 4; i ++){
    int x = 0;
    int o = 0;
    for (int j = 0; j < 4; j++){
      if (gameSpace[i][j] == 'x') {
        x += 1;
      } else if (gameSpace[i][j] == 'o'){
        o += 1;
      }
    }
    if (x == 4) {
      complete = true;
      winnerDinner = one;
    } else if (o == 4) {
      complete = true;
      winnerDinner = two;
    }
  }
}

void Gameboard::checkColumns() {
  for (int i = 0; i < 4; i ++){
    int x = 0;
    int o = 0;
    for (int j = 0; j < 4; j++){
      if (gameSpace[j][i] == 'x') {
        x += 1;
      } else if (gameSpace[j][i] == 'o'){
        o += 1;
      }
    }
    if (x == 4) {
      complete = true;
      winnerDinner = one;
    } else if (o == 4) {
      complete = true;
      winnerDinner = two;
    }
  }
}

void Gameboard::checkDiagonals() {
  int x = 0;
  int o = 0;

  for (int i = 0; i < 4; i++){
    if (gameSpace[i][i] == 'x') {
      x += 1;
    } else if (gameSpace[i][i] == 'o') {
      o += 1;
    }
  }

  if (x == 4) {
    complete = true;
    winnerDinner = one;
  } else if (o == 4) {
    complete = true;
    winnerDinner = two;
  }

  int x1 = 0;
  int y1 = 0;
  switch (gameSpace[0][3]) {
    case 'x':
      x1 += 1;
      break;
    case 'o':
      y1 += 1;
  }
  switch (gameSpace[1][2]) {
    case 'x':
      x1 += 1;
      break;
    case 'o':
      y1 += 1;
  }
  switch (gameSpace[2][1]) {
    case 'x':
      x1 += 1;
      break;
    case 'o':
      y1 += 1;
  }
    switch (gameSpace[3][0]) {
    case 'x':
      x1 += 1;
      break;
    case 'o':
      y1 += 1;
  }
  if (x1 == 4) {
    complete = true;
    winnerDinner = one;
  } else if (y1 == 4) {
    complete = true;
    winnerDinner = two;
  }  
}

void Gameboard::checkAll() {
  checkDiagonals();
  checkRows();
  checkColumns();
  
}

string Gameboard::winner() {
  cout << winnerDinner << " has won the game!" << endl;
  return winnerDinner;
}

void Gameboard::printInfo() {
  cout << "\n";
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << gameSpace[i][j] << " ";
    }
    cout << "\n";
  }
}




