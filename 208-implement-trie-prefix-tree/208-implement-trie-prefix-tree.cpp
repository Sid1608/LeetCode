struct Node{
    Node *a[26];
    bool exist=false;
    
    bool isExist(int indx){
        if(a[indx]==nullptr)
            return false;
        return true;
    }
    void add(int indx,Node* node){
        a[indx]=node;
    }
    Node* nextNode(int indx){
        return a[indx];
    }
    void setExist(){
        exist=true;
    }
    bool isExist(){
        return exist;
    }
    
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        int n=word.size();
        Node * ptr=root;
        for(int i=0;i<n;i++){
            if(ptr->isExist(word[i]-'a')){
                ptr=ptr->nextNode(word[i]-'a');
            }else{
                ptr->add(word[i]-'a',new Node());
                ptr=ptr->nextNode(word[i]-'a');
            }
        }
        ptr->setExist();
    }
    
    bool search(string word) {
        int n=word.size();
        Node * ptr=root;
        for(int i=0;i<n;i++){
            if(ptr->isExist(word[i]-'a')){
                ptr=ptr->nextNode(word[i]-'a');
            }else{
                return false;
            }
        }
        return ptr->exist;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node * ptr=root;
        for(int i=0;i<n;i++){
            if(ptr->isExist(prefix[i]-'a')){
                ptr=ptr->nextNode(prefix[i]-'a');
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */