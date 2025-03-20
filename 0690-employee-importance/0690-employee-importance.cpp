/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int,vector<int>>> emap;
        for(auto emp: employees){
            emap[emp->id] = {emp->importance, emp->subordinates};
        }
        int importance = 0;
        dfs(id,importance,emap);

        return importance;
    }

    void dfs(int id, int &importance, unordered_map<int,pair<int,vector<int>>>& emap){
        importance += emap[id].first;

        for(int sub: emap[id].second){
            dfs(sub,importance,emap);
        }

    }
};