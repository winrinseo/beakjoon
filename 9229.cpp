#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string first;
        bool flag = true;
        cin>>first;
        if(first == "#") break;

        while(1){
            string second;
            cin>>second;
            if(second == "#") break;
            int n = 0;
            for(int i = 0;i<second.size();i++){
                if(first.size() != second.size()){
                    flag = false;
                    break;
                }
                if(first[i] != second[i]) n++;
            }
            if(n >= 2 || n == 0) flag = false;
            first = second;
            
        }

        if(flag) cout<<"Correct"<<"\n";
        else cout<<"Incorrect"<<"\n";
    }
}