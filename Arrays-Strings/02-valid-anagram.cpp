
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    vector<int> count(26, 0);

    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int frequency : count) {
        if (frequency != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << boolalpha;
    cout << isAnagram("anagram", "nagaram") << endl;
    cout << isAnagram("rat", "car") << endl;
    return 0;
}