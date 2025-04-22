class Solution {
public:
    int noOfBouquets(int mid, vector<int>& bloomDay, int k){
        int count = 0;
        int noOfBouquet = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
            }
            else{
                count = 0;
            }

            if(count == k){
                noOfBouquet++;
                count = 0;
            }
        }
        return noOfBouquet;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int start = 0;
        int end = 0;
        int minDays = -1;

        for(int i = 0; i < bloomDay.size(); i++){
            end = max(end,bloomDay[i]);
        }

        while(start <= end){
            int mid = start + (end - start)/2;

            int bouquetsCount = noOfBouquets(mid, bloomDay, k);

            if(bouquetsCount < m){
                start = mid + 1;
            }
            else{
                minDays = mid;
                end = mid - 1;
            }

        }

        return minDays;


    }
};