#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;
int N;
int seg[4000005];
void update(int idx,int st,int ed,int i, int diff) {
	if (st == ed) {
		seg[idx] += diff;
		return;
	}
	seg[idx] += diff;
	if (i <= (st + ed) / 2) update(idx * 2, st, (st + ed) / 2, i, diff);
	else update(idx * 2+1, (st + ed) / 2+1, ed, i, diff);
}
//앞에서 n번째 사탕을 꺼내고 그 사탕의 맛을 반환한다.
//순서를 정확히 알기위해서 오른쪽 서브트리로 들어갈 때 ano에 반대편 서브트리의 값을 가져간다
int get_candy(int idx,int st,int ed,int n,int ano) {
	if (st == ed) {
		seg[idx] -= 1;
		return st;
	}
	seg[idx] -= 1;
	if (seg[idx * 2] + ano >= n) return get_candy(idx * 2, st, (st + ed) / 2, n, ano);
	else return get_candy(idx * 2+1, (st+ed)/2+1, ed, n, ano+seg[idx*2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 2) {
			int b, c;
			cin >> b >> c;
			update(1,1,1000000,b,c);
		}
		else {
			int b;
			cin >> b;
			cout << get_candy(1,1,1000000,b,0) << '\n';
		}
	}
	
}