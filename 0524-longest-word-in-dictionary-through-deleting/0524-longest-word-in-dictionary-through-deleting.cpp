class Solution {
public:
    bool canFormWord(string s, string word){
        int word_i = 0;
        int s_i = 0;

        while(s_i < s.size() && word_i < word.size()){
            if(word[word_i] == s[s_i]){
                word_i++;
            }
            s_i++;
        }

        return word_i == word.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;

        for(int i = 0; i < dictionary.size(); i++){
            if(canFormWord(s,dictionary[i])){
                if(ans.size() < dictionary[i].size() || ans.size() == dictionary[i].size() && ans > dictionary[i]){
                    ans = dictionary[i];
                }
            }
        }


        return ans;
    }
};