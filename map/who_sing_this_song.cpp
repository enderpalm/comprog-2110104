#include <iostream>
#include <map>
#include <string>

using namespace std;

multimap<string, string> song2author;

int main(int argc, const char **argv) {
    int n;
    string raw;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, raw);
        size_t sep = raw.find(", ");
        string song = raw.substr(0, sep);
        string author = raw.substr(sep + 2);
        song2author.insert({song, author});
    }
    getline(cin, raw);
    raw += ", ";
    while (true) {
        size_t sep = raw.find(", ");
        if (sep == string::npos)
            break;
        string word = raw.substr(0, sep);
        raw = raw.substr(sep + 2);

        cout << word << " -> ";
        if (song2author.find(word) == song2author.end())
            cout << "Not found";
        else {
            auto runner = song2author.lower_bound(word);
            auto right = song2author.upper_bound(word);
            while (runner != right) {
                if (runner->first == word)
                    cout << runner->second;
                runner++;
                if (runner != right) cout << ", ";
            }
        }
        cout << '\n';
    }
    return 0;
}