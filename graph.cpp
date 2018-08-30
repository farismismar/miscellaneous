#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    list<int> *adjacentLists;
    int graph_size;
    bool *visited;
    void unvisit() {for (int i = 0; i < graph_size; i++) visited[i] = false;}
public:
    Graph(int n);
    bool add_edge(int source, int dest);
    void bfs(int start);
    void dfs(int start);
    ~Graph();
};

Graph::Graph(int n)
{
    graph_size = n;
    adjacentLists = new list<int> [n];
    visited = new bool [n];
}

Graph::~Graph()
{
    delete [] adjacentLists;
    delete [] visited;
}

bool Graph::add_edge(int source, int dest)
{
    bool success = true;
    // this is an undirected graph, so add edges both ways.
    try {
        adjacentLists[source].push_back(dest);
        adjacentLists[dest].push_back(source);
    }
    catch (...) {
        success = false;
    }

    return success;
}

void Graph::bfs(int start)
{
    list<int> queue;
    unvisit();

    visited[start] = true;
    queue.push_back(start);
 
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();
 
        for(i = adjacentLists[currVertex].begin(); i != adjacentLists[currVertex].end(); i++) {
            int adjVertex = *i;
            if(!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

void Graph::dfs(int start)
{
    list<int> stack;
    unvisit();

    visited[start] = true;
    stack.push_front(start);
 
    list<int>::iterator i;
 
    while(!stack.empty())
    {
        int currVertex = stack.front();
        cout << "Visited " << currVertex << " ";
        stack.pop_front();
 
        // node the order of the traversal may cause a different solution to the DFS
        for(i = adjacentLists[currVertex].begin(); i != adjacentLists[currVertex].end(); i++) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                stack.push_front(adjVertex);
            }
        }
    }
}



// Driver program
int main()
{
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(2, 4);
    
    cout << "BFS" << endl;
    g.bfs(2);
    cout << "\nDFS" << endl;
    g.dfs(0);
 
    return 0;
}