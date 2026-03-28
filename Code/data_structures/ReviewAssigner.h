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
};

class ReviewAssigner {
public:
    ReviewAssigner(const Parser& parser); // creates graph
    void generate(); // runs the algorithm
    void printResults() const; // prints the results
    void outputResults() const; // outputs the results to the output file
    void outputBatchResults(const string& output_filename) const; // outputs the results to the output file given via batch mode

private:
    const Parser& parser;
    GraphInfo graph_info;
    Results results;

    void createGraph();
    void addEdges();

    /**
     *
     * @param mode GenerateAssignments integer
     * @param rev Reviewer object
     * @param sub Submission object
     * @return returns 0 when there is no match, returns the domain matched when there is a match
     */
    int matchesByMode(int mode, const Reviewer& rev, const Submission& sub);

    void storeResults();
};


#endif //REVIEWASSIGNER_H