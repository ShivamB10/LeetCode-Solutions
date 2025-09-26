class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> ans;
        if(nums1.size() >= nums2.size())
        {
            for(int i = 0; i < nums1.size(); i++)
            {
                freq[nums1[i]]++;
            }

            for(int i = 0; i < nums2.size(); i++)
            {
                if(freq[nums2[i]] > 0)
                {
                    freq[nums2[i]]--;
                    ans.push_back(nums2[i]);
                }
            }
        }
        else{
            for(int i = 0; i < nums2.size(); i++)
            {
                freq[nums2[i]]++;
            }

            for(int i = 0; i < nums1.size(); i++)
            {
                if(freq[nums1[i]] > 0)
                {
                    freq[nums1[i]]--;
                    ans.push_back(nums1[i]);
                }
            }
        }


        return ans;

        
    }
};