class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<=0){
            return false;
        }
        long long a=log2(n);
        int b=log2(4);
        int y=a/b;
        long long x=pow(4,y);
        if(x==n){
            return true;
        }
        return false;
    }
};