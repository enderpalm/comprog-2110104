#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    while (getline(ss, line, delimiter)) {
        if (line.empty()) continue;
        tokens.push_back(line);
    }
    return tokens;
}

int main() {
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0])) {
        cout << '(' << e << ')';
    }
}