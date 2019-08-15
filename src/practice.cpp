#include <iostream>
#include <map>

using namespace std;

int main() {

    map<int, int> int_map;
    map<int, char> char_map;
    map<int, bool> bool_map;
    map<int, string> str_map;
    map<int, double> double_map;

    cout<<int_map[0]<<"\n";
    cout<<char_map[0]<<"\n";
    cout<<bool_map[0]<<"\n";
    cout<<str_map[0]<<"\n";
    cout<<double_map[0]<<"\n";

    return 0;
}