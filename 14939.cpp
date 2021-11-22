#include <iostream>
#include <vector>
#include <string.h>
#include <tuple>
#include <math.h>
#include <algorithm>
#define MAX_N 16
#define INF 987654321
using namespace std;
int N;
int board[10];
int temp[10];
void turn(int r, int c) {
	//up
	temp[r - 1] ^= 1 << c;
	//down
	if (r != 9) temp[r + 1] ^= 1 << c;
	//right
	if (c != 9) temp[r] ^= 1 << (c + 1);
	//left
	if (c != 0) temp[r] ^= 1 << (c - 1);
	//center
	temp[r] ^= 1 << c;
}
void init() {
	for (int i = 0; i < 10; i++)
		temp[i] = board[i];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < 10; j++) {
			char a;
			cin >> a;
			if (a == 'O') board[i] |= 1 << j;
		}
	int answer = INF;
	// t는 첫줄에 대한 모든 부분집합
	for (int t = 0; t < (1 << 10); t++) {
		//첫째줄은 윗줄이 없으므로 예외처리
		int cnt = 0;
		init();
		//가능한 첫째줄의 상태를 모두 확인한다.
		for (int i = 0; i < 10; i++) {
			//끌 수 있는 전구라면
			if (t & 1 << i) {
				turn(0, i);
				cnt++;
			}
		}
		//첫째줄의 상태가 정해졌다면 나머지줄에 대해 계산한다.
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				//현재 위치 전구의 위가 켜져있을경우 해당위치의 스위치를 누른다.
				if (temp[i - 1] & 1 << j) {
					turn(i, j);
					cnt++;
				}
			}
		}
		for (int i = 0; i < 10; i++)
			if (temp[i] != 0) {
				cnt = INF;
				break;
			}
		answer = min(answer, cnt);
	}
	answer = answer == INF ? -1 : answer;
	cout << answer;
}