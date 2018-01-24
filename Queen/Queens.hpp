#ifndef QUEEN_H
#define QUEEN_H
const int max_board = 30;
class Queens {
public:
  Queens(int size);
  bool is_solved() const;
  void print() const;
  bool unguarded(int col) const;
  void insert(int col);
  void remove(int col);
  int board_size; // dimension of board = maximum number of queens
private:
  int count;
  bool queen_square[max_board][max_board];
};
#endif