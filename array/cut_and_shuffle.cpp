#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, const char **argv) {
    int n;
    cin >> n;
    vector<string> deck;
    deck.resize(n);
    for (auto &card : deck)
        cin >> card;
    cin.ignore();
    string commands;
    getline(cin, commands);
    for (auto &cmd : commands) {
        if (cmd == 'C') {
            for (int i = 0; i < n >> 1; i++)
                swap(deck[i], deck[i + (n >> 1)]);
        } else if (cmd == 'S') {
            vector<string> tmp;
            tmp.reserve(n);
            for (int i = 0; i < n >> 1; i++) {
                tmp.push_back(deck[i]);
                tmp.push_back(deck[i + (n >> 1)]);
            }
            deck = tmp;
        }
    }
    for (auto &card : deck)
        cout << card << ' ';
    return 0;
}