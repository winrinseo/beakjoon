#include <iostream>
#include <string>
using namespace std;

int K;
char s[10];
bool visited[11];
void solve(int prev , int idx ,string & ans){

    if(ans.size() == K + 1){
        visited[10] = true;
        return;
    }

    int dir = s[idx] == '<' ? 1 : -1;

    for(int i = prev; (0 <= i && i <= 9); i += dir){
        
        if(!visited[i]){
            visited[i] = true;
            ans.push_back(i + '0');
            solve(i , idx+1 , ans);
            if(visited[10]) return;
            ans.pop_back();
            visited[i] = false;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>K;

    for(int i = 0;i<K;i++)
        cin>>s[i];

    string a , b;

    for(int i = 0;i<10;i++) {
            visited[i] = true;
            a.push_back(i + '0');
            solve(i , 0 , a);
            if(visited[10]) break;
            a.pop_back();
            visited[i] = false;
    }
    for(int i = 0;i<11;i++) visited[i] = false;
    for(int i = 9;i>=0;i--) {
            visited[i] = true;
            b.push_back(i + '0');
            solve(i , 0 , b);
            if(visited[10]) break;
            b.pop_back();
            visited[i] = false; 
    }
    cout<<b<<"\n"<<a;
}