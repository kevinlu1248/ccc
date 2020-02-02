// ccc13s2
// Created on 2020-02-01 6:33 p.m. by Kevin Lu
// Time on Task

/*
Sample Input 1
Copy

6
3
3
6
3

Output for Sample Input 1
Copy

2

Explanation of Output for Sample Input 1

Chores must be completed in at most 6 minutes. There are 3 chores available. The first chore takes 3 minutes. The second chore takes 6 minutes. The third chore takes 3 minutes. The answer is 2 since only 2 of these chores can be completed in 6 minutes of time. Specifically, the first and last chore can be completed in the allowable time. It is not possible to complete all 3 chores in 6 minutes.
Sample Input 2
Copy

6
5
5
4
3
2
1

Output for Sample Input 2
Copy

3
*/

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
const int C = 110;
int c, t, arr[C], ans;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d%d", &t, &c);
	for (int i = 0; i < c; i++) scanf("%d", &arr[i]);
	sort(arr, arr + c, cmp);
	//for (int i = 0; i < c; i++) printf("%d\n", arr[i]);
	while ((t -= arr[c--]) > 0) ans++;
	printf("%d", ans);
	return 0;
}