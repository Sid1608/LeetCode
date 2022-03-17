class Solution {
public:
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
};