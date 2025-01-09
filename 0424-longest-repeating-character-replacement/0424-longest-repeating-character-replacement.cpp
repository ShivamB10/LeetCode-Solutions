class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char, int> alphabets;
        int start = 0;
        int maxLength = 0;
        int maxFrequency = 0;
        

        for(int end = 0; end < s.size(); end++){
            alphabets[s[end]]++;
            maxFrequency = std::max(alphabets[s[end]], maxFrequency);

            if(end - start + 1 - maxFrequency > k){
                alphabets[s[start]]--;
                start++;
            }
            else{
                maxLength = std::max(maxLength, end - start + 1);
            }

        }

        return maxLength;
    }
};