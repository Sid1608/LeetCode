class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n%2==1)return false;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                else if(st.top()=='(' and (s[i]=='}'||s[i]==']'))
                    return false;
                else if(st.top()=='{' and (s[i]==']'||s[i]==')'))
                    return false;
                else if(st.top()=='[' and (s[i]=='}'||s[i]==')'))
                    return false;
                st.pop();
                    
            }
        }
        if(!st.empty())return false;
        return true;
    }
};