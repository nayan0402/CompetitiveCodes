//To calculate the maximum XOR of a subarray just take the input and run it

#include <bits/stdc++.h>
using namespace std;
#define int long long

bool secondsort(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

struct TrieNode{
    int value;
    TrieNode *child[2];
    TrieNode(){
        this->value = 0;
        this->child[0] = this->child[1] = NULL;
    }
};

class Solution{   
public:
    void insert(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=31;i>=0;i--){
            bool curr  = pre_xor & (1<<i);
            if(temp->child[curr]==NULL){
                temp->child[curr] = new TrieNode();
            }
            temp = temp->child[curr];
        }
        temp->value=pre_xor;
    }
    int query(TrieNode *root,int pre_xor){
        TrieNode *temp = root;
        for(int i=31;i>=0;i--){
            bool curr = pre_xor & (1<<i);
            if(temp->child[1-curr] != NULL){
                temp = temp->child[1-curr];
            }else if(temp->child[curr] != NULL){
                temp = temp->child[curr];
                
            }
        }
        return pre_xor^(temp->value);
    }
    int maxSubarrayXOR(int N, int arr[]){    
        TrieNode *root = new TrieNode();
        insert(root,0);
        int result = INT_MIN,pre_xor=0;
        for(int i=0;i<N;i++){
            pre_xor= pre_xor^arr[i];
            insert(root,pre_xor);
            result = max(result,query(root,pre_xor));
        }
        return result;
    }
};

void solve() {
    int n, i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    Solution ob;
    cout<<ob.maxSubarrayXOR(n, a)<<endl;
}

int32_t main() {
    int TT = 1;
    cin >> TT;

    while (TT--) {
        solve();
    }

    return 0;
}
