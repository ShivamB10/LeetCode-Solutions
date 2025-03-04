class Solution {
public:
    struct Compare{
        bool operator()(const vector<int>&a, const vector<int>&b){
            return (a[0]*a[0] + a[1]*a[1]) > (b[0]*b[0] + b[1]*b[1]);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for(int i = 0; i < points.size(); i++){
            pq.push(points[i]);
        }

        vector<vector<int>> result;

        for(int j = 0; j < k; j++){
            result.push_back(pq.top());
            pq.pop();
        }


        return result;
    }
};