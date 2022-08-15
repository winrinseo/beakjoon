#include <iostream>

using namespace std;
int N,S;
int arr[55];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        cin>>N;
        if(cin.eof()) break;
        for(int i = 0;i<N;i++)
            cin>>arr[i];
        cin>>S;
        for(int i = 0;i<N;i++){
            if(S == 0) break;
            int s = arr[i];
            int idx = i;
            for(int j = i+1;j<N;j++){
                if(s < arr[j]){
                    s = arr[j];
                    idx = j;
                }
                if(j == i+S) break;
            }

            for(int j = idx;j > i;j--){
                swap(arr[j],arr[j-1]);
            }
            S -= (idx - i);
            
        }

        for(int i = 0;i<N;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
}