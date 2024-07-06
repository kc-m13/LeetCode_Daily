class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;
        
        for(int i = 0; i< nums.size(); i++){
            if(cnt == 0)
                el = nums[i];
            
            if(el == nums[i])
                cnt++;
            else
                cnt--;
        }
        int cnt1 = 0;
        if(cnt!=0){
            for(int i = 0;i<nums.size();i++){
                if(nums[i]==el)
                    cnt1++;
            }
        }
        
        if(cnt1 > nums.size()/2)
            return el;
        
        return -1;
    }
};