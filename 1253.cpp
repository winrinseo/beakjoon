#include <iostream>
#include <unordered_map>
using namespace std;
int N;
int p[2005];
unordered_map<int,int> m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>p[i];
        m[p[i]]++;
    }
    int answer = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(i == j) continue;
            if(m.find(p[i] - p[j]) != m.end()){
                if(p[i] == (p[i] - p[j])){
                    if(m[p[j]] > 2) {
                        answer++;
                        break;
                    }
                }else if(p[j] == (p[i] - p[j])){
                    if(m[p[j]] > 1) {
                        answer++;
                        break;
                    }
                }else {
                    answer++;
                    break;
                }
            }
        }
    }
    cout<<answer;
}