
#include <iostream>
#include "nncpp.cpp"

int main()
{
    srand(time(NULL));
    rand();

    cout << "\n\n-----------Logic Gate Example---------------\n\n";
    Perceptron *p = new Perceptron(2);

    //  p->setWeights({10, 10, -15});
    //  AND gate test

    p->setWeights({15, 15, -10});
    cout << "Gate : " << endl;
    cout << p->run({0, 0}) << endl;
    cout << p->run({0, 1}) << endl;
    cout << p->run({1, 0}) << endl;
    cout << p->run({1, 1}) << endl;

    cout << "\n\n---------Hardcoded XOR Example-----------\n\n";
    MultiLayerPerceptron mlp = MultiLayerPerceptron({2, 2, 1});
    mlp.setWeights({{{-10, -10, 15}, {15, 15, -10}}, {{10, 10, -15}}});
    mlp.printWeights();

    cout << "XOR: " << endl;
    cout << "0 0 = " << mlp.run({0, 0})[0] << endl;
    cout << "0 1 = " << mlp.run({0, 1})[0] << endl;
    cout << "1 0 = " << mlp.run({1, 0})[0] << endl;
    cout << "1 1 = " << mlp.run({1, 1})[0] << endl;
}