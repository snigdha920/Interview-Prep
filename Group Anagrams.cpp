vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mem;
        if(strs.size() == 1) {
            vector<string> temp;
            temp.push_back(strs[0]);
            ans.push_back(temp);
            return ans;
        }
        for(int i=0; i<strs.size(); i++) {
            string t = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mem[strs[i]].push_back(t);
        }
        for(auto it = mem.begin(); it != mem.end(); it++) {
            vector<string> temp;
            for(int i=0; i<it->second.size(); i++) {
                temp.push_back(it->second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
