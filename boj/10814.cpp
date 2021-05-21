#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<struct Person> people;

struct Person {
    Person(int _age, string _name, int _index) {
        age = _age;
        name = _name;
        index = _index;
    }

    int age;
    string name;
    int index;

    bool operator < (struct Person& other) {
        if (age < other.age) {
            return true;
        } else if (age > other.age) {
            return false;
        } else {
            return index < other.index;
        }
    }
};

int main() {

    cin>>N;

    for (int i=0; i<N; ++i) {
        int age;
        string name;
        cin>>age>>name;

        struct Person p (age, name, i);
        people.push_back(p);
    }

    sort(people.begin(), people.end());

    for (int i=0; i<people.size(); ++i) {
        cout<<people[i].age<<" "<<people[i].name<<"\n";
    }

    return 0;
}