class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k >0){
            return false;
        }

        unordered_map<int,int> freq;
        for(int i = 0; i < nums.size();i++){
            freq[nums[i]]++;
        }

        sort(nums.begin(),nums.end());

        for(int j = 0; j < nums.size(); j++){
            if(freq[nums[j]] > 0){
                for(int l = nums[j]+1; l < nums[j]+k; l++){
                    if(freq[l] == 0){
                        return false;
                    }
                    freq[l]--;
                }
            }
            freq[nums[j]]--;
        }


        return true;

    }
};