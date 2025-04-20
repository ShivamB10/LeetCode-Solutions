/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr){
        int start = 0; 
        int end = mountainArr.length() -1;

        

        while(start < end){
            int mid = start + (end - start)/2;
            int mid_val = mountainArr.get(mid);
            if(mid_val > mountainArr.get(mid+1)){
                end = mid;
            }

            else{
                start = mid + 1;
            }
        }


        return start;
    }

    int findTarget(int start, int end, int target, MountainArray &mountainArr, int isAscending){
        int left = start;
        int right = end;

        while(left <= right){
            int mid = left + (right-left)/2;
            
            int mid_val = mountainArr.get(mid);

            if(mid_val == target){
                return mid;
            }

            else{
                if(isAscending == 1){
                    if(mid_val > target){
                        right = mid - 1;
                    }
                    else{
                        left = mid + 1;
                    }
                }
                else{
                    if(mid_val > target){
                        left = mid +1;
                    }
                    else{
                        right = mid -1;
                    }
                }
            }
        }

        return -1;

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = findPeak(mountainArr);

        int target_index = findTarget(0, peakIndex, target,  mountainArr, 1);

        if(target_index == -1){
            target_index = findTarget(peakIndex +1 , mountainArr.length()-1, target, mountainArr, 0);
        }

        return target_index;


    }
};