class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros=0;
        long long int product = 1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) zeros++;
            else product *= nums[i];
        }
        vector<int> ans;
        if(zeros > 1) {
            ans.resize(nums.size(), 0);
            return ans;
        }
        if(zeros == 1) {
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] != 0) ans.push_back(0);
                else ans.push_back(product);
            }
            return ans;
        }
        for(int i=0; i<nums.size(); i++) {
            int p = product/nums[i];
            ans.push_back(p);
        }
        return ans;
    }
};
