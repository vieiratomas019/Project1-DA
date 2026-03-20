#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

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

/**
 * @brief Runs Ford-Fulkerson algorithm on a graph
 * @param g Pointer to the graph
 * @param source integer identifier of the source node
 * @param target integer identifier of the sink node
 * @note Time Complexity: O(E |f*|), E: number of edges, |f*|: maximum value for the flow
 */

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

#endif