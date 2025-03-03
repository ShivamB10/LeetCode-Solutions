class Solution {
public:
    void parenthesisCombo(int open, int closed, vector<string>& result, string& path, int n){
        if(open == closed && open == n){
            result.push_back(path);
            return;
        }

        if(open < n){
            path +="(";
            parenthesisCombo(open+1, closed, result, path, n);
            path.pop_back();
        }

        if(closed < open){
            path +=")";
            parenthesisCombo(open, closed+1, result, path, n);
            path.pop_back();
        }

    
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int closed = 0;
        vector<string> result;
        string path;

        parenthesisCombo(open,closed, result, path, n);

        return result;
    }
};