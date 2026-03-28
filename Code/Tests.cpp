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

void rodar(){
    for (int i = 1; i <= 14; i++)
    {
        Parser parser;
        parser.parse("Input/dataset" + to_string(i) + ".csv");
        parser.setOutputFilename("output_dataset" + to_string(i) + ".csv");
        ReviewAssigner review_assigner(parser);

        review_assigner.generate();
        review_assigner.outputResults();
    }
}

bool validateOutput(const string& filename){
    bool correct = true;
    vector<string> output = parseLines("Output/output_" + filename);
    vector<string> expected = parseLines("Expected_Output/output_" + filename);

    if (output.size() != expected.size()){correct = false;}

    for (int i = 0; i < output.size(); i++)
    {
        if (output[i] != expected[i]){correct = false;}
    }
    return correct;
}

int main()
{
    rodar();
    for (int i = 1; i <= 14; i++)
    {
        if (validateOutput("dataset" + to_string(i) + ".csv")){cout << "Output is correct!" << endl;}
        else{cout << "Output is incorrect!" << endl;}
    }
    return 0;
}