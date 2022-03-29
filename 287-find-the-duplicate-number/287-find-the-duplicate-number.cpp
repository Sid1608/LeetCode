class Solution {
public:
    int findDuplicate(vector<int>& a) {
        map<int,int>p;
        for(int i=0;i<a.size();i++){
            p[a[i]]++;
        }
        int ans;
        for(int i=0;i<a.size();i++){
            if(p[a[i]]>1){
                ans=a[i];
                break;
            }
        }
        return ans;
    }
};