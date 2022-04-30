#include <iostream>
#include <unordered_map>

using namespace std;

// Hash map (Unicode included)
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> dict;
        for (int i=0; i<s.size(); ++i) {
            dict[s[i]] += 1;
        }

        for (int i=0; i<t.size(); ++i) {
            if (dict.find(t[i]) == dict.end() || dict[t[i]] == 0) {
                return false;
            }

            dict[t[i]] -= 1;
        }

        return true;
    }
};


// Array (only ASCII)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int counts[128] = {0, };

        for (int i=0; i<s.size(); ++i) {
            ++counts[s[i]-'\0'];
            --counts[t[i]-'\0'];
        }

        for (int i=0; i<128; ++i) {
            if (counts[i] != 0) return false;
        }

        return true;
    } 
};


int main() {

    string s, t;
    getline(cin, s);
    getline(cin, t);

    Solution1* sol1 = new Solution1();
    bool answer = sol1->isAnagram(s, t);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->isAnagram(s, t);
    printf("%d\n", answer);

    return 0;
}