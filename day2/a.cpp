#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <regex>
#include <cassert>
#include <algorithm>

using namespace std;

int main() {
    regex input_regex(R"(^(\d+)-(\d+) (\w): (\w+)$)");

    ifstream input;
    input.open("input.txt");

    string line;
    smatch line_match;

    int valid_passwords = 0;

    while (getline(input, line)) {
        assert(regex_match(line, line_match, input_regex));

        int lower_bound = stoi(line_match[1].str());
        int upper_bound = stoi(line_match[2].str());
        char character = line_match[3].str()[0];
        string password = line_match[4].str();

        int occurrences = std::count(password.begin(), password.end(), character);

        if (lower_bound <= occurrences && occurrences <= upper_bound) {
            ++valid_passwords;
        }
    }
    input.close();

    cout << valid_passwords << endl;

    return 0;
}