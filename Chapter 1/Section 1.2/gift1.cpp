/*
ID: jamesga4
TASK: gift1
LANG: C++14              
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;
    fin >> np;
    unordered_map<string, int> personToTotalMoney;
    vector<string> orderedNames;
    string name;
    for(int i = 0; i < np; i++) {
        fin >> name;
        personToTotalMoney[name] = 0;
        orderedNames.push_back(name);
    }
    string from, to;
    for(int i = 0; i < np; i++) {
        int amt, numPeop;
        fin >> from;
        fin >> amt >> numPeop;
        if(amt == 0 || numPeop == 0)
            continue;
        for(int k = 0; k < numPeop; k++) {
            fin >> to;
            personToTotalMoney[to] += amt/numPeop;
            personToTotalMoney[from] -= amt/numPeop;
        }
    }
    for(string& name:orderedNames) {
        fout << name << " " << personToTotalMoney[name] << endl;
    }
    return 0;
}