class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        multiset<int>mt;
        for(int t:tokens){
            mt.insert(t);
        }
        int score=0,max_score=0;
        while(!mt.empty()){
            if(power>=*mt.begin()){
                score++;
                max_score=max(max_score,score);
                power-=*mt.begin();
                mt.erase(mt.begin());
            }else{
                if(score==0)break;
                power+=*mt.rbegin();
                auto it = prev(mt.end());
                mt.erase(it);
                score--;
            }
        }
        return max_score;
    }
};