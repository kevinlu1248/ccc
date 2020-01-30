// ccc14s2
// Created on 2020-01-30 12:29 p.m. by Kevin Lu
// Assigning Partners

/*
4
Ada Alan Grace John
John Grace Alan Ada

good

Ada and John are partners, and Alan and Grace are partners. This arrangement is consistent.
Sample Input 2
Copy

7
Rich Graeme Michelle Sandy Vlado Ron Jacob
Ron Vlado Sandy Michelle Rich Graeme Jacob
*/

#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
int n, res = 1;
string a, b, arra[32], arrb[32];
unordered_map<string, string> map;

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) cin >> arra[i]; // scanf("%s", &arr[i]);
	for (int i = 0; i < n; i++) cin >> arrb[i];

	for (int i = 0; i < n; i++) {
		a = arra[i], b = arrb[i];
		if (a == b) {res = 0; break;}
		if (map[b] != a && map[b] != "") {res = 0; break;}
		map[a] = b;
	}

	printf("%s", res ? "good" : "bad");
	return 0;
}