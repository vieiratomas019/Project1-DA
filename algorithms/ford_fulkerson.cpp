#include "../data_structures/Graph.h"
#include <limits>
#include <linux/limits.h>
using namespace std;

// Function to perform DFS and find an augmenting path
template <class T>
bool dfsFindAugmentingPath(Vertex<T>* v, Vertex<T>* t, double& flow) {
    if (v == t) return true;
    v->setVisited(true);

    // outward edges
    for (Edge<T>* e : v->getAdj())
    {
        Vertex<T>* w = e->getDest();
        double residual = e->getWeight() - e->getFlow();

        if (!w->isVisited() && residual > 0) {
            w->setPath(e);

        if (dfsFindAugmentingPath(w, t, flow))
        {
            flow = min(flow, residual);
            return true;
        }
        }
     }

    // inward edges
    for (Edge<T>* e : v->getIncoming())
    {
        Vertex<T>* w = e->getOrig();
        double residual = e->getFlow();

        if (!w->isVisited() && residual > 0)
        {
            w->setPath(e);
            if (dfsFindAugmentingPath(w, t, flow))
            {
                flow = min(flow, residual);
                return true;
            }
        }
    }

    return false;
}

// Ford-Fulkerson algorithm
template <class T>
void fordFulkerson(Graph<T>* g, int source, int target) {
    Vertex<T>* s = g->findVertex(source);
    Vertex<T>* t = g->findVertex(target);

    if (s == nullptr || t == nullptr || s == t)
        throw std::logic_error("Invalid source and/or target vertex");

    // set flow 0
    for (Vertex<T>* v : g->getVertexSet()) {
        for (Edge<T>* e : v->getAdj()) {
            e->setFlow(0);
        }
    }

    double flow = ARG_MAX;

    // set all as unvisited
    // remove old path
    for (Vertex<T>* v : g->getVertexSet())
    {
        v->setVisited(false);
        v->setPath(nullptr);
    }

    while (dfsFindAugmentingPath(s, t, flow))
    {
        Vertex<T>* vertex = t;

        for (Vertex<T>* v = t; v != s; )
        {
            Edge<T>* e = v->getPath();
            double floww = e->getFlow();

            if (e->getDest() == v) // if forward edge
            {
                e->setFlow(floww + flow);
                v = e->getOrig();
            } else // backward edge
            {
                e->setFlow(floww - flow);
                v = e->getDest();
            }
        }

        flow = ARG_MAX;

        for (Vertex<T>* v : g->getVertexSet())
        {
            v->setVisited(false);
            v->setPath(nullptr);
        }
    }

}

/*
/// TESTS ///
#include <gtest/gtest.h>

TEST(Algorithm_2, test_fordFulkerson) {
    Graph<int> myGraph;

    for(int i = 1; i <= 6; i++)
        myGraph.addVertex(i);

    myGraph.addEdge(1, 2, 3);
    myGraph.addEdge(1, 3, 2);
    myGraph.addEdge(2, 5, 4);
    myGraph.addEdge(2, 4, 3);
    myGraph.addEdge(2, 3, 1);
    myGraph.addEdge(3, 5, 2);
    myGraph.addEdge(4, 6, 2);
    myGraph.addEdge(5, 6, 3);

    fordFulkerson(&myGraph, 1, 6);

    std::stringstream ss;
    for(auto v : myGraph.getVertexSet()) {
        ss << v->getInfo() << "-> (";
        for (const auto e : v->getAdj())
            ss << (e->getDest())->getInfo() << "[Flow: " << e->getFlow() << "] ";
        ss << ") || ";
    }

    std::cout << ss.str() << std::endl << std::endl;

    EXPECT_EQ("1-> (2[Flow: 3] 3[Flow: 2] ) || 2-> (5[Flow: 1] 4[Flow: 2] 3[Flow: 0] ) || 3-> (5[Flow: 2] ) || 4-> (6[Flow: 2] ) || 5-> (6[Flow: 3] ) || 6-> () || ", ss.str());
}
*/