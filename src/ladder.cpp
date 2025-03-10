#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg) {
    cout << word1 << " and " << word2 << " have error:" << msg << endl;
}

bool edit_distance_within(const string& str1, const string& str2, int d) { 

}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        return {begin_word};
    }
    
    queue<vector<string>> ladder_queue;
    ladder_queue.push(begin_word);
    set<string> visited;
    visited.insert(begin_word);
    
    while (!ladder_queue.empty()) {
        vector<string> cur_ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = cur_ladder.back();
        for (string word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.find(word)) {
                    visited.insert(word);
                    vector<string> new_ladder = cur_ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {};
}

void load_words(set<string> & word_list, const string& file_name) {

}

void print_word_ladder(const vector<string>& ladder) {
    for (auto c : ladder) {
        cout << c;
        if (!(c == ladder.end())) {
            cout << " -> ";
        }
    }
}

void verify_word_ladder() {

}