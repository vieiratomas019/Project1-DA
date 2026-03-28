//
// Created by baguetes on 20/03/2026.
//

#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Parser.h"
using namespace std;

//show the different parts of the parser object
void showSubmissions(const Parser& parser){
    std::cout << "\n--- SUBMISSIONS ---\n";
    vector<Submission> submissions = parser.getSubmissions();
    for (const auto& s : submissions) {
        std::cout << "ID: " << s.id;
        std::cout << " | Title: " << s.title;

        // Loop through the authors vector safely
        std::cout << " | Authors: " << s.authors;

        std::cout << " | Email: " << s.email;
        std::cout << " | Primary: " << s.primary;
        std::cout << " | Secondary: " << s.secondary << std::endl;
    }
}

void showReviewers(const Parser& parser){
  std::cout << "\n--- REVIEWERS ---\n";
    vector<Reviewer> reviewers = parser.getReviewers();
    for (const auto& r : reviewers) {
        std::cout << "ID: " << r.id;
        std::cout << " | Name: " << r.name;
        std::cout << " | Email: " << r.email;
        std::cout << " | Primary: " << r.primary;
        std::cout << " | Secondary: " << r.secondary << std::endl;
    }
    std::cout << "\n";
}

void showParameters(const Parser& parser){
    Parameters params = parser.getParameters();
    std::cout << "\n--- PARAMETERS ---\n";
    std::cout << "MinReviewsPerSubmission: " << params.MinReviewsPerSubmission << std::endl;
    std::cout << "MaxReviewsPerReviewer: " << params.MaxReviewsPerReviewer << std::endl;
    std::cout << "PrimaryReviewerExpertise: " << params.PrimaryReviewerExpertise << std::endl;
    std::cout << "SecondaryReviewerExpertise: " << params.SecondaryReviewerExpertise << std::endl;
    std::cout << "PrimarySubmissionDomain: " << params.PrimarySubmissionDomain << std::endl;
    std::cout << "SecondarySubmissionDomain: " << params.SecondarySubmissionDomain << std::endl;
}

void showControl(const Parser& parser){
    Control ctrl = parser.getControl();
    std::cout << "\n--- CONTROL ---\n";
    std::cout << "GenerateAssignments: " << ctrl.GenerateAssignments << std::endl;
    std::cout << "RiskAnalysis: " << ctrl.RiskAnalysis << std::endl;
    std::cout << "OutputFileName: " << ctrl.OutputFileName << std::endl;
}

void showAll(const Parser& parser){
  showSubmissions(parser);
  showReviewers(parser);
  showParameters(parser);
  showControl(parser);
}

//show the options for the menu
void showMenu(){
  cout << "Choose an Option (type the correspondent number):" << endl;
  cout << "1. See Info" << endl;
  cout << "2. Create the Graph" << endl;
  cout << "3. Run the Algorithm" << endl;
  cout << "4. Edit Control Values" << endl;
  cout << "5. Exit" << endl;
}

//show new options when the user chooses 1 in the menu
void showInfoOptions(){
    cout << "What Info do you wish to view?" << endl;
    cout << "If you want to view more than one field you should type the options without spaces (eg. 134)" << endl;
    cout << "1. Submissions" << endl;
    cout << "2. Reviewers" << endl;
    cout << "3. Parameters" << endl;
    cout << "4. Control" << endl;
}

//handler/parser for the users input for options
void showWantedInfo(const Parser& parser, string opt_list){
    vector<int> options;
    for (char c: opt_list)
    {
        if (c >= '1' && c <= '4')
        {
            int n = c - '0';
            options.push_back(n);
        }
    }

    for (int option : options)
    {
        switch (option)
        {
        case 1:
            showSubmissions(parser);
            break;
        case 2:
            showReviewers(parser);
            break;
        case 3:
            showParameters(parser);
            break;
        case 4:
            showControl(parser);
            break;
        }
    }
}

//handler for GenerateAssignments parameter
void handleGenerateAssignments(const Parser& parser, const ReviewAssigner& review_assigner)
{
    if (parser.getControl().GenerateAssignments)
    {
        review_assigner.printResults();
        review_assigner.outputResults();
        cout << "This information is available in the file Output/" << parser.getControl().OutputFileName << endl;
    } else
    {
        review_assigner.printResults();
        cout << "Executed the algorithm." << endl;
    }
}

void changeVariable(Parser& parser)
{
    string variable;
    cout << "Which Variable would you like to change (type GenerateAssignments, RiskAnalysis or OutputFileName): ";
    cin >> variable;
    cout << "What should the New Value be: ";

    // GenerateAssignments and RiskAnalysis take ints while OutputFileName takes strings
    if (variable == "GenerateAssignments")
    {
        int new_value;
        cin >> new_value;

        parser.setGenerateAssignemnts(new_value);
    } else if (variable == "RiskAnalysis")
    {
        int new_value;
        cin >> new_value;

        if (new_value >= 0 && new_value <= 3)
        {
            parser.setRiskAnalysis(new_value);
        }
    } else if (variable == "OutputFileName")
    {
        string new_value;
        cin >> new_value;

        parser.setOutputFilename(new_value);
    }

    cout << "Changes were applied." << endl;
}
