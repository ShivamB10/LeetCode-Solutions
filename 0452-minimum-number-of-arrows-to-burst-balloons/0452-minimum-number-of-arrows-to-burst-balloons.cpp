class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 1;
        int end = points[0][1];

        for(int i = 0; i < points.size(); i++){
            if(points[i][0] > end){
                count++;
                end = points[i][1];
            }
            else{
                end = min(points[i][1], end);
            }
        }

        return count;
    }
};