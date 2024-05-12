//oriya7914@gamil.com
//213525512
#include <iostream>
#include <vector>
#pragma once
using namespace std;
namespace ariel{
     class Graph{
        private:
          vector<vector<int>>adjMatrix;
          int numedges;
          size_t numvertices;
          bool directedGraph;
          bool weightedGraph;

        
        public:
         std::vector<size_t> getNeighbors(size_t node) ;
        void loadGraph(vector<vector<int>> &Matrix);
        void printGraph();
        std::vector<std::vector<int>> getMatrix();
        size_t getNumOfVertices();
        bool checkEdge(size_t node, size_t node2);
        bool isDirected();
        
        





      
    };
   

}
