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

vector<string> validateOutput(const string& filename){
    vector<string> incorrect_lines;
    vector<string> output = parseLines("Output/output_" + filename);
    vector<string> expected = parseLines("Expected_Output/output_" + filename);

    if (output.size() != expected.size()){incorrect_lines.push_back("Incorrect number of lines");}

    for (int i = 0; i < output.size(); i++)
    {
        if (output[i] != expected[i]){incorrect_lines.push_back(output[i]); incorrect_lines.push_back(expected[i]);}
    }
    return incorrect_lines;
}

int main()
{
    rodar();
    for (int i = 1; i <= 14; i++)
    {
        vector<string> res = validateOutput("dataset" + to_string(i) + ".csv");
        if (res.empty()){cout << "Output " + to_string(i) + " is correct!" << endl;}
        else
        {
            cout << "=======================================" << endl;
            cout << "Output " + to_string(i) + " is incorrect!" << endl;
            cout << "First Incorrect Line: " << res[0] << endl;
            cout << "Should be: " << res[1] << endl;
            cout << "=======================================" << endl;
        }
    }
    return 0;
}