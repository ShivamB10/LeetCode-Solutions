class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int w1 = 0;
        int w2 = 0;

        for(int i = 0; i < word1.size()+ word2.size(); i++){
            if(i%2==0 && w1 < word1.size()){
                ans.push_back(word1[w1]);
                w1++;
            }
            else if(i%2==0 && w1 == word1.size()){
                ans.push_back(word2[w2]);
                w2++;
            }
            else if(i%2==1 && w2 < word2.size()){
                ans.push_back(word2[w2]);
                w2++;
            }
            else if(i%2 == 1 && w2 == word2.size()){
                ans.push_back(word1[w1]);
                w1++;
            }
        }


        return ans;
    }
};