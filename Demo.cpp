/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */
//oriya7914@gamil.com
//213525512
#include "Algorithms.hpp"
#include "Graph.hpp"

using  namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g;
    cout << "My Graph 1" ;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
     cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
     cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << "Graph with  nc" ;
    cout << Algorithms::negativeCycle(g) << endl;
 
    // 5x5 matrix that represents a non-connected graph with a cycle.
    cout << "My Graph 2" ;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
     cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::negativeCycle(g) << endl;// no

    // 5x5 matrix that reprsents a connected weighted graph.
    cout << "My Graph 3" ;
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
     cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
     cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).//not true suppose to print:The cycle is: 0->1->2->0
     cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."////it not true
    cout << Algorithms::negativeCycle(g) << endl;// no


cout << "My Graph 5" ;
     // delite before sobmitt
    vector<vector<int>> graph5= {
       {0, -10, -5, 0},
        {-10, 0, -2, 0},
        {-5, -2, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph5); // Load the graph to the object.

    g.printGraph();     //Graph with 4 vertices and 4 edges
    cout << Algorithms::isConnected(g) << endl;//yes
    cout << Algorithms::shortestPath(g, 0, 3) << endl;// -1 Graph contains negative weight cycle 
    cout << Algorithms::isContainsCycle(g) << endl;//The cycle is: 0->1->2->0
    cout << Algorithms::negativeCycle(g) << endl;//Negative cycle found: 2->1->2

    cout << "My Graph 6" ;
    vector<vector<int>> graph6= {
       {0, 0,0,0},
        {1,0,1,0},
        {0,1,0,1},
        {0,1,0,0}};
    g.loadGraph(graph6); // Load the graph to the object.
    
    g.printGraph();     
    cout << Algorithms::isConnected(g) << endl;// no// גרף שהוא לא מכוון חייב להיותבעל קשירות מלאה כדי להיות קשור
    cout << Algorithms::shortestPath(g, 0,1) << endl;// -1
    cout << Algorithms::isBipartite(g) << endl; //// non
    cout << Algorithms::isContainsCycle(g) << endl;
    cout << Algorithms::negativeCycle(g) << endl;//no

cout << "My Graph 7" ;
     vector<vector<int>> graph7= {
       {0, 0,1,0},
        {0,0,0,1},
        {0,1,0,0},
        {1,0,0,0}};
    g.loadGraph(graph7); // Load the graph to the object.

    g.printGraph();     
    cout << Algorithms::isConnected(g) << endl;// 1
    cout << Algorithms::shortestPath(g, 3,0) << endl;//-1
    cout << Algorithms::isBipartite(g) << endl; //// no
    cout << Algorithms::isContainsCycle(g) << endl;//The cycle is: 0->1->2->0
    cout << Algorithms::negativeCycle(g) << endl;//Negative cycle found: 2->0->1->2

cout << "My Graph 8" ;
     vector<vector<int>> graph8= {
       {0,-5,0,0},
        {0,0,1,0},
        {2,0,0,0},
        {0,0,0,3}};
    g.loadGraph(graph8); // Load the graph to the object.

    g.printGraph();     
    cout << Algorithms::isConnected(g) << endl;// no
    cout << Algorithms::shortestPath(g, 3,0) << endl;//-1
    cout << Algorithms::isBipartite(g) << endl; //// A:2,3 B:0,1
    cout << Algorithms::isContainsCycle(g) << endl;//
    cout << Algorithms::negativeCycle(g) << endl;//no

    
cout << "My Graph 8" ;
    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
                         
}
