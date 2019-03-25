#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    map<string, vector<int> > dict;

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string country;
        int year;
        cin >> country >> year;

        if (dict.find(country) == dict.end()) {
            dict.insert(make_pair(country, vector<int>()));
        }

        auto it = std::upper_bound(dict[country].cbegin(), dict[country].cend(),
                                   year);
        dict[country].insert(it, year);
    }

    map<string, vector<int> >::iterator it;

    for (it = dict.begin(); it != dict.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    int q = 0;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string country;
        int occurance;
        cin >> country >> occurance;

        cout << dict[country][occurance - 1] << endl;
    }

    cout << endl;

    return 0;
}