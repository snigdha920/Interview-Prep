class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> track;
        vector<int> ans;
        for(int i=0; i<k; i++) {
            track[nums[i]]=i;
        }
        ans.push_back(track.rbegin()->first);
        for(int i=k; i<nums.size(); i++) {
            track[nums[i]]=i;
            auto it = track.rbegin();
            vector<int> deleteVals;
            while(it->second <= (i-k)) {
                int deleteVal = it->first;
                deleteVals.push_back(deleteVal);
                it++;
                // track.erase(deleteVal);
                cout << "deleteVal : " << deleteVal << ", at i : " << i << endl;
            }
            for(int j=0; j<deleteVals.size(); j++) {
                track.erase(deleteVals[j]);
            }
            ans.push_back(track.rbegin()->first);
        }
        return ans;
    }
};
