class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        int even=1,odd=0;
        int currSum=0,res=0;
        for(auto x:arr){
            currSum+=x;
            if(currSum%2==0){
                res+=odd;
                even++;
            }else{
                res+=even;
                odd++;
            }
            res%=mod;
        }
        return res;
    }
};