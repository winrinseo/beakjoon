#include <iostream>

using namespace std;

int T,N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>N;
        string a,b;
        cin>>a>>b;
        int ans = 0;
        for(int i = 0;i<N-1;i++){
            if(a[i] != b[i]){
                a[i] += 1;
                if(a[i] == '2') a[i] = '0';
                a[i+1] += 1;
                if(a[i+1] == '2') a[i+1] = '0';
                ans++;
            }
        }

        if(a[N-1] != b[N-1]) cout<<-1;
        else cout<<ans;
        cout<<"\n";
    }
}