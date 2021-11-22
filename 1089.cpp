#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int N;
//0~9층까지 비트마스킹으로 표현
int num[10];
//전광판의 상태
int p[10];
//i번째 전광판이 표현 가능한 숫자,[i][j]==true i-1번째 전광판이 숫자 j 표현 가능
bool isValid[10][10];
//만들 수 있는 숫자의 갯수
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	num[0] = 0b111101101101111, num[1] = 0b100100100100100, num[2] = 0b111001111100111;
	num[3] = 0b111100111100111, num[4] = 0b100100111101101, num[5] = 0b111100111001111;
	num[6] = 0b111101111001111, num[7] = 0b100100100100111, num[8] = 0b111101111101111;
	num[9] = 0b111100111101111;
	int width = (N * 3) + (N - 1);
	int height = 5;
	vector<string> board(height, string(width, '.'));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> board[i][j];
		}
	}
	int idx = 0;
	int pos = 0;
	//전광판 파싱
	while (1) {
		for (int w = pos; w < pos + 3; w++) {
			for (int h = 0; h < 5; h++) {
				if (board[h][w] == '#')
					p[idx] |= (1 << (h * 3 + w - pos));
			}
		}
		idx++;
		if (idx == N) break;
		pos += 4;
	}
	
	for (int i = 0; i < N; i++) {
		int s = 0;
		//i-1번째 전광판이 표현 한 것으로 예상되는 수
		for (int j = 0; j < 10; j++) {
			if (num[j] == (p[i] | num[j])) {
				isValid[i][j] = true;
				s++;
			}
			
		}
		if (s == 0) {
			cout << -1;
			return 0;
		}
	}
	double answer = 0;
	for (int i = 0; i < N; i++) {
		double a = 0;
		int n = 0;
		for (int j = 0; j < 10; j++) {
			if (isValid[i][j]) {
				n++;
				a += (j*pow(10,N-i-1));
			}
		}
		double dv = a / n;
		answer += dv;
	}
    
	printf("%lf", answer);
}