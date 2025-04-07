class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int starting_point = 0;
        int curr_gas = 0;
        int total_gas = 0;
        int total_cost = 0;

        for(int i = 0; i< gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];

            curr_gas += gas[i] - cost[i];

            if(curr_gas < 0){
                starting_point = i+1;
                curr_gas = 0;
            }

        }

        if(total_cost > total_gas){
            return -1;
        }

        return starting_point;
    }
};