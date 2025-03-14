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
    int length1 = str1.size();
    int length2 = str2.size();

    if (abs(length2-length1) > d) {
        return false;
    }

    int cnt = 0;
    int i = 0;
    int j = 0;

    while (i < length1 && j < length2) {
        if (str1[i] != str2[j]) {
            cnt++;
            if (cnt > d) {
                return false;
            }
            if (length1 > length2) { 
                i++; 
            } else if (length1 < length2) {
                j++;
            } else {
                i++; 
                j++;
            }
        } else {
            i++;
            j++;
        }
    }

    //cnt += length1 - i (length2 - j);
    cnt += abs(length1 - i - (length2 - j));
    return cnt <= d;
}


bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();

        for (const string& word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.count(word)) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
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
    ifstream infile(file_name);
    if (!infile) {
        cerr << "Unable to open file: " << file_name << endl;
        return;
    }

    string word;
    while (infile >> word) {
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder) {
    int len = ladder.size();
    if (len == 0) {
            cout << "No word ladder found.\n";
            return;
        }
    if (len > 0) {
            cout << "Word ladder found: ";
    }
    for (int i = 0; i < len; i++) {
        cout << ladder[i] << " ";
        // if (i != len-1) {
        //     cout << " -> ";
        // }
    }
    cout << endl;
}

void verify_word_ladder() {
    set<string> word_list;

    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    //vector<string> result1 = generate_word_ladder("cat", "dog", word_list);
    //print_word_ladder(result1);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    // result1 = generate_word_ladder("marty", "curls", word_list);
    // print_word_ladder(result1);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    // result1 = generate_word_ladder("code", "data", word_list);
    // print_word_ladder(result1);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    // result1 = generate_word_ladder("work", "play", word_list);
    // print_word_ladder(result1);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    // result1 = generate_word_ladder("sleep", "awake", word_list);
    // print_word_ladder(result1);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
    // result1 = generate_word_ladder("car", "cheat", word_list);
    // print_word_ladder(result1);
}