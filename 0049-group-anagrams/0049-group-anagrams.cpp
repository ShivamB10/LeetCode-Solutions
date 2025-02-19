class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            map[key].push_back(strs[i]);
        }

        for(auto it = map.begin(); it!= map.end(); ++it){
            ans.push_back(it->second);
        }

        return ans;
    }
};