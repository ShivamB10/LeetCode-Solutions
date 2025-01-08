class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector <string> ans;
        unordered_map <string, int> sequences;
        

        if(s.size() < 10){
            return ans;
        }

        for(int i = 0; i < s.size() - 9; i++){
            sequences[s.substr(i,10)] += 1;
        }

        for(auto it = sequences.begin(); it != sequences.end(); ++it){
            if(it->second >1){
                ans.push_back(it->first);
            }
        }

        return ans;

    }
};