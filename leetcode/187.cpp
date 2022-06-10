#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// string hash map.
class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> counts;
        for (int i=0; i<=n-10; ++i) {
            ++counts[s.substr(i, 10)];
        }
        
        vector<string> answer;
        for (auto iter=counts.begin(); iter != counts.end(); ++iter) {
            if (iter->second > 1) answer.push_back(iter->first);
        }
        
        return answer;
    }
};


// int(bit) hash map.
class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> answer;

        if (n < 11) return answer;

        unordered_map<int, int> counts;
        unordered_map<char, int> char2int = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

        int seq = 0, mask = (1 << 20) - 1;  // Mask is for cutting the sequnece to 20-bit integer always.
        for (int i=0; i<n; ++i) {
            seq = ((seq << 2) | char2int[s[i]]) & mask;
            if (counts.find(seq) != counts.end() && counts[seq] == 1) {
                answer.push_back(s.substr(i-9, 10));
            }
            if (i >= 9) ++counts[seq];
        }
        
        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution1* sol1 = new Solution1();
    vector<string> answer = sol1->findRepeatedDnaSequences(s);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    Solution2* sol2 = new Solution2();
    answer = sol2->findRepeatedDnaSequences(s);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}