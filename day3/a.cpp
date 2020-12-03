#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<string> tree_map;

    ifstream input;
    input.open("input.txt");
    string input_line;

    while (getline(input, input_line)) {
        tree_map.emplace_back(input_line);
    }
    input.close();

    auto n = tree_map.size();
    auto m = tree_map[0].length();

    pair<int, int> pos{0, 0};
    pair<int, int> move_vector{3, 1};

    int count = 0;

    for (;;) {
        pos.first = (pos.first + move_vector.first) % m;
        pos.second += move_vector.second;

        if (pos.second >= n) {
            break;
        }

        if (tree_map[pos.second][pos.first] == '#') {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}