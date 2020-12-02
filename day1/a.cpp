#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int main() {

    ifstream input;
    input.open("input.txt");

    unordered_set<int> entries;

    int line;
    while (input >> line) {
        entries.insert(line);
    }
    input.close();

    for (auto a : entries) {
        if (entries.count(2020 - a)) {
            cout << a * (2020 - a) << endl;
            return 0;
        }
    }

    return 0;
}