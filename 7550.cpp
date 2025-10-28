#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int T;
string p[3];
set<string> answer;
vector<string> word[3];
vector<string> split(string str){
    vector<string> ret;
    string s;

    for(int i = 0;i<str.size();i++){
        if(('A' <= str[i] && str[i] <= 'Z')
            ||('a' <= str[i] && str[i] <= 'z')){
                s.push_back(str[i] | 32); // 소문자 변환
        }else if(!s.empty()){
            ret.push_back(s);
            s.clear();
        }
    }

    if(!s.empty()){
        ret.push_back(s);
    }

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    int S = T;
    cin.ignore();
    while(T--){
        
        answer.clear();
        for(int i = 0;i<3;i++){
            getline(cin,p[i]);
        }
        
        
        vector<bool> visited[3];
        for(int i = 0;i<3;i++){
            
            word[i] = split(p[i]);
            visited[i].resize(word[i].size());
        }

       

        // 시작 지점
        for(int start = 0;start<word[0].size();start++){
            if(visited[0][start]) continue;
            visited[0][start] = true;

            int line = 0;
            int idx = start;

            while(line < 2){
                // 커서를 이동시킴
                idx += word[line][idx].size();
                //줄바꿈
                while(idx >= word[line].size() && line < 2){
                    idx -= word[line].size();
                    line++;
                }
                // 이미 방문한 단어면 더 반복할 필요 없음
                if(idx < word[line].size() && visited[line][idx])
                    break;

                if(idx < word[line].size())
                    visited[line][idx] = true;

                // 세번째 줄에 도달했으면
                if(line == 2){
                    if(idx >= word[line].size())
                        answer.insert("-outside-");
                    else answer.insert(word[line][idx]);
                }
            }
            
        }

        bool flag = false;
        if(answer.find("-outside-") != answer.end()){
            flag = true;
            answer.erase("-outside-");
        }
        cout<<"Scenario #"<<S-T<<":\n";
        if(answer.size() >= 3){
            cout<<"-too many-"<<"\n";
        }else{
            if(flag) cout<<"-outside-"<<"\n";
            for(auto it = answer.begin();it!=answer.end();it++)
                cout<<*it<<"\n";
        }
        cout<<"\n"; 
    }
}