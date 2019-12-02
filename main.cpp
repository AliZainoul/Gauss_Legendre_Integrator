#include <vector>
#include <iostream>
#include <cmath>

#include "data_Gauss_Legendre.hpp"

using namespace std;

double polynom(double x)
{
  return 3.0*pow(x,5) + 2.0*pow(x,2)+5;
}


int main()
{

  // copy rules for order 20 in STL vectors for further use
  vector<double> data;

  unsigned int nn = 20;
  data.resize(nn);

  copy(Quad1D_10, Quad1D_10+nn, data.begin());

  vector<double> nodes(nn/2);
  vector<double> weights(nn/2);

  for(int ii=0; ii<nn; ii=ii+2)
  {
    nodes.push_back(data[ii]);
    weights.push_back(data[ii+1]);
  }

  double value = 0.0;
  for(int ii=0; ii<nodes.size(); ++ii){
    value += weights[ii]*polynom(nodes[ii]);
  }

  double exact_value = 34.0/3.0;
  cout << "The error between exact and computed values is: " << abs(value-exact_value) << endl;
  return 0;
}
