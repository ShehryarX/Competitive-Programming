#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string text;
    cin >> text;

    vector<char> res;

    for (char &c : text) {
        if (c == '<') {
            res.pop_back();
        } else {
            res.push_back(c);
        }
    }

    for (int i = 0; i < res.size(); i++) {
      cout << res[i];
    }

    cout << endl;

    return 0;
}