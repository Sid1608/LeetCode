class Trie{
    public:
    class TrieNode{
        public:
        TrieNode* left,*right;
        // TrieNode(){
        //     left=NULL;
        //     right=NULL;
        // }
    };
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    
    void Insert(int num){
        int bitIndex=30;
        TrieNode* curr=root;
        while(bitIndex>=0){
           int mask=(1<<bitIndex);
            int bit=(num&mask)>0?1:0;
            if(bit==0){
                if(curr->left==NULL){
                    curr->left=new TrieNode();
                }
                curr=curr->left;
            }else{
                if(curr->right==NULL){
                    curr->right=new TrieNode();
                }
                curr=curr->right;
            }
            bitIndex--;
        }
    }
    
    
    int query(int find ){
        int bitIndex=30;
        TrieNode* curr=root;
        int ans=0;
        while(bitIndex>=0){
            int mask=(1<<bitIndex);
            int bit=(find&mask)>0?1:0;
            
            if(bit==0){
                if(curr->left!=NULL){
                    curr=curr->left;
                }else{
                    ans|=mask;
                    curr=curr->right;
                }
            }else{
                if(curr->right!=NULL){
                    curr=curr->right;
                    ans|=mask;
                }else{
                    curr=curr->left;
                }
            }
            bitIndex--;
            
        }
        return ans;
    }
        
        
    
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie* trie=new Trie();
        for(int val:nums){
            trie->Insert(val);
        }
        int ans=0;
        for(int val:nums){
            int num=(1<<30)-1;
            int find=(INT_MAX)^ val;
            int res=trie->query(find);
            ans=max(ans,res^val);
        }
        return ans;
        
    }
};