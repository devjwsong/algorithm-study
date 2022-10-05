#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic programming.
Time: O(n)
Space: O(1)
*/
class Solution1 {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int n = damage.size();

        // noArmor: the current min sum of damages so far when I don't have an armor left.
        // withArmor: the current min sum of damages so far when I still have an armor.
        long long noArmor = max(0, damage[0]-armor);
        long long withArmor = damage[0];
        for (int i=1; i<n; ++i) {
            noArmor = min(withArmor + max(0, damage[i]-armor), noArmor + damage[i]);
            withArmor = withArmor + damage[i];
        }

        return min(noArmor, withArmor) + 1;
    }
};


/*
Greedy method.
Time: O(n)
Space: O(1)
Greedily, it is logical to think that the armor should be used when we take the maximum amount of damage.
Since if we use the armor when the damage is low, it would be the waste.
*/
class Solution2 {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int n = damage.size();
        int maxDam = 0;
        long long sum = 0;
        for (int i=0; i<n; ++i) {
            sum += damage[i];
            maxDam = max(maxDam, damage[i]);
        }

        return 1 + sum - min(maxDam, armor);
    }
};


int main() {
    
    int n;
    scanf("%d", &n);

    vector<int> damage;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        damage.push_back(val);
    }

    int armor;
    scanf("%d", &armor);

    Solution1 *sol1 = new Solution1();
    long long answer = sol1->minimumHealth(damage, armor);
    printf("%lld\n", answer);
}