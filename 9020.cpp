#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int t,n;
vector<int> p;
bool check[10005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2;i<=10000;i++){
        if(check[i]) continue;
        p.push_back(i);
        for(int j = i*2;j<=10000;j+=i){
            check[j] = true;
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        int diff = 10001;
        int a[2] = {0};
        for(int i = 0;i<p.size();i++){
            for(int j = i;j<p.size();j++){
                if(p[i]+p[j] > n) break;
                if(p[i]+p[j] == n){
                    if(diff > abs(p[j]-p[i])){
                        diff = abs(p[j]-p[i]);
                        a[0] = p[i];a[1] = p[j];
                    }
                }
            }
        }
        cout<<a[0]<<" "<<a[1]<<"\n";
    }

}