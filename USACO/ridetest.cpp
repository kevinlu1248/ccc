/*
ID: pradd1
PROG: ride
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("ride.out");
ifstream fin ("ride.in");

int main(){
    string s1;
    string s2;
    fin >> s1 >> s2;
    int prod1 = 1;
    for (int i=0;i<s1.size();++i){
        prod1 *= s1[i]-'A'+1;
    }
    int prod2 = 1;
    for (int i=0;i<s2.size();++i){
        prod2 *= s2[i]-'A'+1;
    }
    fout << (prod1%47==prod2%47?"GO":"STAY") << endl;
    return 0;
}