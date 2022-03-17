```cpp
space complexity: o(count of no of opening parenthesis)
time complexity: o(n)
int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int>st,x;
        int score=0;
        unordered_map<int,int>p;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
               
                if(st.size())
                    p[st.top()]++;
                st.push(i);
            }else{
                int temp=0;
                while(p[st.top()]--){
                    temp+=x.top();
                    x.pop();
                }
                if(temp==0)x.push(1);
                else x.push(2*temp);
                st.pop();
            }
        }
        while(x.size()){
            score+=x.top();
            x.pop();
        }
        return score;
    }
```

```cpp
space complexity: o(1)
time complexity: o(n)
int scoreOfParentheses(string s) {
        stack<int>st;
        int score=0;
        s="("+s+")";
         int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
               st.push(-1);
            }else{
                int temp=0;
                while(st.top()!=-1){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                if(temp==0)st.push(1);
                else st.push(2*temp);
            }
        }
        score=st.top()/2;
        return score;
    }
```




