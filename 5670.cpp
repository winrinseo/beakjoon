#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int N;

struct Node{
    bool end;
    bool r;//루트노드인지 판별
    int hasChild;
    map<char,Node*> child;
    Node():end(0),hasChild(0),r(0){}
    ~Node(){
        for(auto a : child){
            delete a.second;
        }
    }
};
void insert(Node* root, const char* key){
    if(*key == 0){
        root->end = true;
        return;
    } 
    if(root->child.find(*key)==root->child.end()){
        Node* newnode = new Node();
        root->child[*key] = newnode; 
    }
    insert(root->child[*key],key+1);
    root->hasChild = root->child.size();
}
int find(Node* root,const char* key,int put){
    //문자열을 끝가지 입력했을 경우
    if(*key == 0) return put;
    
    int num = root->hasChild < 2? 0 : 1;
    /*
    자식노드가 1개이지만 루트노드이거나 
    해당 노드에서 끝나는 노드가 있을 경우
    직접 입력해야함
    */
    if((root->end)||(root->r)&&root->hasChild==1) num=1;
    int ret = find(root->child[*key],key+1,put+num);
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> word;
    while(!cin.eof()){
        cin>>N;
        if(cin.eof()==true) break;
        word.clear();
        Node* root = new Node();
        root->r = true;
        for(int i = 0;i < N;i++){
            string s;cin>>s;
            word.push_back(s);
            insert(root,word[i].c_str());
        }
        double sum = 0.00;
        for(int i = 0;i<N;i++){
            sum += find(root,word[i].c_str(),0);
        }
        sum/=N;
        printf("%0.2f\n",sum);
        delete root;
    }
}