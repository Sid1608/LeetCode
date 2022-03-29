class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int fast=a[0];
        int slow=a[0];
        do{
            slow=a[slow];
            fast=a[a[fast]];
            
        }while(fast!=slow);
        fast=a[0];
        while(fast!=slow){
            fast=a[fast];
            slow=a[slow];
        }
        return slow;
    }
};