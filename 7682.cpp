#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
unordered_set<string> set;
bool isEnd(string& a){
    for(int i = 0;i<3;i++){
        //세로
        if(a[i] != '.' && a[i] == a[i + 3] && a[i + 3] == a[i + 6])
            return true;
        //가로
        if(a[(i * 3)] != '.' && a[(i * 3)] == a[(i * 3) + 1] && a[(i * 3) + 1] == a[(i * 3) + 2])
            return true;
    }
    //대각
    if(a[0] != '.' && a[0] == a[4] && a[4] == a[8])
        return true;
    if(a[2] != '.' && a[2] == a[4] && a[4] == a[6])
        return true;

    bool flag = true;
    for(int i = 0;i<9;i++)
        if(a[i] == '.')
            flag = false;
    if(flag) return true;
    return false;
}
void solve(string & a,int k){
    if(isEnd(a)){
        set.insert(a);
        return;
    }
    char c = k == -1 ? 'X' : 'O';
    for(int i = 0;i<9;i++){
        if(a[i] == '.'){
            a[i] = c;
            solve(a,(k*-1));
            a[i] = '.';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    string a = ".........";
    solve(a,-1);
    while(1){
        cin>>str;
        if(str == "end") break;
        if(set.find(str) == set.end()) cout<<"invalid"<<"\n";
        else cout<<"valid"<<"\n";
    }
}