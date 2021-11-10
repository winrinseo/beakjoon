#include <iostream>
#include <string>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    string a[55];
    for(int i = 0;i<N;i++){
        cin>>a[i];
    }
    string answer = a[0];
    for(int i = 1;i<N;i++){
        for(int j = 0;j<a[i].size();j++){
            if(answer[j] != a[i][j]) answer[j] = '?'; 
        }
    }
    cout<<answer;
}