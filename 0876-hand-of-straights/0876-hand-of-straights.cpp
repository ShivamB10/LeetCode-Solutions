class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0){
            return false;
        }

        unordered_map<int,int> freq;
        for(int i = 0;  i < hand.size(); i++){
            freq[hand[i]]++;
        }

        sort(hand.begin(), hand.end());

        for(int j = 0; j < hand.size(); j++){
            if(freq[hand[j]] > 0){
                for(int k = hand[j]+1; k < hand[j]+ groupSize; k++){
                    if(freq[k] == 0){
                        return false;
                    }
                    freq[k]--;
                }
            freq[hand[j]]--;
            }
            
        }


        return true;
    }
};