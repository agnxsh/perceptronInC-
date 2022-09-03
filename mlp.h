#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <cmath>
#include <time.h>
#include "nncpp.cpp"
using namespace std;

class MultiLayerPerceptron
{
public:
    MultiLayerPerceptron(vector<int> layers, double bias = 1.0, double eta = 0.5);
    void setWeights(vector<vector<vector<double>>> wInit);
    void printWeights();
    vector<double> run(vector<double> x);
    double bp(vector<double> x, vector<double> y);

    vector<int> layers;
    double bias;
    double eta;
    vector<vector<Perceptron>> network;
    vector<vector<double>> values;
    vector<vector<double>> d;
};