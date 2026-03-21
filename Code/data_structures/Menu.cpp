//
// Created by baguetes on 20/03/2026.
//

#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Parser.h"

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