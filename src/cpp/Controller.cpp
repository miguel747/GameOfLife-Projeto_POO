#include <iostream>

using namespace std;

#include "../include/Controller.h"
#include "../include/LifeGeneration.h"

void Controller::startGame() {

  while(true) {
      cout << "Select one option: " << endl << endl;
      cout << "[1] Cell revive " << endl;
      cout << "[2] Next generation - Default " << endl;
      cout << "[3] Next generation - HighLife" << endl;
      cout << "[4] Halt " << endl << endl;

    int menu = 0;

    cout << "Opcao: " ;

    cin >> menu;
    switch(menu) {
        case 1: revive(); break;
        case 2: NGDefault(); break;
        case 3: NGHighLife(); break;
        case 4: return;
     defaut: cout << endl << "Opcao invalida. Tente novamente." << endl << endl;
    }
  }
}

void Controller::revive() {
  int cols = game.getWidth();
  int rows = game.getHeight();
  int c, r = 0;

  cout << "Enter the cell collumn number (0 -- " << (cols-1) << "): " ;
  cin >> c;

  if(c == -1) return;

  while(c >= cols) {
     cout << "Enter the cell collumn number (0 -- " << (cols-1) << "). Type -1 to exit: " ;
     cin >> c;

     if(c == -1) return;
  }

  cout << "Enter the cell row number (0 -- " << (rows-1) << "): " ;
  cin >> r;

  if(rows == -1) return;

   while(r >= rows) {
     cout << "Enter the cell row number (0 -- " << (rows-1) << "). Type -1 to exit: " ;
     cin >> r;

     if(c == -1) return;
   }

   game.makeCellAlive(c, r);
   board.update(game);
}

void Controller::NGDefault(){
    game.SetGeneration(new Default());
    game.NewGeneration();
    board.update(game);
}

void Controller::NGHighLife(){
    game.SetGeneration(new HighLife());
    game.NewGeneration();
    board.update(game);
}
