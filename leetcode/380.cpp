#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;


/*
Hash map + A little trick with an array.
We cannot directly randomly sample the number from the set or map. (That's not how the iterator works...)
So we have to make an array for random sampling.
Note that the first S elements in the array are currently living elements in the set, assuming S is the size of hash map.
So when inserting / removing, we should adjust the index to keep the actual elements in the hash map
to be located from 0 ~ S-1.
The rest of the elements in the array (S ~ L-1) have no meaning. (L: The length of array.)
Time: O(1).
Space: O(n).
*/
class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> vals;
    default_random_engine generator;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;

        vals.push_back(val);
        swap(vals[vals.size()-1], vals[mp.size()]);
        mp[val] = mp.size();
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;

        int idx = mp[val];
        swap(vals[idx], vals[mp.size()-1]);
        mp[vals[idx]] = idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int size = mp.size();
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