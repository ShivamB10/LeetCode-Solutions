class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int currentSatisfied = 0;
        int maxSatisfied = 0;
        int extraSatisfied = 0;
        int start =0;

        for(int i = 0; i < customers.size(); i++){
            if(grumpy[i] == 0){
                currentSatisfied += customers[i];
            }
            else if( i < minutes){
                extraSatisfied += customers[i];
            }
        }

        maxSatisfied = currentSatisfied + extraSatisfied;

        for(int end = minutes; end < customers.size(); end++){
            if(grumpy[start] == 1){
                extraSatisfied -= customers[start];
            }

            if(grumpy[end] == 1){
                extraSatisfied += customers[end];
            }

            maxSatisfied = std::max(maxSatisfied, currentSatisfied + extraSatisfied );

            start++;

            
        }

        return maxSatisfied;

    }
};