#include <iostream>

using namespace std;

int N , Q;
int arr[305][305];
int prefix[305][305][11];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin>>arr[i][j];

            
            prefix[i][j][arr[i][j]]++;
            for(int k = 0;k<=10;k++)
                prefix[i][j][k] += prefix[i-1][j][k] + prefix[i][j-1][k] - prefix[i-1][j-1][k];
        }
        
    }

    
    cin>>Q;

    while(Q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        
        int answer = 0;
        
        for(int k = 0;k<=10;k++){
            int cnt = prefix[x2][y2][k] - prefix[x1-1][y2][k] - prefix[x2][y1-1][k] + prefix[x1-1][y1-1][k];
            
            if(cnt) answer++;
        }
        cout<<answer<<"\n";
    }
        
}