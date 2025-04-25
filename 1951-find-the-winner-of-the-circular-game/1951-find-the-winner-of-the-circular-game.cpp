class Solution {
public:
    void findWinner(vector<int> & arr, int startIndex, int k){
        if(arr.size() == 1){
            return;
        }

        int removalIndex = (startIndex + k-1)% arr.size();


        arr.erase(arr.begin()+removalIndex);

        findWinner(arr, removalIndex, k);

        return;




    }
    int findTheWinner(int n, int k) {
        vector<int> arr;

        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }

        findWinner(arr,0,k);

        return arr[0];

        
    }
};