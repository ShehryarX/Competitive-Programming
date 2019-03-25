#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> dict;
    map<int, string> reverseDict;
    string command = "";

    while (cin >> command) {
        if (command == "def") {
            string key;
            int val;
            cin >> key >> val;
            if (dict.find(key) == dict.end()) {
                dict.insert(make_pair(key, val));
                reverseDict.insert(make_pair(val, key));
            } else {
                dict[key] = val;
                reverseDict[val] = key;
            }
        } else if (command == "calc") {
            int res = 0;
            bool positive = true, undetermined = false;
            string token;

            do {
                cin >> token;

                if (token == "+") {
                    cout << " + ";
                    positive = true;
                } else if (token == "-") {
                    cout << " - ";
                    positive = false;
                } else if (token != "=") {
                    if (dict.find(token) == dict.end()) {
                        undetermined = true;
                    } else {
                        int val = dict[token];
                        res += positive ? val : -val;
                    }
                    cout << token;
                }
            } while (token != "=");

            if (undetermined || reverseDict.find(res) == reverseDict.end()) {
                cout << " = unknown" << endl;
            } else {
                cout << " = " << reverseDict[res] << endl;
            }
        } else if (command == "clear") {
          dict.clear();
          reverseDict.clear();
        } else {
          break;
        }
    }

    return 0;
}