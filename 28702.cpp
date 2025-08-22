#include <iostream>

using namespace std;

string d[3];
int toInt(string str){
    int ret = 0;

    for(int i = 0;i<str.size();i++){
        ret *= 10;
        ret += (str[i] - '0');
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int idx = -1;
    for(int i = 0;i<3;i++){
        cin>>d[i];
        if(d[i][0] >= '0' &&d[i][0] <= '9')
            idx = i;
    }

    int answer = toInt(d[idx]) + (3 - idx);

    if(answer % 3 == 0 && answer % 5 == 0){
        cout<<"FizzBuzz";
    }else if(answer % 3 == 0){
        cout<<"Fizz";
    }else if(answer % 5 == 0){
        cout<<"Buzz";
    }else cout<<answer;
    
}