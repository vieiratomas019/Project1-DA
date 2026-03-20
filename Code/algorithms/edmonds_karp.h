

#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#include "../data_structures/Graph.h"

// Function to test the given vertex 'w' and visit it if conditions are met
template <class T>
void testAndVisit(std::queue< Vertex<T>*> &q, Edge<T> *e, Vertex<T> *w, double residual) {
    // Check if the vertex 'w' is not visited and there is residual capacity
    if (! w->isVisited() && residual > 0) {
        // Mark 'w' as visited, set the path through which it was reached, and enqueue it
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

// Function to find an augmenting path using Breadth-First Search
template <class T>
bool findAugmentingPath(Graph<T> *g, Vertex<T> *s, Vertex<T> *t) {
    // Mark all vertices as not visited
    for(auto v : g->getVertexSet()) {
        v->setVisited(false);
    }

    std::queue<Vertex<T>*> q;
    s->setVisited(true);
    q.push(s);

    while ( !q.empty() ) {
        Vertex<T>* v = q.front();
        q.pop();

        // iterate through all forward edges
        for (Edge<T>* e : v->getAdj()) {
            double residualCapacity = e->getWeight() - e->getFlow();

            testAndVisit(q, e, e->getDest(), residualCapacity);

            // early exit
            if (t->isVisited()) return true;
        }

        // iterate through all backward edges
        for (Edge<T>* e : v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());

            // early exit
            if (t->isVisited()) return true;
        }
    }

    // Return true if a path to the target is found, false otherwise
    return t->isVisited();
}

// Function to find the minimum residual capacity along the augmenting path
template <class T>
double findMinResidualAlongPath(Vertex<T> *s, Vertex<T> *t) {
    double f = INF;

    Vertex<T>* curr = t;
    while (curr != s) {
        // edge whose dest is curr
        Edge<T>* e = curr->getPath();

        double residualCapacity;
        if (e->getDest() == curr) { // forwards edge
            residualCapacity = e->getWeight() - e->getFlow();
            curr = e->getOrig();
        } else { // backwards edge
            residualCapacity = e->getFlow();
            curr = e->getDest();
        }

        if (residualCapacity < f) f = residualCapacity;
    }

    // Return the minimum residual capacity
    return f;
}

// Function to augment flow along the augmenting path with the given flow value
template <class T>
void augmentFlowAlongPath(Vertex<T> *s, Vertex<T> *t, double f) {
    // Traverse the augmenting path and update the flow values accordingly
    Vertex<T>* curr = t;

    while(curr != s) {
        Edge<T>* e = curr->getPath(); // edge whose dest is curr

        if (e->getDest() == curr) {
            e->setFlow(e->getFlow() + f);
            curr = e->getOrig();
        } else {
            e->setFlow(e->getFlow() - f);
            curr = e->getDest();
        }
    }
}

/**
 * @brief Runs Edmonds-Karp algorithm on a graph
 * @param g Pointer to the graph
 * @param source integer identifier of the source node
 * @param target integer identifier of the sink node
 * @note Time Complexity: O(V E^2), V: number of vertices, E: number of edges
 */
template <class T>
void edmondsKarp(Graph<T> *g, int source, int target) {
    // Find source and target vertices in the graph
    Vertex<T>* s = g->findVertex(source);
    Vertex<T>* t = g->findVertex(target);

    // initialize flow of all existing edges to 0
    for (Vertex<T>* v : g->getVertexSet())
        for (Edge<T>* e : v->getAdj())
            e->setFlow(0);

    // while loop that finds augmenting path, calculates the minimum residual, and augments the flow until no more paths can be found
    while (findAugmentingPath(g, s, t)) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}

#endif

