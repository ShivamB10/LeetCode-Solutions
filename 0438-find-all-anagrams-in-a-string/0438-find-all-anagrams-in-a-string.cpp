class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        string substr;
        unordered_map<char,int> window_freq, p_freq;
        vector<int> ans;

        for(int i = 0; i < p.size(); i++){
            p_freq[p[i]]++;
        }

        for(int k = 0; k < p.size(); k++){
            window_freq[s[k]]++;
        }

        if(window_freq == p_freq){
            ans.push_back(0);
        }


        for(int j= p.size(); j < s.size(); j++){
            window_freq[s[j]]++;

            window_freq[s[j-p.size()]]--;

            if(window_freq[s[j-p.size()]] == 0){
                window_freq.erase(s[j-p.size()]);
            }

            if(window_freq == p_freq){
            ans.push_back(j-p.size()+1);
            }
        }

        

        return ans;
    }
};