class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mem;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(mem.find(target-nums[i]) != mem.end()) {
                ans.push_back(mem[target-nums[i]]);
                ans.push_back(i);
                return ans;
            } 
            mem[nums[i]] = i;
        }
        return ans;
    }
};
