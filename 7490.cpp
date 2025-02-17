#include <iostream>
#include <deque>
using namespace std;

int T , N;
string s;
deque<int> q;
void solve(int depth){
    if(depth == N){
        q.clear();
        int sum = 0;
        q.push_back(1);
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                int b = q.back();q.pop_back();
                q.push_back(b * 10 + (i + 2));
            }else{
                q.push_back(i+2);
            }
        }
        sum += q.front(); q.pop_front();

        for(int i = 0;i<s.size();i++){
            if(s[i] == ' ')
                continue;
            
            if(s[i] == '+'){
                sum += q.front();q.pop_front();
            }else{
                sum -= q.front();q.pop_front();
            }   
        }


        if(sum == 0){
            cout<<1;
            for(int i = 0;i<s.size();i++){
                cout<<s[i];
                cout<<i+2;
            }
            cout<<"\n";
        }
        return;
    }

    //" "
    s.push_back(' ');
    solve(depth + 1);
    s.pop_back();

    //+
    s.push_back('+');
    solve(depth + 1);
    s.pop_back();

    //-
    s.push_back('-');
    solve(depth + 1);
    s.pop_back();

   
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        cin>>N;

        solve(1);
        cout<<"\n";
    }
}