#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    list<int> *adjacentLists;
    int graph_size;
    bool *visited;
    void unvisit() {for (int i = 0; i < graph_size; i++) visited[i] = false;}
    void DFSUtil(int, bool []);
public:
    Graph(int n);
    bool add_edge(int source, int dest);
    void bfs(int start);
    void dfs_rec(int start);
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

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << "Visited " << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adjacentLists[v].begin(); i != adjacentLists[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
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
 
    while(!queue.empty()) {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();
 
        for(i = adjacentLists[currVertex].begin(); i != adjacentLists[currVertex].end(); i++) {
            int adjVertex = *i;
            if(!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

// DFS traversal
void Graph::dfs_rec(int v)
{
    unvisit();
 
    // Call the recursive function
    DFSUtil(v, visited);
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
    cout << "\nDFS Rec" << endl;
    g.dfs_rec(2);
 
    return 0;
}