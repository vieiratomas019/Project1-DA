//
// Created by baguetes on 21/03/2026.
//

#include "ReviewAssigner.h"
#include "../algorithms/edmonds_karp.h"

ReviewAssigner::ReviewAssigner(const Parser &parser) : parser(parser), graph_info() {
}

void ReviewAssigner::generate() {
    createGraph();

    switch (parser.getControl().GenerateAssignments) {
        case 0: case 1:
            addEdges1(); break;
        case 2:
            addEdges2(); break;
        case 3:
            addEdges3(); break;
        default: break;
    }

    run();
}

void ReviewAssigner::printResults() const {
    const std::vector<Submission>& submissions = parser.getSubmissions();
    const std::vector<Reviewer>& reviewers = parser.getReviewers();

    for (int j = 0; j < graph_info.N_REV; j++) {
        Vertex<int>* v = graph_info.graph.findVertex(j + 1);
        for (Edge<int>* e : v->getAdj()) {
            if (e->getFlow() == 1) {
                int subIdx = e->getDest()->getInfo() - graph_info.N_REV - 1;
                std::cout << "Reviewer " << reviewers[j].id
                          << " -> Submission " << submissions[subIdx].id << "\n";
            }
        }
    }
}

void ReviewAssigner::createGraph() {
    const std::vector<Submission>& submissions = parser.getSubmissions();
    const std::vector<Reviewer>& reviewers = parser.getReviewers();
    const Parameters& parameters = parser.getParameters();

    const int& N_SUB = static_cast<int>(submissions.size()), N_REV = static_cast<int>(reviewers.size()) ;
    const int& source = 0, sink = 1 + N_REV + N_SUB;

    // save into the struct
    graph_info.source = source;
    graph_info.sink = sink;
    graph_info.N_REV = N_REV;
    graph_info.N_SUB = N_SUB;

    // === ADD NODES ===

    // source
    graph_info.graph.addVertex(source);

    // reviewers [ 1 ... N_REV ]
    for (int i = 1; i <= N_REV; i++) graph_info.graph.addVertex(i);

    // submissions ] N_REV ... N_REV + N_SUB ]
    for (int j = 1; j <= N_SUB; j++) graph_info.graph.addVertex(N_REV + j);

    // sink
    graph_info.graph.addVertex(sink);

}

void ReviewAssigner::addEdges1() {
    const std::vector<Submission>& submissions = parser.getSubmissions();
    const std::vector<Reviewer>& reviewers = parser.getReviewers();
    const Parameters& parameters = parser.getParameters();

    // connect source to reviewers
    for (int i = 0; i < graph_info.N_REV; i++) graph_info.graph.addEdge(graph_info.source, 1 + i, parameters.MaxReviewsPerReviewer);

    // connect reviewers to submissions
    for (int i = 0; i < graph_info.N_REV; i++) {
        for (int j = 0; j < graph_info.N_SUB; j++) {
            if (reviewers[i].primary == submissions[j].primary) graph_info.graph.addEdge(1 + i, 1 + graph_info.N_REV + j, 1);
        }
    }

    // connect submissions to sink
    for (int i = 0; i < graph_info.N_SUB; i++) graph_info.graph.addEdge(1 + graph_info.N_REV + i, graph_info.sink, parameters.MinReviewsPerSubmission);
}

void ReviewAssigner::addEdges2() {
    /* still to be implemented */
}

void ReviewAssigner::addEdges3() {
    /* still to be implemented */
}

void ReviewAssigner::run() {
    edmondsKarp(&graph_info.graph, graph_info.source, graph_info.sink);
}

