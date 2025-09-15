#include <iostream>
#define pii pair<int,int>
using namespace std;

int N;
pii point[100005];
int prefix[2][100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 1;i<=N;i++){
        cin>>point[i].first>>point[i].second;
    }
    
    for(int i = 2;i<=N;i++){
        prefix[0][i] = prefix[0][i-1] + (abs(point[i].first - point[i-1].first) + abs(point[i].second - point[i-1].second));
        if(i >= 3)
            prefix[1][i] = prefix[0][i-2] + (abs(point[i].first - point[i-2].first) + abs(point[i].second - point[i-2].second));

    }

    int answer = 987654321;


    for(int i = 3;i<=N;i++){
        
        int dist = prefix[1][i] + (prefix[0][N] - prefix[0][i]);
        
        answer = min(answer , dist);
    }

    cout<<answer;

}