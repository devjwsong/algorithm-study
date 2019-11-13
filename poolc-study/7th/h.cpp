#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> cows;

int tree[262144];

int power = 1;

void update(int leaf) {
    int index = leaf/2;

    while(1) {
        tree[index] = tree[index*2] + tree[index*2+1]; 

        if (index <= 1) {
            break;
        }
        
        index /= 2;
    }
}

int query(int left, int right) {
    int sum = 0;

    left += (power-1);
    right += (power-1);

    while(1) {
        if (left >= right) {
            break;
        }

        if (left % 2 == 1) {
            sum += tree[left];
            ++left;
        }

        if (right % 2 == 0) {
            sum +=tree[right];
            --right;
        }

        left /= 2;
        right /= 2;
    }

    sum += tree[left];

    return sum;
}

int main() {

    scanf("%d", &N);

    int idx = 0;

    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d", &p);
        cows.push_back(p);

        if (i > 0) {
            if (cows[i] > cows[i-1]) {
                continue;
            } else {
                idx = i;
            }
        } 
    }

    while(1) {
        if (power >= N) {
            break;
        }

        power *= 2;
    }

    for (int i=idx; i<N; ++i) {
        ++tree[power + cows[i]-1];
        update(power + cows[i]-1);
    }

    int k = idx;
    printf("%d\n", k);

    for (int i=0; i<k; ++i) {
        int val = 0;
        val += (idx-i-1);
        val += query(1, cows[i]);
        ++tree[power + cows[i] - 1];
        update(power + cows[i] - 1);
        printf("%d ", val);
    }
    
    printf("\n");

    return 0;
}