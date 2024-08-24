#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void anagram(string& src, int cnt) {
    do {
        cout << src << " ";
    }
    while (next_permutation(src.begin(), src.end()));
}

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string src;
    cin >> src;
    sort(src.begin(), src.end());
    anagram(src, 0);
    return 0;
}
