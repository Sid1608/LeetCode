class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
         vector<string>ans;
        if(n==0)return ans;
        int num=nums[0],cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==num+cnt){
              
                cnt++;
            }else{
                string temp="";
                if(cnt==1){
                    temp+=to_string(num);
                    ans.push_back(temp);
                   
                }else{
                    temp+=to_string(num)+"->"+to_string(nums[i-1]);
                    ans.push_back(temp);
                }
                cnt=1;
                num=nums[i];
            }
        }
        string temp="";
        if(cnt==1){
            temp+=to_string(num);
            ans.push_back(temp);

        }else{
            temp+=to_string(num)+"->"+to_string(nums[n-1]);
            ans.push_back(temp);
        }
        return ans;
        
    }
};