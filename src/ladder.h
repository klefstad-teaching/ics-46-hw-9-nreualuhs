#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void error(string word1, string word2, string msg);
bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
bool is_adjacent(const string& word1, const string& word2);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);
void load_words(set<string> & word_list, const string& file_name);
void print_word_ladder(const vector<string>& ladder);
void verify_word_ladder();
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

// VertexList bfs(const Graph& graph, Vertex startVertex) {
//     VertexList res;
//     vector<bool> visited(graph.size(), false);
//     queue<Vertex> queue;
//     visited[startVertex] = true;
//     queue.push(startVertex);

//     while (!queue.empty()) {
//         Vertex ver = queue.front();
//         queue.pop();
//         res.push_back(ver);
//         for (Vertex v : graph.edges_from(ver)) {
//             if (!visited[v]) {
//                 visited[v] = true;
//                 queue.push(v);
//             }
//         }
//     }
//     return res;
// }