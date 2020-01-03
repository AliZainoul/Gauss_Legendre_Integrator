#include <vector>
#include "data_Gauss_Legendre.hpp"


typedef double func (double);

using namespace std;

double integrator(func function){
  // ideally adjust the quadrature rule to the polynomial order...
  // size_t number_of_nodes = ceil((polynomial_order+1)/2.0);
  //  later ...
  // copy rules for order 20 in STL vectors for further use*

  vector<double> data; //Initialize a vector named data
  unsigned int nn = 16; // nn: size of the vector (nbr elements)
  data.resize(nn); // Resize the vector to "nn" elements
  // Copy from the first element of the array Quad1D_10 to the "nn"-element into the vector data
  copy(Quad1D_8, Quad1D_8+nn, data.begin());

  vector<double> nodes(nn/2);
  vector<double> weights(nn/2);

  for(int ii=0; ii<nn; ii=ii+2)
  {
    nodes.push_back(data[ii]);
    weights.push_back(data[ii+1]);
  }

  double value = 0.0;
  for(int ii=0; ii<nodes.size(); ++ii)
  value += weights[ii]*function(nodes[ii]);
  return value;
}
