#include <iostream>
#include "Queens.hpp"
using namespace std;

void Queens::insert(int col) {
  queen_square[count++][col] = true;
}

void Queens::remove(int col) {
  queen_square[--count][col] = false;
}

Queens::Queens(int size) {
  board_size = size;
  count = 0;
  for (int row = 0; row < board_size; row++) {
    for (int col = 0; col < board_size; col++) {
      queen_square[row][col] = false;
    }
  }
}

bool Queens::unguarded(int col) const {
  int i;
  bool ok = true; // turns false if we find a queen in column or diagonal
  for (i = 0; ok && i < count; i++) {
    ok = !queen_square[i][col]; // Check upper part of column
  }
  for (i = 1; ok && count - i >= 0 && col - i >= 0; i++) {
    ok = !queen_square[count - i][col - i]; // ck upper-left diagonal
  }
  for (i = 1; ok && count- i >= 0 && col + i < board_size; i++) {
    ok = !queen_square[count - i][col + i]; // Check upper-right diagonal
  }
  return ok;
}

bool Queens::is_solved() const{
  return (count == board_size);

}
void Queens::print() const {
  int row, col;
  for (col = 0; col < board_size; col++) {
    cout << "--";
  }
  cout << "--\n";
  for (row = 0; row < board_size; row++) {
    for (col = 0; col < board_size;col++) {
      if (queen_square[row][col]) {
        cout << "Q";
      }
      else {
        cout << ".";
      }
    }
    cout << endl;
  }
}