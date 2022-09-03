
#include "nncpp.h"
using namespace std;
double frand()
{
    return (2.0 * (double)rand() / RAND_MAX) - 1.0;
}

// return a new Perceptron object with the specified number of inputs (+1 for the bias)
Perceptron::Perceptron(int inputs, double bias)
{
    this->bias = bias;
    weights.resize(inputs + 1);
    generate(weights.begin(), weights.end(), frand);
}

// Firing the perceptron with X being a vector with input values
double Perceptron::run(vector<double> x)
{
    x.push_back(bias);
    double sum = inner_product(x.begin(), x.end(), weights.begin(), (double)0.0);
    return sigmoid(sum);
}

void Perceptron::setWeights(vector<double> wInit)
{
    weights = wInit;
}

double Perceptron::sigmoid(double x)
{
    return (1.0 / (1.0 + exp(-x)));
}
