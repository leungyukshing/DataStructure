#include "String.hpp"
#include <iostream>
#include <list>
using namespace std;

int main() {
  String s1 = "hello";
  String s3 = "world";
  String s4 = "lo";
  /*String s2 = s1;
  char cstr[] = "this is cstr";
  String s3(cstr);
  write(s3);

  list<char> l1;
  l1.push_back('l');
  l1.push_back('y');
  l1.push_back('c');
  String s4(l1);
  write(s4);

  cout << s4.c_str() << endl;*/
  //strcat(s1, s3);
  int ter;
  String s = read_in(ter);
  cout << s.c_str() << endl;
  cout << strstr(s1, s4) << endl;
  cout << ter << endl;
  return 0;
}