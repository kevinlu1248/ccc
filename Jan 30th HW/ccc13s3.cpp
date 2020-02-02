// ccc13s3
// Created on 2020-02-01 7:01 p.m. by Kevin Lu
// Chances of Winning

/*
Sample Input 1
Copy

3
3
1 3 7 5
3 4 0 8
2 4 2 2

Output for Sample Input 1
Copy

0

Explanation of Output for Sample Input 1

Team 3 has lost two of its three games, and team 4 has tied one and won one, which gives 4 points to team 4. Even if team 3 wins its final game, it cannot have more points than team 4, and thus, will not be champion.
Sample Input 2
Copy

3
4
1 3 5 7
3 4 8 0
2 4 2 2
1 2 5 5

Output for Sample Input 2
Copy

9
*/

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int scores[4], t, g, a, b, sa, sb;
bool played[6]; // played[i] is if game i has been played
const int games[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
//const map<int[2], int> m = {{{0, 1}, 0}, {{0, 2}, 1}, {{0, 3}, 2}, {{1, 2}, 3}, {{1, 3}, 4}, {{2, 3}, 5}};
const int map[4][4] = { // map[i][j] is the corresponding game_no between i and j
		{-1, 0, 1, 2},
		{0, -1, 3, 4},
		{1, 3, -1, 5},
		{2, 4, 5, -1}
};

void printScores(int game_no) {
	for (int score: scores) printf("%d, ", score);
	printf("game_no: %d\n", game_no);
}

// checks if won
int didWin() {
	for (int i = 0; i < 4; i++)
		if (i != t - 1 && scores[t - 1] <= scores[i])
			return 0;
	return 1;
}

int solve(int game_no){
	//printScores(game_no);
	if (game_no == 6) return didWin();

	int ans = 0;
	//do {game_no++;} while (played[game_no]);
	while (played[game_no]) game_no++;
	if (game_no >= 6) return didWin();
	int t1 = games[game_no][0], t2 = games[game_no][1];

	// team 1 wins
	scores[t1] += 3;
	ans += solve(game_no + 1);
	scores[t1] -= 3;

	// team 2 wins
	scores[t2] += 3;
	ans += solve(game_no + 1);
	scores[t2] -= 3;

	// tie
	scores[t1]++; scores[t2]++;
	ans += solve(game_no + 1);
	scores[t1]--; scores[t2]--;

	return ans;
}

//// t1 < t2
//int solve(int tscores[4], int t1, int t2, bool tplayed[4][4]) {
//	int ans = 0;
//	if (t1 == 0 && t2 == 4) { // checking if t won (done)
//		return didWin(tscores);
//	}
//
//	// checking next case (next game: t1 and t2)
//	int nt1, nt2;
//	if (t1 == 3) {nt1 = 0; nt2 = t2 + 1;}
//	else {nt1 = t1 + 1; nt2 = t2;}
//	while (tplayed[nt1][nt2]) {
//		if (nt1 == 3 && nt2 == 3) return didWin(tscores);
//		if (nt1 == 3) {
//			nt1 = 0;
//			nt2++;
//		}
//		else {
//			nt1++;
//		}
//	}
//	tplayed[nt1][nt2] = true;
//
//	// t1 wins
//	tscores[t1] += 3;
//	ans += solve(tscores, nt1, nt2, tplayed);
//	tscores[t1] -= 3;
//
//	// t2 wins
//	tscores[t2] += 3;
//	ans += solve(tscores, nt1, nt2, tplayed);
//	tscores[t2] -= 3;
//
//	// tie
//	tscores[t1]++;
//	tscores[t2]++;
//	ans += solve(tscores, nt1, nt2, tplayed);
//	tscores[t1]--;
//	tscores[t2]--;
//
//	return ans;
//}

int main() {
	scanf("%d%d", &t, &g);

	// inputting
	for (int i = 0; i < g; i++) {
		scanf("%d%d%d%d", &a, &b, &sa, &sb);
		//printf("%d %d %d\n", a, b, map[a][b]);
		if (sa > sb) scores[a - 1] += 3;
		else if (sb > sa) scores[b - 1] += 3;
		else {scores[a - 1]++; scores[b - 1]++;}
		played[map[a - 1][b - 1]] = true;
 	}

	//for (int i = 0; i < 6; i++) printf("%d", played[i]);
	//for (int i = 0; i < 4; i++) printf("%d", scores[i]);

	printf("%d\n", solve(0));
	return 0;
}