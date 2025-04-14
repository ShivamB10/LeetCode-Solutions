class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        vector<int>result;


        for(int i = 0; i<s.size();i++){
            last[s[i]] = i;
        }

        int end = 0;
        int start = 0;

        for(int j = 0; j < s.size(); j++){
            end = max(end, last[s[j]]);

            if(j == end){
                result.push_back(end - start + 1);
                start = j+1;
            }
        }

        return result;
    }
};