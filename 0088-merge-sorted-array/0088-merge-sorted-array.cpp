class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
            return;
        }
        if(n == 0){
            return;
        }
        
        int i = i = m - 1;; int j = j = n - 1;;
        int pos = m+n-1;

        while(j >=0){
            if(i >=0 && nums1[i] > nums2[j]){
                nums1[pos] = nums1[i];
                i--;
                pos--;
            }
            else{
                nums1[pos] = nums2[j];
                j--;
                pos--;
            }
        }

    }
};