#include <iostream>

using namespace std;

int T,N;
int arr[1005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        cin>>N;

        for(int i = 0;i<N;i++)
            cin>>arr[i];

        
        int sum = 0;
        int maxsum = -1005;
        for(int p = 0;p<N;p++){
            sum += arr[p];
            maxsum = max(maxsum , sum);
            if(sum < 0){
                sum = 0;
            }
        }
        cout<<maxsum<<"\n";
    }
}