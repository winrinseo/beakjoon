#include <iostream>
#include <algorithm>
using namespace std;
string N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int cnt = 0;
    while(N.size() > 1){
        int temp = 0;
        for(int i = 0;i<N.size();i++)
            temp+=N[i]-'0';
        N = to_string(temp);
        cnt++;
    }
    cout<<cnt<<"\n";
    if((N[0]-'0')%3==0) cout<<"YES";
    else cout<<"NO";
}