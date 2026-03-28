//
// Created by Henrique Reis on 28/03/2026.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "data_structures/ReviewAssigner.h"
using namespace std;

vector<string> parseLines(const string& filename){
    ifstream file(filename);
    vector<string> res;
    string line;

    while (getline(file, line))
    {
        res.push_back(line);
    }

    return res;
}

bool validateOutput(const string& filename){
    bool correct = true;
    vector<string> output = parseLines("Output/output_" + filename);
    vector<string> expected = parseLines("Expected_Output/" + filename);

    if (output.size() != expected.size()){correct = false;}

    for (int i = 0; i < output.size(); i++)
    {
        if (output[i] != expected[i]){correct = false;}
    }
    return correct;
}

int main()
{
    if (validateOutput("dataset13.csv")){cout << "Output is correct!" << endl;}
    else{cout << "Output is incorrect!" << endl;}
    return 0;
}