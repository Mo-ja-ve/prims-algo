#include <stdio.h>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

typedef struct edge_t{

    int v;//  neighbour vector
    int weight;//  weight of that path
}edge;


void add_edge(vector<vector<edge>> &graph, int first, int second, int weight){

    edge temp;
    
    temp.v = second;
    temp.weight = weight;

    cout << "adding an edge between " << first << " and " << second << " with weight " << weight << endl;

    graph[first].push_back(temp);

    temp.v = first;

    graph[second].push_back(temp);
}


void list_edges(vector<vector<edge>> graph){

    if(!graph.empty()){

        for(int i = 0; i < graph.size(); i++)
        {
            cout << "node " << i << " has links to: ";
            if(!graph[i].empty())
            {
                for(int j = 0; j < graph[i].size(); j++)
                {
                    cout << graph[i][j].v << "(" << graph[i][j].weight << ") ";
                }
                cout << endl;
            }else
            {
                cout<< " no other nodes" << endl;
            }

        }
    }else{

        std::cout<<std::endl<<"Graph is empty!"<<std::endl<<std::endl;
    }
}

void load(vector<vector<edge > > &graph){

    graph.clear();

    int case_nodes;
    int case_links;

    int first, second, weight;

    cin >> case_nodes >> case_links;

    cout << endl << endl << "loading case with " << case_nodes << " nodes and " << case_links << " links" << endl;

    graph.resize(case_nodes);

    for(int i = 0; i < case_links; i++)
    {
        cout << " taking in number " << i << endl;
        cin >> first >> second >> weight;

        add_edge(graph, first, second, weight);
    }
}

// void primMST(vector<pair<int,int> > adj[], int V)
// {
//     // Create a priority queue to store vertices that
//     // are being preinMST. This is weird syntax in C++.
//     // Refer below link for details of this syntax
//     // http://geeksquiz.com/implement-min-heap-using-stl/
//     priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

//     int src = 0; // Taking vertex 0 as source

//     // Create a vector for keys and initialize all
//     // keys as infinite (INF)
//     vector<int> key(V, INF);

//     // To store parent array which in turn store MST
//     vector<int> parent(V, -1);

//     // To keep track of vertices included in MST
//     vector<bool> inMST(V, false);

//     // Insert source itself in priority queue and initialize
//     // its key as 0.
//     pq.push(make_pair(0, src));
//     key[src] = 0;

//     /* Looping till priority queue becomes empty */
//     while (!pq.empty())
//     {
//         // The first vertex in pair is the minimum key
//         // vertex, extract it from priority queue.
//         // vertex label is stored in second of pair (it
//         // has to be done this way to keep the vertices
//         // sorted key (key must be first item
//         // in pair)
//         int u = pq.top().second;
//         pq.pop();

//         inMST[u] = true; // Include vertex in MST

//         // Traverse all adjacent of u
//         for (auto x : adj[u])
//         {
//             // Get vertex label and weight of current adjacent
//             // of u.
//             int v = x.first;
//             int weight = x.second;

//             // If v is not in MST and weight of (u,v) is smaller
//             // than current key of v
//             if (inMST[v] == false && key[v] > weight)
//             {
//                 // Updating key of v
//                 key[v] = weight;
//                 pq.push(make_pair(key[v], v));
//                 parent[v] = u;
//             }
//         }
//     }

//     // Print edges of MST using parent array
//     for (int i = 1; i < V; ++i)
//         printf("%d - %d\n", parent[i], i);
// }

void print_mst(vector<vector<edge>> graph)
{

}

int main(){

    //the representation of the graph is a vector
    //each element of this vector represents a node in the graph
    // it, in turn, is a vector of connections to other nodes, along with the weights of those connections
    vector<vector<edge>> graph;

    int num_cases;
    cin >> num_cases;

    cout << "handling " << num_cases << " case(s)" << endl;

    for(int i = 0; i < num_cases; i++)
    {
        load(graph);
        list_edges(graph);
    }


}
