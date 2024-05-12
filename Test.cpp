#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, -1},
        {1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph4= {
       {0, -10, -5, 0},
        {-10, 0, -2, 0},
        {-5, -2, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph5= {
       {0, 0,0,0},
        {1,0,1,0},
        {0,1,0,1},
        {0,1,0,0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == false);



    vector<vector<int>> graph6 = {
    {0, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph7= {
       {0, 0,1,0},
        {0,0,0,1},
        {0,1,0,0},
        {1,0,0,0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->2");

    vector<vector<int>> graph4= {
       {0, -10, -5, 0},
        {-10, 0, -2, 0},
        {-5, -2, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "Invalid start or end vertex");

     vector<vector<int>> graph5 = {
        {0, -1, 2},
        {0, 0, -3},
        {0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph6= {
       {0, 0,1,0},
        {0,0,0,1},
        {0,1,0,0},
        {1,0,0,0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->1->3");

    vector<vector<int>> graph7 = {
          {0, 3, 7},
        {0, 0, 0},
        {7, 1, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::shortestPath(g, 1,0) == "-1");


}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3= {
       {0, -10, -5, 0},
        {-10, 0, -2, 0},
        {-5, -2, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph3); 
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph4= {
       {0, 0,0,0},
        {1,0,1,0},
        {0,1,0,1},
        {0,1,0,0}};
    g.loadGraph(graph4);
     CHECK(ariel::Algorithms::isContainsCycle(g) == true);


    vector<vector<int>> graph5 = {
        {0, 0, 0, 1, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, -1, 0},
        {0, 0, 0, 0, 1},
        {0, -1, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);


}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4= {
       {0,-5,0,0},
        {0,0,1,0},
        {2,0,0,0},
        {0,0,0,3}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph5 = {
        {0, 0, 0, 1, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, -1, 0},
        {0, 0, 0, 0, 1},
        {0, -1, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 4, 2}, B={3, 1}");

    vector<vector<int>> graph7= {
       {0, 0,1,0},
        {0,0,0,1},
        {0,1,0,0},
        {1,0,0,0}};
    g.loadGraph(graph7);
     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1}, B={2, 3}");
    

}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
     vector<vector<int>> graph1 = {
        {0, 0, 0, 1, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, -1, 0},
        {0, 0, 0, 0, 1},
        {0, -1, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle found: 3->4->1->2->3");

     vector<vector<int>> graph8= {
       {0,-5,0,0},
        {0,0,1,0},
        {2,0,0,0},
        {0,0,0,3}};
    g.loadGraph(graph8);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle found: 2->0->1->2");

    vector<vector<int>> graph6= {
       {0, 0,0,0},
        {1,0,1,0},
        {0,1,0,1},
        {0,1,0,0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    vector<vector<int>> graph5= {
       {0, -10, -5, 0},
        {-10, 0, -2, 0},
        {-5, -2, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle found: 2->1->2");



}


