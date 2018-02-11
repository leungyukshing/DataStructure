#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "../LinkedStack/LinkedStack.hpp"
#include "../LinkedStack/LinkedStack.cpp"
#include "../LinkedQueue/LinkedQueue.hpp"
#include "../LinkedQueue/LinkedQueue.cpp"

struct Term {
  int degree;
  double coefficient;
  Term() {}
  Term(int exponent, double scalar) {
    degree = exponent;
    coefficient = scalar;
  }
  bool operator == (const Term &original) {
    if (degree == original.degree && coefficient == original.coefficient) {
      return true;
    }
    return false;
  }
};

class Polynomial: private LinkedQueue<Term> {
public:
  void read();
  void print();
  void equals_sum(Polynomial p, Polynomial q);
  void equals_difference(Polynomial p, Polynomial q);
  void equals_product(Polynomial p, Polynomial q);
  Error_code equals_quotient(Polynomial p, Polynomial q);
  int degree() const;
private:
  void mult_term(Polynomial p, Term t);
};
#endif