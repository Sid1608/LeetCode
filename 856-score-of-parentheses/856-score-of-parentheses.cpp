class Solution {
public:
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
};