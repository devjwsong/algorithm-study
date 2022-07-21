#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;


class SummaryRanges1 {
public:
    set<int> st;

    SummaryRanges1() {

    }
    
    // O(logN)
    void addNum(int val) {
        st.insert(val);
    }
    
    // O(N)
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        vector<int> cur;
        for (auto iter=st.begin(); iter!=st.end(); ++iter) {
            if (cur.size() == 0) {
                cur = {*iter, *iter};
            } else {
                if (*iter == cur[1]+1) {
                    cur[1] = *iter;
                } else {
                    res.push_back(cur);
                    cur = {*iter, *iter};
                }
            }
        }
        res.push_back(cur);

        return res;
    }
};


class SummaryRanges2 {
public:
    vector<vector<int>> intervals;
    unordered_set<int> st;

    SummaryRanges2() {

    }
    
    /*
    Since this function is eventually O(N), so there is no need for binary search.
    But for reducting time, it is beneficial.
    */
    void addNum(int val) {
        if (st.find(val) != st.end()) return;
        st.insert(val);

        if (intervals.size() == 0) {
            intervals.push_back({val, val});
        }
        
        int n = intervals.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (val < intervals[mid][1]) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (val < intervals[left][0]) {
            if (val + 1 == intervals[left][0]) {
                intervals[left][0] = val;
            } else {
                intervals.insert(intervals.begin()+0, {val, val});
            }
        } else if (intervals[left][1] < val && val < intervals[right][0]) {
            if (val == intervals[left][1]+1 && val+1 == intervals[right][0]) {
                intervals[left][1] = intervals[right][1];
                for (int i = right; i<n-1; ++i) {
                    intervals[i] = intervals[i+1];
                }
                intervals.pop_back();
            } else if (val == intervals[left][1]+1) {
                intervals[left][1] = val;
            } else if (val+1 == intervals[right][0]) {
                intervals[right][0] = val;
            } else {
                intervals.push_back(intervals[n-1]);
                for (int i=n-1; i>right; --i) {
                    intervals[i] = intervals[i-1];
                }
                intervals[right] = {val,val};
            }
        } else if (val > intervals[right][1]) {
            if (intervals[right][1] + 1 == val) {
                intervals[right][1] = val;
            } else {
                intervals.push_back({val, val});
            }
        }
    }
    
    // O(1)
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */