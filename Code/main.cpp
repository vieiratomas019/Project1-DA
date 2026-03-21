#include <iostream>

#include "data_structures/Graph.h"
#include "data_structures/Menu.h"
#include "algorithms/edmonds_karp.h"
#include "algorithms/ford_fulkerson.h"
#include "data_structures/Parser.h"

void usage() {
    std::cerr << "Usage CLI: myProg\nUsage Batch: myProg -b [input_file] [output_filename]" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 1 && argc != 4) {
        usage();
        return 1;
    }

    if (argc == 1) {
        // WITH THE INPUT FILE: KEEP IN MIND THAT THE PATH MUST INCLUDE THE Input/ FOLDER

        // while loop perguntar o input file
            // se quer sair do programa : sair
            // se input file valido
                // Parser parser;
                // parser.parse()
                // break;
        // === THEN ===
        // mostrar menu full para que o user edite alguma coisa do input file
            // ==== USER CAN: ====
            // request information: provided the current config from the parsed input file (list reviewers, submissions, parameters, etc)
            // change some information ??????????
        // create the graph with the stored info
        // run the algorithm
        // still some missing steps

        Parser parser;
        parser.parse("Input/dataset1.csv");

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

        Parameters params = parser.getParameters();
        std::cout << "\n--- PARAMETERS ---\n";
        std::cout << "MinReviewsPerSubmission: " << params.MinReviewsPerSubmission << std::endl;
        std::cout << "MaxReviewsPerReviewer: " << params.MaxReviewsPerReviewer << std::endl;
        std::cout << "PrimaryReviewerExpertise: " << params.PrimaryReviewerExpertise << std::endl;
        std::cout << "SecondaryReviewerExpertise: " << params.SecondaryReviewerExpertise << std::endl;
        std::cout << "PrimarySubmissionDomain: " << params.PrimarySubmissionDomain << std::endl;
        std::cout << "SecondarySubmissionDomain: " << params.SecondarySubmissionDomain << std::endl;

        Control ctrl = parser.getControl();
        std::cout << "\n--- CONTROL ---\n";
        std::cout << "GenerateAssignments: " << ctrl.GenerateAssignments << std::endl;
        std::cout << "RiskAnalysis: " << ctrl.RiskAnalysis << std::endl;
        std::cout << "OutputFileName: " << ctrl.OutputFileName << std::endl;
    }

    return 0;
}