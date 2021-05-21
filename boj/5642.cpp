#include <iostream>
#include <vector>

using namespace std;

int numTest = 0;
vector<int> inputs;
vector<int> results;

int main() {
    cin>>numTest;

    for (int i=1; i<=numTest; ++i) {
        int len = 0;
        cin>>len;

        for (int j=0; j<len; ++j) {
            int inputNum = 0;
            cin>>inputNum;
            inputs.push_back(inputNum);
        }

        int value = inputs[0];
        int max = value;

        for (int j=1; j<len; ++j) {
            if (value >= 0 && value + inputs[j] > 0) {
                value += inputs[j];
            } else {
                value = inputs[j];
            }

            if (max < value) {
                max = value;
            }
        }

        results.push_back(max);

        inputs.clear();
    }

    for (int i=1; i<=numTest; ++i) {
        cout<<"#"<<i<<" "<<results[i-1]<<endl;
    }

    return 0;
}