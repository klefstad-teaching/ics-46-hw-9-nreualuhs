#include "dijkstras.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.size();

    vector<int> distances(n, INF);
    previous.resize(n, -1);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({source, 0});
    distances[source] = 0;

    while (!pq.empty()) {
        //int u = minHeap.extractVertexWithMinimumWeight().first;
        auto cur = pq.top();
        pq.pop();

        int u = cur.first;

        if (visited[u]) continue;

        visited[u] = true;

        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    // stack<int> stk;
    // int cur = destination;

    // while (cur != -1) {
    //     stk.push(cur);
    //     cur = previous[cur];
    // }

    // vector<int> path;
    // while (!stk.empty()) {
    //     path.push_back(stk.top());
    //     stk.pop();
    // }

    // return path;

    vector<int> path;
    for (int i = destination; i != -1; i = previous[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << " ";
    }
    cout << " \nTotal cost is " << total << "\n"; 
}