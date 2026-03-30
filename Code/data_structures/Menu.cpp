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
    vector<Submission> submissions = parser.getSubmissions();
    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════════════════════════════╗" << endl << "\033[0m";
    cout << "\033[34m" << "  ║                      SUBMISSIONS                             ║" << endl << "\033[0m";
    cout << "\033[34m" << "  ╠══════════════════════════════════════════════════════════════╣" << endl << "\033[0m";
    for (const auto& s : submissions) {
        cout << "       ID: " << s.id << endl;
        cout << "       Title: " << s.title << endl;
        cout << "       Authors: " << s.authors << endl;
        cout << "       Email: " << s.email << endl;
        cout << "       Primary: " << s.primary << endl;
        cout << "       Secondary: " << s.secondary << endl;
        cout << "  ╠══════════════════════════════════════════════════════════════╣" << endl;
    }
}

void showReviewers(const Parser& parser){
    vector<Reviewer> reviewers = parser.getReviewers();
    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════════════════════════════╗" << endl << "\033[0m";
    cout << "\033[34m" << "  ║                       REVIEWERS                              ║" << endl << "\033[0m";
    cout << "\033[34m" << "  ╠══════════════════════════════════════════════════════════════╣" << endl << "\033[0m";
    for (const auto& r : reviewers) {
        cout << "     ID: " << r.id << endl;
        cout << "     Name: " << r.name << endl;
        cout << "     Email: " << r.email << endl;
        cout << "     Primary: " << r.primary << endl;
        cout << "     Secondary: " << r.secondary << endl;
        cout << "  ╚══════════════════════════════════════════════════════════════╝" << endl;
    }
}

void showParameters(const Parser& parser){
    Parameters params = parser.getParameters();
    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════════════════════════════╗" << endl << "\033[0m";
    cout << "\033[34m" << "  ║                      PARAMETERS                              ║" << endl << "\033[0m";
    cout << "\033[34m" << "  ╠══════════════════════════════════════════════════════════════╣" << endl << "\033[0m";
    cout << "    MinReviewsPerSubmission:   " << params.MinReviewsPerSubmission << endl;
    cout << "    MaxReviewsPerReviewer:     " << params.MaxReviewsPerReviewer << endl;
    cout << "    PrimaryReviewerExpertise:  " << params.PrimaryReviewerExpertise  << endl;
    cout << "    SecondaryReviewerExpertise:" << params.SecondaryReviewerExpertise<< endl;
    cout << "    PrimarySubmissionDomain:   " << params.PrimarySubmissionDomain   << endl;
    cout << "    SecondarySubmissionDomain: " << params.SecondarySubmissionDomain << endl;
    cout << "  ╚══════════════════════════════════════════════════════════════╝" << endl;
}

void showControl(const Parser& parser){
    Control ctrl = parser.getControl();
    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════════════════════════════╗" << endl << "\033[0m";
    cout << "\033[34m" << "  ║                       CONTROL                                ║" << endl << "\033[0m";
    cout << "\033[34m" << "  ╠══════════════════════════════════════════════════════════════╣" << endl << "\033[0m";
    cout << "    GenerateAssignments: " << ctrl.GenerateAssignments << endl;
    cout << "    RiskAnalysis:        " << ctrl.RiskAnalysis << endl;
    cout << "    OutputFileName:      " << ctrl.OutputFileName << endl;
    cout << "  ╚══════════════════════════════════════════════════════════════╝" << endl;
}

//show the options for the menu
void showMenu(){
    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════╗" << endl << "\033[0m";
    cout << "\033[34m" << "  ║       Choose an option (1-5):        ║" << endl << "\033[0m";
    cout << "\033[34m" << "  ╠══════════════════════════════════════╣" << endl << "\033[0m";
    cout << "  ║  1.  See Info                        ║" << endl;
    cout << "  ║  2.  Create the Graph                ║" << endl;
    cout << "  ║  3.  Run the Algorithm               ║" << endl;
    cout << "  ║  4.  Edit Control Values             ║" << endl;
    cout << "  ║  5.  Exit                            ║" << endl;
    cout << "  ╚══════════════════════════════════════╝" << endl;
    cout << "  Choose options (1-5): ";
}

//show new options when the user chooses 1 in the menu
void showInfoOptions(){
    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════╗" << endl << "\033[0m";
    cout << "\033[34m" << "  ║            View Info                 ║" << endl << "\033[0m";
    cout << "\033[34m" << "  ╠══════════════════════════════════════╣" << endl << "\033[0m";
    cout << "  ║  1.  Submissions                     ║" << endl;
    cout << "  ║  2.  Reviewers                       ║" << endl;
    cout << "  ║  3.  Parameters                      ║" << endl;
    cout << "  ║  4.  Control                         ║" << endl;
    cout << "  ╠══════════════════════════════════════╣" << endl;
    cout << "  ║  Combine options without spaces      ║" << endl;
    cout << "  ║  e.g. 134 = Submissions + Params     ║" << endl;
    cout << "  ║             + Control                ║" << endl;
    cout << "  ╚══════════════════════════════════════╝" << endl;
    cout << "  Choose options (1-4): ";
}

//handler/parser for the users input for options
void showWantedInfo(const Parser& parser, string opt_list){
    vector<int> options;
    for (char c: opt_list)
    {
        int n = c - '0';
        options.push_back(n);
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
        cout << endl;
        cout << "This information is available in the file Output/" << parser.getControl().OutputFileName << endl;
    } else
    {
        review_assigner.printResults();
        cout << "Executed the algorithm." << endl;
    }
}

enum Option{GENERATE, RISK, OUTPUT};

void changeVariable(Parser& parser)
{
    string variable;

    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════╗\n" << "\033[0m";
    cout << "\033[34m" << "  ║          EDIT CONTROL VALUES         ║\n" << "\033[0m";
    cout<< "\033[34m"  << "  ╠══════════════════════════════════════╣\n" << "\033[0m";
    cout << "  ║  Variables:                          ║\n";
    cout << "  ║  - GenerateAssignments (0-3)         ║\n";
    cout << "  ║  - RiskAnalysis        (0-1)         ║\n";
    cout << "  ║  - OutputFileName      (string)      ║\n";
    cout << "  ╚══════════════════════════════════════╝\n";
    cout << "  Which variable would you like to change: ";

    while (true)
    {
        cin >> variable;
        if (variable == "GenerateAssignments" || variable == "RiskAnalysis" || variable == "OutputFileName"){break;}

        cout << "  Variable should either be GenerateAssignments, RiskAnalysis or OutputFileName. Try again: ";
    }
    cout << "  What should the new value be: ";

    // GenerateAssignments and RiskAnalysis take ints while OutputFileName takes strings
    Option option;
    if (variable == "GenerateAssignments"){option = GENERATE;}
    if (variable == "RiskAnalysis"){option = RISK;}
    if (variable == "OutputFileName"){option = OUTPUT;}

    switch (option)
    {
    case GENERATE:
        int new_gen;
        while (true)
        {
            cin >> new_gen;
            if (new_gen >= 0 && new_gen <= 3){break;}

            cout << "  GenerateAssignments should be 0-3. Try again: ";
        }

        parser.setGenerateAssignemnts(new_gen);
        break;
    case RISK:
        int new_risk;
        while (true)
        {
            cin >> new_risk;
            if (new_risk == 0 || new_risk == 1){break;}

            cout << "  RiskAnalysis should be either 0 or 1. Try again: ";
        }

        parser.setRiskAnalysis(new_risk);
        break;
    case OUTPUT:
        string new_name;
        cin >> new_name;

        string csv = new_name.substr(new_name.length() - 4, 4);
        if (csv.compare(".csv"))
        {
            new_name += ".csv";
        }

        parser.setOutputFilename(new_name);
    }

    cout << "\n";
    cout << "\033[34m" << "  ╔══════════════════════════════════════╗\n" << "\033[0m";
    cout << "\033[34m" << "  ║  Changes applied successfully!       ║\n" << "\033[0m";
    cout << "\033[34m" << "  ╚══════════════════════════════════════╝\n" << "\033[0m";
}

void byebye()
{
    cout << R"(
                /|  /|  ---------------------------
                ||__||  |                         |
               /   O O\__        Bye bye!         |
              /          \                        |
             /      \     \                       |
            /   _    \     \ ----------------------
           /    |\____\     \      ||
          /     | | | |\____/      ||
         /       \| | | |/ |     __||
        /  /  \   -------  |_____| ||
       /   |   |           |       --|
       |   |   |           |_____  --|
       |  |_|_|_|          |     \----
       /\                  |
      / /\        |        /
     / /  |       |       |
 ___/ /   |       |       |
|____/    c_c_c_C/ \C_c_c_c
)";
}