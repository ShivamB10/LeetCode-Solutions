class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> unique;
        unordered_set<int> nums2Set(nums2.begin(),nums2.end());
        vector<int> result;


        for(int i = 0; i < nums1.size(); i++){
            if(nums2Set.find(nums1[i]) != nums2Set.end()){
                unique.insert(nums1[i]);
            }
        }

        for(auto it = unique.begin(); it != unique.end(); it++){
            result.push_back(*it);
        }

        return result;

        
    }
};