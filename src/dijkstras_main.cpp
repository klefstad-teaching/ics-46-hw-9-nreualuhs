#include "dijkstras.h"
#include <iostream>

using namespace std;

int main() {
    Graph graph;

    file_to_graph("src/small.txt", graph);

    for (int dest = 0; dest < graph.numVertices; ++dest) {
        vector<int> previous;
        vector<int> distances = dijkstra_shortest_path(graph, 0, previous);
        vector<int> path = extract_shortest_path(distances, previous, dest);
        print_path(path, distances[dest]);
    }
}