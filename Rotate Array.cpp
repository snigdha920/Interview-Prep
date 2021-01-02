class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        int n = end-start+1;
        for(int i=start; i<=start+(n-1)/2; i++) {
            swap(nums[i], nums[end-(i-start)]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums, 0, n-1);
        if(k >= 1) reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
        for(int i=0; i<n; i++) cout << nums[i] << " ";
        return;
    }
};
