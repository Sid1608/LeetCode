class Solution {
public:
    int solve(string s,int l,int r){
        if(l>=r){
            return 0;
        }
        
        if(s[l]==s[r]){
            return solve(s,l+1,r-1);
        }else{
            int movesr=0,movesl=0,indx=-1,ans1=INT_MAX,ans2=INT_MAX;
            string x=s;
            for(int i=l+1;i<r;i++ ){
                if(s[i]==s[r]){
                    movesr=i-l;
                    indx=i;
                    break;
                }
            }
            if(indx!=-1){
                for(int i=indx;i>l;i--){
                    swap(s[i],s[i-1]);
                }
                ans1=movesr+solve(s,l+1,r-1);
            }
            indx=-1;
            for(int i=r-1;i>l;i--){
                if(x[i]==x[l]){
                    movesl=r-i;
                    indx=i;
                    break;
                }
            }
            if(indx!=-1){
                for(int i=indx;i<r;i++){
                    swap(x[i],x[i+1]);
                }
                ans2=movesr+solve(x,l+1,r-1);
            }
            return min(ans1,ans2);
        }
        
    }
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int ans=0;

        int l=0,r=n-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                int indx=-1;
                for(int i=r-1;i>l;i--){
                    if(s[i]==s[l]){
                        // movesl=r-i;
                        indx=i;
                        break;
                    }
                }
                if(indx!=-1){
                    for(int i=indx;i<r;i++){
                        swap(s[i],s[i+1]);
                        ans++;
                    }
                    l++,r--;
                }else{
                    for(int i=l+1;i<r;i++ ){
                        if(s[i]==s[r]){
                            // movesr=i-l;
                            indx=i;
                            break;
                        }
                    }
                    for(int i=indx;i>l;i--){
                        swap(s[i],s[i-1]);
                        ans++;
                    }
                    l++,r--;
                }
        }
        
    }
        return ans;
    }
};