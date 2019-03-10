#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heights;
vector<int> results;

int main() {

    int numTest = 10;

    for (int test=1; test<=numTest; ++test) {

        int len = 0;
        cin>>len;

        for (int i=0; i<len; ++i) {
            int height = 0;
            cin>>height;
            heights.push_back(height);
        }

        int value = 0;

        for (int i=0; i<len; ++i) {
            if (heights[i] != 0) {
                if (heights[i] > heights[i-1] &&
                        heights[i] > heights[i-2] &&
                        heights[i] > heights[i+1] &&
                        heights[i] > heights[i+2]) {
                    int maxHeight = max(max(heights[i-1], heights[i-2]), max(heights[i+1], heights[i+2]));
                    value += (heights[i] - maxHeight);
                }
            }
        }

        results.push_back(value);

        heights.clear();

    }

    for (int test=1; test<=numTest; ++test) {
        cout<<"#"<<test<<" "<<results[test-1]<<endl;
    }

    return 0;
}