class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>ump;
        for(auto num:arr){
            ump[num]++;
        }
        multiset<int,greater<int>>mt;
        for(auto i:ump){
            mt.insert(i.second);
        }
        int m=n/2;
        int cnt=0;
        for(int a:mt){
            m-=a;
            cnt++;
            if(m<=0){
                break;
            }
        }
        return cnt;
    }
};