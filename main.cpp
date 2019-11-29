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

    graph.resize(case_nodes);

    cout << endl << endl << "loading case with " << case_nodes << " nodes and " << case_links << " links" << endl;

    for(int i = 0; i < case_links; i++)
    {
        cin >> first >> second >> weight;

        add_edge(graph, first, second, weight);
    }
}


int main(){

    vector<vector<edge>> graph;

    int num_cases;
    cin >> num_cases;

    for(int i = 0; i < num_cases; i++)
    {
        load(graph);
        list_edges(graph);
    }


}