//
// Created by baguetes on 21/03/2026.
//

#ifndef REVIEWASSIGNER_H
#define REVIEWASSIGNER_H

#include "Parser.h"
#include "Graph.h"
#include <map>
#include <fstream>

struct GraphInfo {
    Graph<int> graph;
    int source;
    int sink;
    int N_REV;
    int N_SUB;
};

struct MissingReview {
    int sub_id;
    int domain;
    int count;
};

struct Results {
    bool valid = false; // check if we called ReviewAssigner::generate();
    bool success = true;

    // relations between primary of reviewers and submissions
    unsigned long primary_size;

    std::vector< std::tuple<int, int, int> > primary_rel_rev; // sorted by reviewers' IDs
    std::vector< std::tuple<int, int, int> > primary_rel_sub; // sorted by submissions' IDs

    // ADD OTHER RELATIONS

    std::vector<MissingReview> missing_reviews;

    // ADD riskAnalysis info
    int riskLevel = 0;
    std::vector<int> riskyReviewers;
};

class ReviewAssigner {
public:
    /**
* @brief Creates the graph
* @param parser reference to object parser that contains the desired info
*/
    ReviewAssigner(const Parser& parser);
    /**
* @brief Runs the algorithm
*/
    void generate();
    /**
* @brief Prints the results to the console
*/
    void printResults() const;
    /**
* @brief Outputs the results to the output file
*/
    void outputResults() const;
    /**
* @brief Returns the valid state of a Results object
*/
    bool getValid() const{return results.valid;}

private:
    const Parser& parser;
    GraphInfo graph_info;
    Results results;

    void createGraph();
    void addEdges();

    int matchesByMode(int mode, const Reviewer& rev, const Submission& sub);

    void storeResults();

    bool isAssignmentValid();
    void RiskAnalysis();
};


#endif //REVIEWASSIGNER_H