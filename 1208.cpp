#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heights;
vector<int> results;

int main() {

    int numTest = 10;

    for (int test=1; test<=numTest; ++test) {
        int numDump = 0;
        cin>>numDump;

        for (int i=0; i<100; ++i) {
            int input = 0;
            cin>>input;
            heights.push_back(input);
        }

        int max_index = 0;
        int min_index = 0;

        for (int dump=0; dump<numDump; ++dump) {

            max_index = max_element(heights.begin(), heights.end()) - heights.begin();
            min_index = min_element(heights.begin(), heights.end()) - heights.begin();

            if (heights[max_index] - heights[min_index] <= 1) {
                break;
            }

            heights[max_index] -= 1;
            heights[min_index] += 1;

            if (dump == numDump - 1) {
                break;
            }
        }

        max_index = max_element(heights.begin(), heights.end()) - heights.begin();
        min_index = min_element(heights.begin(), heights.end()) - heights.begin();
        results.push_back(heights[max_index] - heights[min_index]);

        heights.clear();
    }

    for (int test=1; test<=numTest; ++test) {
        cout<<"#"<<test<<" "<<results[test-1]<<endl;
    }

    return 0;
}