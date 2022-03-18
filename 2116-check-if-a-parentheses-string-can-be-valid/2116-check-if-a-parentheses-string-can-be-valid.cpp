class Solution {
public:
    //()))
    //1011
    //((
    //11
    //consider ( as -1 and ( and +1
    //now each time you ecounter a unlocked state increase cnt
    //on encountering locked state increase bal by 1 if ( and decrease by 1 if )
    bool canBeValid(string s, string locked) {
        int n=s.size();
        int cnt=0,bal=0;
        if(n%2!=0)
            return false;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(locked[i]=='0'){
                    cnt++;
                }else{
                    bal++;
                }
            }else if(s[i]==')'){
                if(locked[i]=='0'){
                    cnt++;
                }else{
                    bal--;
                    if(bal==-1){
                        bal=0;
                        if(cnt){
                            cnt--;
                        }else{
                            return false;
                        }
                    }
                 
                }
            }
        }
    
      
        cnt=0,bal=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                if(locked[i]=='0'){
                    cnt++;
                }else{
                    bal++;
                }
            }else if(s[i]=='('){
                if(locked[i]=='0'){//)(
                    cnt++;
                }else{
                    bal--;
                    if(bal==-1){
                        bal=0;
                        if(cnt){
                            cnt--;
                        }else{
                            return false;
                        }
                    }
                   
                }
            }
        }
        return true;
    }
};