#ifndef TERM_H
#define TERM_H
struct Term {
	int degree;
	double coefficient;
	Term::Term(int exponent, double scalar) {
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
#endif