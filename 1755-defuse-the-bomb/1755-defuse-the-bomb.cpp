class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector <int> ans(n , 0);
        int currSum = 0;

        if( k == 0) return ans;
        
        if( k > 0){
            for(int i = 1; i <= k; i++){
                currSum += code[i];
            }

            ans[0] = currSum;

            for (int j = 1; j < n; j++){
                currSum -= code[j];
                currSum += code[(j+k) % n];
                ans[j] = currSum; 
            }
        }

        if(k <0){
            k = abs(k);

            for(int start = (n - k); start < n; start++){
                currSum += code[start % n];
            }

            ans[0] = currSum;

            for(int l = 1; l < n; l++){
                currSum -= code[(n + l - k - 1) % n]; 
                currSum += code[(l - 1) % n];     
                ans[l] = currSum;
            }
        }
        

        return ans;
    }
};