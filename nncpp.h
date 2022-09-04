#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <cmath>
#include <time.h>

using namespace std;

class Perceptron
{
public:
    vector<double> weights;
    double bias;
    Perceptron(int inputs, double bias = 1.0);
    double run(vector<double> x);
    void setWeights(vector<double> wInit);
    double sigmoid(double x);
};

class MultiLayerPerceptron
{
public:
    MultiLayerPerceptron(vector<int> layers, double bias = 1.0, double eta = 0.5);
    // eta is the learning rate of the machine-learning algorithm
    void setWeights(vector<vector<vector<double>>> wInit);
    void printWeights();
    vector<double> run(vector<double> x);
    double bp(vector<double> x, vector<double> y);

    vector<int> layers;
    double bias;
    double eta;
    vector<vector<Perceptron>> network;
    // the class that consists of the actual network
    vector<vector<double>> values;
    // holding the output values
    vector<vector<double>> d;
    // used for error handling and redundant terms.
};