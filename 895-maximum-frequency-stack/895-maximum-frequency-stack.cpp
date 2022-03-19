class FreqStack {
public:
    stack<int>stk;
    int timer=0,max_size;
    unordered_map<int,vector<int>>mp;
    unordered_map<int,vector<int>>mq;
    set<int,greater<int>>s;
    FreqStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        mp[val].push_back(timer);
        s.insert(mp[val].size());
        mq[mp[val].size()].push_back(val);
        timer++;
    }
    
    int pop() {
        int ele,t=-1;
        while(mq[*s.begin()].size()==0){
            s.erase(s.begin());
        }
        int max_size=*s.begin();
        ele=mq[max_size].back();
        mp[ele].pop_back();
        mq[max_size].pop_back();
        return ele;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */