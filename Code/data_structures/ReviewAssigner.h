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

struct Results {
    bool valid = false; // check if we called ReviewAssigner::generate();
    bool success = false;

    // relations between primary of reviewers and submissions
    std::vector<std::pair<int, int>> primary_rel;

    // ADD OTHER RELATIONS

    // ADD riskAnalysis info
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
};


#endif //REVIEWASSIGNER_H