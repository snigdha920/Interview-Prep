class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) break;
            while (i>0 && i<n && nums[i] == nums[i-1]) i++;
            int j=i+1, k=n-1; 
            while(j < k) {
                if(nums[i]+nums[j]+nums[k] > 0) k--;
                else if(nums[i]+nums[j]+nums[k] < 0) j++;
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    int nk = nums[k];
                    int nj = nums[j];
                    k--; j++; 
                    while(j < k && nums[k] == nk) k--;
                    while(j < k && nums[j] == nj) j++; 
                }
            }
        }
        return ans;
    }
};
