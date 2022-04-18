#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    vector<int> p(N);
    for(int i = 0;i < N;i++){
        cin>>p[i];
    }
    int answer = 0;
    sort(p.begin(),p.end());
    do{
        int sum = 0;
        for(int i = 1;i<N;i++)
            sum += abs(p[i-1]-p[i]);
        
        answer = max(answer,sum);
    }while(next_permutation(p.begin(),p.end()));
    cout<<answer;
}