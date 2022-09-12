#include <iostream>
#include <stack>
#include <vector>
#define ll long long
using namespace std;
vector<string> order;
bool isEnd;
ll num[100005];
int idx, N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        isEnd = false;

        order.clear();
        order.reserve(100005);
        idx = 0;
        //숫자가 늘어나는 연산 , 줄어드는 연산
        int plus = 0 , minus = 0;
        while(1){
            string ord; cin>> ord;
            if(ord == "QUIT"){
                isEnd = true;
                break;
            }
            if(ord == "END"){
                break;
            }
            
            if(ord == "NUM"){
                ll a;cin>>a;
                num[idx++] = a;
            }
            if(ord == "NUM" || ord == "DUP") plus++;
            else if((ord == "INV") || (ord == "SWP")) {}
            else minus++;
            order.push_back(ord);
        }
        if(isEnd) break;
        bool gflag = true;
        // 스택에 수가 하나만 남지 않는 경우는 볼 필요도 없음
        if(1 + plus - minus != 1){
            gflag = false;
        }
        cin>>N;

        for(int n = 0;n<N;n++){
            ll a;cin>>a;
            // if(!gflag) {
            //     cout<<"ERROR"<<"\n";
            //     continue;
            // }
            bool flag = true;
            stack<ll> s;
            s.push(a);
            idx = 0;
            for(string & ord : order){

                if(ord == "NUM"){
                    s.push(num[idx++]);
                }else if(ord == "POP"){
                    if(s.empty()) flag = false;
                    else s.pop();
                }else if(ord == "INV"){
                    if(s.empty()) flag = false;
                    else {
                        ll t = s.top();s.pop();
                        s.push(-t);
                    }
                }else if(ord == "DUP"){
                    if(s.empty()) flag = false;
                    else s.push(s.top());
                }else if(ord == "SWP"){
                    if(s.size() < 2) flag = false;
                    else{
                        ll first = s.top(); s.pop();
                        ll second = s.top();s.pop();
                        s.push(first);
                        s.push(second);
                    }
                }else if(ord == "ADD"){
                    if(s.size() < 2) flag = false;
                    else{
                        ll first = s.top(); s.pop();
                        ll second = s.top();s.pop();
                        ll res = second + first;
                        if(abs(res) > 1e9) flag = false;
                        else s.push(res);
                    }
                }else if(ord == "SUB"){
                    if(s.size() < 2) flag = false;
                    else{
                        ll first = s.top(); s.pop();
                        ll second = s.top();s.pop();
                        ll res = second - first;
                        if(abs(res) > 1e9) flag = false;
                        else s.push(res);
                    }
                }else if(ord == "MUL"){
                    if(s.size() < 2) flag = false;
                    else{
                        ll res = s.top();s.pop();
                        res *= s.top();s.pop();
                        if(abs(res) > 1e9) flag = false;
                        else s.push(res);
                    }
                }else if(ord == "DIV"){
                    if(s.size() < 2) flag = false;
                    else{
                        int neg = 0;
                        ll first = s.top(); s.pop(); if(first < 0)  neg++;
                        ll second = s.top();s.pop(); if(second < 0) neg++;
                        if(first == 0) flag = false;
                        else {
                            ll res = abs(second) / abs(first);
                            if(neg == 1) res = -res;
                            s.push(res);
                        }
                    }
                }else if(ord == "MOD"){
                    if(s.size() < 2) flag = false;
                    else{
                        ll first = s.top(); s.pop();
                        ll second = s.top();s.pop();
                        if(first == 0) flag = false;
                        else{
                            ll res = abs(second) % abs(first);
                            if(second < 0) res = -res;
                            s.push(res);
                        }
                    }
                }
                if(!flag) break;
            }
            if(!flag || s.size() >= 2 || s.empty())
                cout<<"ERROR"<<"\n";
            else cout<<s.top()<<"\n"; 
        }

        cout<<"\n";

    }
}