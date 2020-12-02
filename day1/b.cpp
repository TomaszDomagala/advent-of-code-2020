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

    for (auto a = entries.begin(); a != entries.end(); ++a) {
        for (auto b = entries.begin(); b != a; ++b) {

            if (entries.count(2020 - *a - *b)) {
                cout << *a * *b * (2020 - *a - *b) << endl;
                return 0;
            }
        }
    }

    return 0;
}