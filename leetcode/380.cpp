#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;


class RandomizedSet {
private:
    unordered_map<int, int> dict;
    vector<int> vals;
    default_random_engine generator;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (dict.find(val) == dict.end()) {
            vals.push_back(val);
            swap(vals[dict.size()], vals[vals.size()-1]);
            dict[val] = vals.size()-1;
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if (dict.find(val) != dict.end()) {
            int nextIdx = dict[val], prevIdx = dict.size()-1;
            swap(vals[nextIdx], vals[prevIdx]);
            dict[vals[nextIdx]] = nextIdx;
            dict.erase(val);
            return true;
        }

        return false;
    }
    
    int getRandom() {
        int size = dict.size();
        uniform_int_distribution<int> dist(0, size-1);
        int idx = dist(generator);
        return vals[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */