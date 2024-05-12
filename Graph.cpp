//oriya7914@gamil.com
//213525512

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel {
     std::vector<size_t> Graph::getNeighbors(size_t node) {
    std::vector<size_t> neighbors;
    if (node >= this->numvertices) {
        throw std::invalid_argument("Invalid vertex index");
    }

    for (size_t i = 0; i < this->numvertices; ++i) {
        if (this->adjMatrix[node][i] != 0) {
            neighbors.push_back(i);
        }
    }

    return neighbors;
}



  
    void Graph::printGraph() {
        cout << "Graph with " << this->numvertices << " vertices and " << this->numedges << " edges.\n";
    }

    bool Graph::isDirected() {
        return this->directedGraph;
    }

    vector<vector<int>> Graph::getMatrix() {
        return this->adjMatrix;
    }

    size_t Graph::getNumOfVertices() {
        return this->numvertices;
    }

    bool Graph::checkEdge(size_t node, size_t node2) {
        if (this->adjMatrix[node][node2] != 0) {
            return true;
        }
        return false;
    }

    void Graph::loadGraph(vector<vector<int>> &adjMatrix) {
        if (adjMatrix.size() != adjMatrix[0].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix");
        }

        this->numvertices = adjMatrix.size();
        this->numedges = 0;
        this->adjMatrix = adjMatrix;
        this->directedGraph = false;
        this->weightedGraph = false;

        for (size_t i = 0; i < this->numvertices; ++i) {
            for (size_t j = 0; j < this->numvertices; ++j) {
                if (adjMatrix[i][j]  != adjMatrix[j][i] ) {
                    this->directedGraph = true;
                    break; // Early exit if directedness is confirmed
                }
            }
            if (this->directedGraph) {
                break;
            }
        }
        
        for (size_t i = 0; i < this->numvertices; ++i) {
            for (size_t j = 0; j < this->numvertices; ++j) {
                if(adjMatrix[i][j] != 0)
                {
                    this->numedges=this->numedges+1;
                }
            }
        }

        

        //cout << "Graph with " << this->numedges << " edges.\n";
        // if the graph is directed, it has half the number of edges
        if (!this->directedGraph) {

            this->numedges = this->numedges / 2;
        }
    }

}



