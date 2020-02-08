#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int N;
vector<string> animals;
map<string, set<string>> aniToFea;

int main() {

    cin>>N;

    for(int i=0; i<N; ++i) {
        string name;
        cin>>name;
        animals.push_back(name);

        int K;
        cin>>K;

        for (int j=0; j<K; ++j) {
            string feature;
            cin>>feature;

            aniToFea[name].insert(feature);
        }
    }

    int result = 0;

    for (int i=0; i<animals.size(); ++i) {
        set<string> features = aniToFea[animals[i]];

        for (int j=i+1; j<animals.size(); ++j) {
            int count = 0;
            for (set<string>::iterator iter=features.begin(); iter!=features.end(); ++iter) {
                if (aniToFea[animals[j]].count(*iter) > 0) {
                    ++count;
                }
            }
            result = max(result, count);
        }
    }

    cout<<result+1<<"\n";

    return 0;
}