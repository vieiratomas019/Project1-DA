//
// Created by baguetes on 21/03/2026.
//

#ifndef REVIEWASSIGNER_H
#define REVIEWASSIGNER_H
#include "Parser.h"
#include "Graph.h"

struct GraphInfo {
    Graph<int> graph;
    int source;
    int sink;
    int N_REV;
    int N_SUB;
};

class ReviewAssigner {
public:
    ReviewAssigner(const Parser& parser);
    void generate();
    void printResults() const;

private:
    const Parser& parser;
    GraphInfo graph_info;

    void createGraph();
    void addEdges1();
    void addEdges2();
    void addEdges3();

    void run();
};


#endif //PROJECT1_REVIEWASSIGNER_H