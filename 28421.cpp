#include <iostream>
#include <cmath>
using namespace std;
int N , Q;
int p[10005];
int arr[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>Q;
    for(int i = 0;i<N;i++){
        cin>>arr[i];
        p[arr[i]]++;
    }


    while(Q--){
        int cmd , n;
        cin>>cmd>>n;


        if(cmd == 1){
            if(N == 1){
                cout<<0<<"\n";
                continue;
            }
            bool flag = false;
            if(n == 0 && p[0]){
                cout<<1<<"\n";
                continue;
            }

            for(int i = 1; i <= sqrt(n); i++){
                if(n % i != 0) continue;
                int lo = i;
                int hi = n / i;
                if(hi > 10000) continue;
                if((lo == hi && p[lo] >= 2) || (lo != hi && (p[lo] && p[hi]))){
                    flag = true;
                    cout<<1<<"\n";
                    break;
                }
            }
            if(!flag) cout<<0<<"\n";
        }else{
            if(arr[n - 1]) p[arr[n - 1]]--;
            if(arr[n - 1] != 0) p[0]++;
            arr[n-1] = 0;
        }
    }
}