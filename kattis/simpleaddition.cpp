#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class BigInteger {
   public:
    list<int> numberList;

    BigInteger(string s) {
        for (int i = 0; i < s.size(); i++) {
            numberList.push_front(s[i] - '0');
        }
    }

    bool isEmpty() { return numberList.empty(); }

    void add(BigInteger &other) {
        int carry = 0, sum = 0;
        vector<int> result;

        while (!isEmpty() || !other.isEmpty()) {
            if (!isEmpty() && !other.isEmpty()) {
                sum = numberList.front() + other.numberList.front() + carry;
                numberList.pop_front();
                other.numberList.pop_front();
            } else if (!isEmpty()) {
                sum = numberList.front() + carry;
                numberList.pop_front();
            } else {
                sum = other.numberList.front() + carry;
                other.numberList.pop_front();
            }

            carry = sum / 10;
            sum %= 10;

            result.push_back(sum);
        }

        if (carry != 0) {
            result.push_back(carry);
        }

        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }
    }
};

int main(void) {
    string a, b;

    cin >> a;
    cin >> b;

    BigInteger b1(a);
    BigInteger b2(b);

    b1.add(b2);

    cout << endl;

    return 0;
}