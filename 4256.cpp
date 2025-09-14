#include <iostream>

using namespace std;


int T,N;
int preorder[1005];
int inorder[1005];
int r_idx;
void postorder(int s, int e){
    if(s > e) return;
    int root = preorder[r_idx++];
    
    for(int i = s;i<=e;i++){

        if(inorder[i] == root){

            postorder(s , i - 1);
            postorder(i + 1 , e);
            break;
        }
    }

    cout<<root<<" ";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;

    while(T--){
        cin>>N;

        for(int i = 0;i<N;i++)
            cin>>preorder[i];

        for(int i = 0;i<N;i++)
            cin>>inorder[i];

        r_idx = 0;
        postorder(0 , N-1);
        cout<<"\n";
    }
}