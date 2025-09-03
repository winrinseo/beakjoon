#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T,N;

struct node{
    bool end = 0;
    node * child[10] = {0};
};

struct Trie{
    node * root;
    Trie(){ root = new node();}

    bool insert(char * c){
        return insert(root , c);
    }
    bool insert(node * cur , char * c){
        if(cur->end) return false;
        if(*c == 0){
            cur->end = true;
            return true;
        }

        if(cur->child[*c - '0'] == nullptr){
            cur->child[*c - '0'] = new node();
        }

        return insert(cur->child[*c - '0'] , c + 1);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        
        cin>>N;
        Trie trie;
        bool flag = true;
        vector<string> str;
        for(int i = 0;i<N;i++){
            string s;cin>>s;
            str.push_back(s);
        }
        sort(str.begin(),str.end(),[](string & a, string & b){
            return a.size() < b.size();
        });
        for(int i = 0;i<N;i++){
            flag = trie.insert((char*)str[i].c_str());
            if(!flag){
                cout<<"NO"<<"\n";
                break;
            }
        }
        if(flag){
            cout<<"YES"<<"\n";
        }    
    }
}