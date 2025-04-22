class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int start = 0;
        unordered_map<char,int> freq;
        int maxFreq = 0;
        int maxLength = 0;

        for(int end = 0; end < answerKey.size(); end++){
            freq[answerKey[end]]++;

            maxFreq = max(maxFreq, freq[answerKey[end]]);

            while(end - start + 1 - maxFreq > k){
                freq[answerKey[start]]--;
                start++;
            }

            maxLength = max(maxLength, end - start+1);
        }

        return maxLength;
    }





};