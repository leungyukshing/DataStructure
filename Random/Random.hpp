#ifndef RANDOM_H
#define RANDOM_H
class Random {
public:
  Random(bool pseudo = true);
  double random_real();
  int random_integer(int low, int high);
  int poisson(double mean);
private:
  int reseed();
  int seed, multiplier, add_on; // constants for use in arithmetic operations
};
#endif