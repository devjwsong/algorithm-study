#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    bool isSatisfied(vector<int>& time, long long countLimit, int totalTrips) {
        int n = time.size();
        long long count = 0;
        for (int i=0; i<n; ++i) {
            count += (countLimit / time[i]);
        }

        return count >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int minTime = INT_MAX;
        for (int i=0; i<n; ++i) {
            minTime = min(minTime, time[i]);
        }
        long long maxNum = (long long) totalTrips * minTime;

        long long low = 1, high = maxNum;
        while (low + 1 < high) {
            long long mid = (low + high) / 2;
            bool res = isSatisfied(time, mid, totalTrips);

            if (!res) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (isSatisfied(time, low, totalTrips)) return low;
        return high;
    }
};
