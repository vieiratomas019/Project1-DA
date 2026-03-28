//
// Created by baguetes on 21/03/2026.
//

#ifndef REVIEWASSIGNER_H
#define REVIEWASSIGNER_H

#include "Parser.h"
#include "Graph.h"
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
    ReviewAssigner(const Parser& parser); // creates graph
    void generate(); // runs the algorithm
    void printResults() const; // prints the results
    void outputResults() const; // outputs the results to the output file

private:
    const Parser& parser;
    GraphInfo graph_info;
    Results results;

    void createGraph();
    void addEdges1();
    void addEdges2();
    void addEdges3();

    void storeResults();

    bool isAssignmentValid();
    void RiskAnalysis();
};


#endif //REVIEWASSIGNER_H