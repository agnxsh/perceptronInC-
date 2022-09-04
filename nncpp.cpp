
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

MultiLayerPerceptron::MultiLayerPerceptron(vector<int> layers, double bias, double eta)
{
    this->layers = layers;
    this->bias = bias;
    this->eta = eta;
    for (int i = 0; i < layers.size(); i++)
    {
        values.push_back(vector<double>(layers[i], 0.0));
        // initialising the first neuron with 0.0
        network.push_back(vector<Perceptron>());
        if (i > 0)
        // network[0] is the input layer so it has no neurons
        {
            for (int j = 0; j < layers[i]; j++)
            {
                network[i].push_back(Perceptron(layers[i - 1], bias));
            }
        }
    }
}

void MultiLayerPerceptron::setWeights(vector<vector<vector<double>>> wInit)
{
}

void MultiLayerPerceptron::printWeights()
{
    cout << endl;
    for (int i = 1; i < network.size(); i++)
    {
        for (int j = 0; j < layers[i]; j++)
        {
            cout << "Layer" << i + 1 << "Neuron" << j << ": ";
            for (auto &it : network[i][j].weights)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}