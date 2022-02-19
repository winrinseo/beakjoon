#include <iostream>
#include <string>
using namespace std;
int a;
string n;
int m = 1234567891;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>a>>n;
    long long c = 1;
    long long answer = 0;
    for(int i = 0;i<n.size();i++){
        long long s = n[i]-'a'+1;
        answer+=(s*c);
        answer%=m;
        c*=31;
        c %= m;
    }
    cout<<answer;
}