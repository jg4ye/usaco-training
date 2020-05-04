/*
ID: jamesga4
TASK: ride
LANG: C++14              
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string commet, group;
    fin >> commet >> group;
    int commetInt = 1, groupInt = 1;
    for(char c : commet)
        commetInt *= c - 'A' + 1;
    for(char c : group)
        groupInt *= c - 'A' + 1;
    if(commetInt%47 == groupInt%47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}