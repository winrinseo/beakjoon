/*
국제기업 조이 코퍼레이션은 전세계에 여러 지점이 있다. 
기업의 프로젝트 리더 YJ는 해외의 많은 사람들과 협력하길 원한다.
그러나 그는 해외 협업자들이 미팅시간을 그들의 현지 시간으로 알 수 있도록 배려하지 않는다고 악명높다.

YJ의 배려 부족에 놀란 그의 비서 MH는 협업자들 각자의 time zone으로 메일을 다시 작성했습니다.
MH는 메일에 모든 협력자들의 time zone을 작성하는 것에 재능있다.
Time zones은 아래와 같이 UTC와 정수D(-12<=D<=12)의 차이로 정의된다.
Korea : UTC+9

그러나 조이 코퍼레이션은 평양에도 지점이 있는데 평양 지점은 최근에 time zone을 UTC+8.5로 변경했다.
결과적으로 MH의 노트엔 정수부뿐만 아니라 추가적인 소수부가 조금 보였다. ex)UTC-3.5

YJ의 time zone 기준의 미팅 시간과 YJ와 협력하는 모든 협력자들의 time zone이 주어진다.
각 협력자들의 미팅 시간을 계산해라.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string t , utc;

vector<string> split(string str , bool & sign){
    
    vector<string> ret;
    string s;
    for(int i = 0;i<str.size();i++){
        if(str[i] == '+'){
            sign = 1;
            ret.push_back(s);
            s.clear();
        }else if(str[i] == '-'){
            sign = 0;
            ret.push_back(s);
            s.clear();
        }else if(str[i] == '.' || str[i] == ':'){
            ret.push_back(s);
            s.clear();
        }else{
            s.push_back(str[i]);
        }
    }
    if(!s.empty()) ret.push_back(s);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>N;
    cin>>t>>utc;

    bool sign = 0;
    vector<string> time = split(t,sign);

    int origin = stoi(time[0]) * 60 + stoi(time[1]);

    time = split(utc,sign);
    time.push_back("0");
    int diff = stoi(time[1]) * 60;
   
    if(!sign) origin += (diff + (60 * stoi(time[2]) / 10));
    else origin -= (diff + (60 * stoi(time[2]) / 10));

    origin += 1440;
    origin %= 1440;
    
    for(int i = 0;i<N;i++){
        string str;cin>>str;

        int local = origin;

        time = split(str,sign);
        time.push_back("0");
        diff = stoi(time[1]) * 60;
        
        if(sign) local += (diff + (60 * stoi(time[2]) / 10));
        else local -= (diff + (60 * stoi(time[2]) / 10));

        local += 1440;
        local %= 1440;
        
        int H = (local / 60) % 24;
        int M = local % 60;
        if(H < 10) cout<<"0";
        cout<<H<<":";
        if(M < 10) cout<<"0";
        cout<<M;
        cout<<"\n";
    }
}