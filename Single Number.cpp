class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());
        bool flag = 0; int i;
        for(i=0; i<nums.size()-1; i+=2) {
            if(nums[i] != nums[i+1]) {
                flag = 1;
                break;
            }
        }
        if(nums.size()%2) {
            if(flag == 0) return nums[nums.size()-1];
            else return nums[i];
        } else {
            return nums[i];
        }
    }
};
