#include <iostream>
#include <unordered_map>

using namespace std;
string str;
unordered_map<string , char> m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    m[".--"] = 'A';
    m["-."] = 'B';
    m["---"] = 'C';
    m[".."] = 'D';
    m["--.."] = 'E';
    m["--.-"] = 'F';
    m[".-."] = 'G';

    
    while(cin>>str){
        

        string c;
        string answer;

        for(int i = 0;i<str.size();){
            char min = 'Z';
            int next = -1;
            for(int j = i; j < i + 4;j++){
                if(j >= str.size()) break;
                c.push_back(str[j]);

                if(m.find(c) != m.end() && m[c] < min){
                    next = j;
                    min = m[c];
                }
            }

            if(next != -1){
                i = next + 1;
                answer.push_back(min);
                c.clear();
            }else{
                cout<<"could not be translated"<<"\n";
                answer.clear();
                break;
            }
            
        } 
        if(!answer.empty()) cout<<answer<<"\n";
        
    }
}