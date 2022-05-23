#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int N;
int p[500005];
vector<int> a;
double round_digit(double num, int d) { double t = pow(10, d - 1); return round(num * t) / t; }
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>p[i];

    sort(p,p+N);

    int sum = 0;
    int maxn = 1;
    int n=1,nn=p[0];
    a.push_back(p[0]);
    for(int i = 0;i<N;i++){
        sum+=p[i];
        if(i>0){
            if(p[i]==p[i-1]){
                n++;
                
            }else n = 1;
            if(n>maxn){
                a.clear();
                maxn = n;
                nn = p[i];
                a.push_back(p[i]);
            }else if(n==maxn&&a.back()!=p[i]) a.push_back(p[i]);
        }
    }
    double mean = (double)sum/N;
    cout<<(int)round_digit(mean,1)<<"\n";
    cout<<p[N/2]<<"\n";
    if(a.size()==1) cout<<a.back()<<"\n";
    else cout<<a[1]<<"\n";
    cout<<p[N-1]-p[0];
}