#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> answer;
int maxsize = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<=N;i++){
        vector<int> a;
        a.push_back(N);
        a.push_back(i);
        while((a[a.size()-2]-a[a.size()-1])>=0)
            a.push_back((a[a.size()-2]-a[a.size()-1]));
        if(maxsize<a.size()){
            answer = a;
            maxsize = a.size();
        }
            
    }
    cout<<answer.size()<<"\n";
    for(int& a:answer)
        cout<<a<<" ";
}