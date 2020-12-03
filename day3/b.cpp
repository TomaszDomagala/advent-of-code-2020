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

    vector<pair<int, int>> move_vectors{
            {1, 1},
            {3, 1},
            {5, 1},
            {7, 1},
            {1, 2}
    };
    vector<pair<int, int>> positions(move_vectors.size());
    vector<long long> counts(move_vectors.size());

    for (int x = 0; x < n; ++x) {
        for (int i = 0; i < move_vectors.size(); ++i) {
            auto &pos = positions[i];
            const auto &vec = move_vectors[i];

            pos.first = (pos.first + vec.first) % m;
            pos.second += vec.second;

            if (pos.second < n && tree_map[pos.second][pos.first] == '#') {
                counts[i]++;
            }
        }
    }
    long long ans = 1;
    for (const auto &c:counts) {
        cout << c << endl;
        ans *= c;
    }

    cout << ans << endl;

    return 0;
}