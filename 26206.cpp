#include <iostream>


using namespace std;


int N,C;

string answer;
int cnt;
struct node{

    int end = 0;

    node * child[26] = {0};

    void insert(char * cur , string & input){
        if(*cur == 0){
            end++;
            
            if(cnt < end){
                answer = input;
                cnt = end;
            }else if(cnt == end){
                if(answer > input){
                    answer = input;
                }
            }
            return;
        }

        if(*cur == '*'){
            for(int i = 0;i<26;i++){
                if(!child[i]) child[i] = new node();
                input.push_back(i + 'a');
                child[i]->insert(cur + 1 , input);
                input.pop_back();
            }
        }else{
            if(!child[*cur - 'a']) child[*cur - 'a'] = new node();
            input.push_back(*cur);
            child[*cur - 'a']->insert(cur + 1 , input);
            input.pop_back();
        }
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>C;
    node * root = new node();
    for(int i = 0;i<N;i++){
        string str;cin>>str;
        string input;
        root->insert((char*)str.c_str() , input);
    }

    cout<<answer<<" "<<cnt;
}