#include <iostream>

using namespace std;

int T;
string input1;
string input2;

int convert_to_second(string time) {
    int hours = atoi(time.substr(0, 2).c_str());
    int minutes = atoi(time.substr(3, 2).c_str());
    int seconds = atoi(time.substr(6, 2).c_str());

    return hours * 3600 + minutes * 60 + seconds;
}

string convert_to_string(int time) {
    string hours = to_string(time/3600);
    time %= 3600;
    string minutes = to_string(time/60);
    time %= 60;
    string seconds = to_string(time);

    if (hours.size() == 1) {
        hours = "0" + hours;
    }

    if (minutes.size() == 1) {
        minutes = "0" + minutes;
    }

    if (seconds.size() == 1) {
        seconds = "0" + seconds;
    }

    return hours + ":" + minutes + ":" + seconds;
}

int main() {

    cin>>T;
    for (int t=1; t<=T; ++t) {
        
        cin>>input1;
        cin>>input2;

        int cur = convert_to_second(input1);
        int pro = convert_to_second(input2);

        int remain = 0;
        if (pro >= cur) {
            remain = pro-cur;
        } else {
            remain = pro + 24*3600 - cur;
        }

        cout<<"#"<<t<<" "<<convert_to_string(remain)<<"\n";
    }

    return 0;
}