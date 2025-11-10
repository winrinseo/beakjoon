#include <iostream>
#include <unordered_set>

using namespace std;

int N;
int p[25];
unordered_set<int> s;
int answer;
void solve(int cur , int sum){
    if(cur == N){
        if(sum == 0) return;
        if(s.find(sum) == s.end()){
            s.insert(sum);
            answer--;
        }
        return;
    }

    solve(cur + 1 , sum + p[cur]);
    solve(cur + 1 , sum);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        cin>>p[i];
        answer += p[i];
    }

    solve(0 , 0);

    cout<<answer;
}