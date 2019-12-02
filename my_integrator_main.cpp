#include <vector>
#include <iostream>
#include <cmath>
#include "my_integrator.hpp"
#include "data_Gauss_Legendre.hpp"

using namespace std;

double polynom(double x)
{
  return 3.0*pow(x,5) + 2.0*pow(x,2)+5;
}

int main()
{
  double exact_value = 34.0/3.0;
  cout << "The error between exact and compiuted values is: " << abs(exact_value-integrator(polynom)) << endl;
  return 0;
}
