#include <iostream>
#include "Queens.hpp"
using namespace std;

void solve_from(Queens &configuration) {
  if (configuration.is_solved())
    configuration.print();
  else {
    for (int col = 0; col < configuration.board_size; col++) {
      if (configuration.unguarded(col)) {
        configuration.insert(col);
        solve_from(configuration); // Recursively continue to add queens.
        configuration.remove(col);
      }
    }
  }
}

void print_information() {
  cout << "This program determines all the ways to place n queens\n"
    << "on an n by n chessboard, where n <= " << max_board << endl;
}


int main() {
  int board_size;
  print_information();
  cout << "What is the size of the board?" << flush;
  cin >> board_size;
  if (board_size < 0 || board_size > max_board) {
    cout << "The number must be between 0 and " << max_board << endl;
  }
  else {
    Queens configuration(board_size); // Initialize empty configuration
    solve_from(configuration);
  }
  return 0;
}