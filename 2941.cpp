#include <iostream>

using namespace std;

string a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    int answer = 0;
    for(int i = 0;i<a.size();){
        
        if(a[i]=='c'){
            if(i<a.size()-1&&(a[i+1]=='='||a[i+1]=='-')) i+=2;
            else i+=1;
        }else if(a[i]=='d'){
            if(i<a.size()-2&&a[i+1]=='z'&&a[i+2]=='=') i+=3;
            else if(i<a.size()-1&&a[i+1]=='-') i+=2;
            else i+=1;
        }else if(i<a.size()-1&&(a[i]=='l'||a[i]=='n')){
            if(a[i+1]=='j') i+=2;
            else i+=1;
        }else if(i<a.size()-1&&(a[i]=='s'||a[i]=='z')){
            if(a[i+1]=='=') i+=2;
            else i+=1;
        }else i++;

        answer++;
    }
    cout<<answer;
}