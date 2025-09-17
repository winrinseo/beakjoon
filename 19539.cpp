#include <iostream>
#include <algorithm>

using namespace std;

int N;
int t[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int sum = 0;
    for(int i = 0;i<N;i++){
        cin>>t[i];
        sum += t[i];
    }
    
    if(sum % 3 != 0){
        cout<<"NO";
        return 0;
    }
    
    int one = sum /3;
    int two = sum /3;

    
    for(int i = 0;i<N;i++){
        int cnt_two = min(two , t[i]/2);
        t[i] -= (cnt_two * 2);
        two -= cnt_two;
        one -= t[i];
    }
    
    if(one == 0 && two == 0) cout<<"YES";
    else cout<<"NO";

}
