#include <iostream>
#include "Key.hpp"
#include "../Timer/Timer.hpp"
#include "../Timer/Timer.cpp"
#include "../Random/Random.hpp"
#include "../Random/Random.cpp"
#include "../List/List.hpp"
#include "../List/List.cpp"
using namespace std;
Error_code sequential_search(const List<Record> &the_list,
               const Key &target, int &position) {
  int s = the_list.size();
  for (position = 0; position < s; position++) {
    Record data;
    the_list.retrieve(position, data);
    if (data == target)
      return Success;
  }
  return not_present;
}

void print_out(string comment, double t, int comp_ct, int searches) {
  float average;
  cout << comment << " Search Statistics: " << endl;
  cout << " Time for " << searches << " comparisons was " << t << endl;
  average = ((float) comp_ct) / ((float) searches);
  cout << " Average number of comparisons per search was " << average << endl;
}
void test_search(int searches, List<Record> &the_list) {
  int list_size = the_list.size();
  if (searches <= 0 || list_size < 0) {
    cout << "Exiting test: " << endl
         << "The number of searches must be positive." << endl
         << "The number of list entries must exceed 0." << endl;
         return;
  }
  int i, target, found_at;
  Key::comparisons = 0;
  Random number;
  Timer clock;
  for (i = 0; i < searches; i++) {
    target = 2 * number.random_integer(0, list_size - 1) + 1;
    //cout << "target is: " << target << endl;
    if (sequential_search(the_list, target, found_at) == not_present)
      cout << "Error.Failed to find expected target" << target << endl;
  }
  print_out("Successful", clock.elapsed_time(), Key::comparisons, searches);
  Key::comparisons = 0;
  clock.reset();
  for (i = 0; i < searches; i++) {
    target = 2 * number.random_integer(0, list_size);
    //cout << "target is: " << target << endl;
    if (sequential_search(the_list, target, found_at) == Success)
      cout << "Error.Found unexpected target" << target << " at " << found_at << endl;
  }
  print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches);
}

void intro() {
  cout << "Testing program for sequential search.\n"
       << "User options are:\n"
       << "[H]elp\n"
       << "[Q]uit\n"
       << "[F]ill list\n"
       << "[T]est sequential search" << endl;
}

int main() {
  intro();
  int n, searches = 100;
  char command = ' ';
  List<Record> the_list;
  while (command != 'q' && command != 'Q') {
    cout << "Enter a command of H, Q, F, T: " << flush;
    cin >> command;
    switch (command) {
      case 'h':
      case 'H':
        cout << "User options are:\n"
        << "[H]elp\n"
        << "[Q]uit\n"
        << "[F]ill list\n"
        << "[T]est sequential search" << endl;
        break;
      case 't':
      case 'T':
        test_search(searches, the_list);
        break;
      case 'f':
      case 'F':
        the_list.clear();
        cout << "Enter an upper bound n for the size of list entries: " << flush;
        cin >> n;
        for (int i = 1; i <= n; i += 2) {
          if (the_list.insert(the_list.size(), i) != Success)
            cout << "OverFlow in filling list." << endl;
        }
        cout << "The present list is: ";
        for (int i = 0; i < the_list.size(); i++) {
          int x;
          the_list.retrieve(i, x);
          cout << x << " ";
          cout << endl;
        }
        break;
    }
  }
  /*
  List<Record, 20> testlist;
  testlist.insert(0, 1);
  testlist.insert(1, 2);
  testlist.insert(2, 9);
  testlist.insert(3, 10);
  testlist.insert(4, 5);
  testlist.insert(5, 3);
  testlist.insert(6, 7);
  testlist.insert(7, 6);
  testlist.insert(8, 4);

  Key k(3);
  int pos;
  sequential_search(testlist, k, pos);
  cout << pos << endl;*/
}