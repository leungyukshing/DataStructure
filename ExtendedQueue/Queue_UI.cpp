#include <iostream>
#include "ExtendedQueue.hpp"
#include "ExtendedQueue.cpp"
using namespace std;

char get_command() {
  char cmd;
  bool waiting = true;
  
  while (waiting) {
    cout << "-----------------------------------" << endl;
    cout << "[1] Append a new element" << endl;
    cout << "[2] Serve the front element" << endl;
    cout << "[3] Retrieve the front element" << endl;
    cout << "[4] Check whether the queue is empty" << endl;
    cout << "[5] Check whether the stack is full" << endl;
    cout << "[6] Get the queue size" << endl;
    cout << "[7] Clear the queue" << endl;
    cout << "[8] Retrieve and serve the top element" << endl;
    cout << "[q] quit the program" << endl;
    cout << "Select command and press <Enter>:";
    cin >> cmd;
    cmd = tolower(cmd);
    if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4' || cmd == '5' || 
    cmd == '6' || cmd == '7' || cmd == '8' || cmd == 'q') {
      waiting = false;
    }
  }
  return cmd;
}

template <class Queue_entry>
bool do_command(char command, ExtendedQueue<Queue_entry> &qu) {
  switch (command) {
    case '1': 
      cout << "Enter the element you want to append:";
      Queue_entry ele0;
      cin >> ele0;
      if (qu.append(ele0) == OverFlow) {
        cout << "Warning: Queue full, lost number��" << endl;
      }
      else {
        cout << "Append succeed!" << endl;
      }
      break;
    case '2':
      if (qu.serve() == UnderFlow) {
        cout << "Warning: Queue empty!" << endl; 
        break;
      }
      cout << "Serve succeed!" << endl;
      break;
    case '3':
      Queue_entry ele2;
      if (qu.retrieve(ele2) == Success) {
        cout << "Front element is " << ele2 << endl;
      }
      else {
        cout << "Warning: Queue is empty!" << endl;
      }
      break;
    case '4':
      if (qu.empty()) {
        cout << "Queue is empty" << endl;
      }
      else {
        cout << "Queue is not empty" << endl;
      }
      break;
    case '5':
      if(qu.full()) {
        cout << "Queue is full" << endl;
      }
      else {
        cout << "Queue is not full" << endl;
      }
      break;
    case '6':
      cout << "The queue size is " << qu.size() << endl;
      break;
    case '7':
      qu.clear();
      cout << "Clear succeed!" << endl;
      break;
    case '8':
      Queue_entry ele7;
      if(qu.serve_and_retrieve(ele7) == Success) {
        cout << "Serve succeed! The front element is " << ele7 << endl;
      }
      else {
        cout << "Waring: The queue is empty!" << endl;
      }
      break;
    case 'q':
      cout << "Thank you for using!Bye!" << endl;
      return false;
  }
  return true;
}

int main() {
  ExtendedQueue<int> qu;
  cout << "Welcome to use ExtendedQueue!(int version)" << endl;
  while (do_command(get_command(), qu));
  return 0;
}