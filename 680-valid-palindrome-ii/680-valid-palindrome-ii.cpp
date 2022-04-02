class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        int moves=1,flag=0;
        while(l<=r){
            if(s[l]==s[r]){
                l++,r--;
            }else{
                if(moves){
                    l++;
                    moves--;
                }else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
            return true;
        l=0,r=n-1;
        moves=1;
        while(l<=r){
            if(s[l]==s[r]){
                l++,r--;
            }else{
                if(moves){
                    r--;
                    moves--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};