class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num1, num2;
        for(int i=0; i<nums1.size(); i++) {
            num1[nums1[i]] += 1;
            cout << nums1[i] << " : " << num1[nums1[i]] << endl;
        }
        for(int i=0; i<nums2.size(); i++) {
            num2[nums2[i]] += 1;
            cout << nums2[i] << " : " << num2[nums2[i]] << endl;
        }
        
        vector<int> result;
        set<int> done;
        for(int i=0; i<nums1.size(); i++) {
            if(done.find(nums1[i]) != done.end()) continue;
            if(num1.find(nums1[i]) != num1.end() && num2.find(nums1[i]) != num2.end()) {
                int count = min(num1[nums1[i]], num2[nums1[i]]);
                cout << count << " - count" << endl;
                for(int j=0; j<count; j++) {
                    result.push_back(nums1[i]);
                }
                done.insert(nums1[i]);
            }
        }
        return result;
    }
};
