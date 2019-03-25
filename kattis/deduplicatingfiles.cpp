#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int hash_str(string str) {
    int res = 0;

    for (char &c : str) {
        res ^= c;
    }

    return res;
}

int main() {
    int n;

    cin >> n;

    while (n != 0) {
        vector<int> hashes;
        vector<string> dupes;
        string str;
        getline(cin, str);

        for (int i = 0; i < n; i++) {
            string str;
            getline(cin, str);
            dupes.push_back(str);
            int hash = hash_str(str);
            hashes.push_back(hash);
        }

        int uniques = n;
        int collisions = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (hashes[i] == hashes[j]) {
                    if (dupes[i] != dupes[j]) {
                        collisions++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dupes[i] == dupes[j]) {
                    uniques--;
                    break;
                }
            }
        }

        cout << uniques << " " << collisions << endl;
        cin >> n;
    }

    return 0;
}