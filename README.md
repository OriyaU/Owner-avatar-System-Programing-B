<!-- <!-- # מטלה 1 - גרפים (Classes and Namespaces)

המטרה שלכם במטלה הזאת היא ליצור מחלקה שמייצגת גרף ולממש אלגוריתמים על הגרפים (זה הזמן להזכר בקורס אלגוריתמים 1).

במטלה הזאת הייצוג של הגרף שלכם יתבצע בעזרת מטריצת שכנויות - https://he.wikipedia.org/wiki/%D7%9E%D7%98%D7%A8%D7%99%D7%A6%D7%AA_%D7%A9%D7%9B%D7%A0%D7%95%D7%AA.

הגרף יכול להיות גרף מכוון ולא מכוון וגם גרף ממושקל. מטריצת השכנויות חייבת להיות מטריצה ריבועית.

עליכם לכתוב את הקבצים הבאים:

```
Graph.cpp
Algorithms.cpp
```

הקובץ `Graph.cpp` מכיל מחלקה המייצגת גרף.
המחלקה מכילה את הפעולות `loadGraph` המקבלת מטריצת שכנויות וטוענת אותה לתוך הגרף ו-`printGraph` שמדפיסה את הייצוג של הגרף (הפורמט לבחירתכם, ראו דוגמה ב-`Demo.cpp`).

הקובץ `Algorithms.cpp` מכיל מימושים לאלגוריתמים על גרפים. ביניהם:

- `isConnected(g)` - האלגוריתם מקבל גרף ומחזיר 1 אם הגרף קשיר (אחרת מחזיר 0).
- `shortestPath(g,start,end)` - האלגוריתם מקבל גרף, קודקוד התחלה וקודקוד סיום ומחזיר את המסלול הקל ביותר (במקרה שהגרף לא ממושקל - הקצר ביותר) בין שני הקודקודים. במידה ואין מסלול כזה, האלגוריתם יחזיר -1.
- `isContainsCycle(g)` - האלגוריתם מקבל גרף ומדפיס מעגל כלשהו. אם לא קיים מעגל בגרף, האלגוריתם יחזיר 0.
- `isBipartite(g)` - האלגוריתם מקבל גרף ומחזיר את החלוקה של הגרף לגרף דו-צדדי. אם אי אפשר לחלק את הגרף, האלגוריתם יחזיר 0.
- `negativeCycle(g)` - האלגוריתם מקבל גרף ומוצא מעגל שלילי (כלומר מעגל שסכום המשקלים של הצלעות שלילי). אם לא קיים מעגל כזה, האלגוריתם ידפיס שלא קיים מעגל שלילי.

הקובץ `Demo.cpp` מכיל דוגמאות של קלטים ופלטים.
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. כמו כן, בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש). אי עמידה בהנחיות תגרור הפחתה בציון. בהצלחה! -->


Description of the  project: --># Owner-avatar-System-Programing-B
projectes




Description

Welcome to the Graph Algorithms Library, a C++ project that provides a simple  implementation of graph data structures along with fundamental graph algorithms. This library supports both directed and undirected graphs, allowing you to perform various graph-related operations with ease.

 
Classes:

   1. Graph
   2. Algorithms



The graph features and functionalities:
feachers:
the matricx of the graph
nomber of adges
nomber of vertecx
is weighted Graph
is directed graph

functionalities:
most important- loadGraph() :Load a graph from a 2D adjacency matrix.Check if the matrix is square (if not, it's un error).thisis where we anitialize all the features af the graph.
Second function  is printGraph() which is printing the number of vertices and edges in the graph/
and there is more:
getMatrix()
getNeighbors()
getNumOfVertices()
checkEdge()

The  Algoritems functionalities:
    static int isConnected(Graph &graph);
        Purpose: Determines if the graph is connected.
        Implementation: Utilizes Depth-First Search (DFS) to traverse the graph and checks if all vertices are reachable from the starting vertex. If any vertex remains unreachable, the graph is considered disconnected.

    static std::string negativeCycle(Graph& graph);
        Purpose: Detects the presence of a negative weight cycle in the graph.
        Implementation: Implements the Bellman-Ford algorithm to find the shortest paths from a source vertex to all other vertices. If any vertex's distance decreases in one more iteration, it indicates the presence of a negative cycle.

    static std::string shortestPath(Graph& graph, int start, int end);
        Purpose: Finds the shortest path between two vertices in the graph.
        Implementation: Employs Dijkstra's algorithm to calculate the shortest path from the start vertex to all other vertices, then backtracks to find the shortest path to the end vertex.

    static bool detectCycleDFS(Graph& graph, size_t node, std::vector<bool>& visited, std::vector<bool>& recStack);
        Purpose: Detects cycles in the graph using Depth-First Search (DFS).
        Implementation: Utilizes DFS to traverse the graph while keeping track of visited nodes and a recursive stack to detect back edges. If a back edge is found to a visited node in the recursion stack, it indicates the presence of a cycle.

    static std::string isBipartite(Graph& graph);
        Purpose: Determines if the graph is bipartite, meaning its vertices can be divided into two disjoint sets with no edges within the same set.
        Implementation: Uses a modified Breadth-First Search (BFS) algorithm to assign colors (group A and group B) to vertices and checks for adjacent vertices with the same color, which would violate bipartiteness.

    static void DFS(Graph &graph, size_t node, std::vector<bool> &visited);
        Purpose: Performs Depth-First Search (DFS) traversal on the graph.
        Implementation: Recursively explores the graph starting from a given node, marking visited nodes to avoid revisiting them.

    static bool isContainsCycle(Graph& g);
        Purpose: Checks if the graph contains any cycles.
        Implementation: Uses a modified DFS algorithm to mark nodes as visited and maintain a path stack to detect cycles during traversal. If a back edge to a visited node is encountered, it indicates the presence of a cycle.

    static bool isContainsCycleUtil(Graph& g, size_t src, std::vector<Color>* colors, std::vector<int>* parents, std::vector<int>* path);
        Purpose: Utility function used by isContainsCycle to detect cycles during DFS traversal.
        Implementation: Recursively explores adjacent vertices of the current vertex, marking visited nodes and checking for back edges to detect cycles. Maintains a path vector to track the cycle path if found.

    Installation

To use this library in your C++ project, follow these steps:
Clone the repository to your local machine:

$ git clone https://github.com/your_username/graph-algorithms.git

Navigate to the library director

$ cd graph-algorithms

Compile the library using your preferred C++ compiler:

$ g++ -std=c++11 -c Algorithms.cpp Graph.cpp

Link the compiled object files to your project:

$ g++ -std=c++11 -o your_program your_program.cpp Algorithms.o Graph.o

Include the necessary header files in your code:


    #include "Algorithms.hpp"
    #include "Graph.hpp"
 Now you can use the graph algorithms provided by this library in your project.



	


  
