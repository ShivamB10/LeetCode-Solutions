class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<int> openBrackets;
        stack<int> flexBrackets;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                flexBrackets.push(i);
            } else if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!flexBrackets.empty()) {
                    flexBrackets.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openBrackets.empty() && !flexBrackets.empty() &&
               (openBrackets.top() < flexBrackets.top())) {
            openBrackets.pop();
            flexBrackets.pop();
        }

        if(openBrackets.empty() && !flexBrackets.empty()){
            return flexBrackets.size()%2 == 0;
        }

        return openBrackets.size() == 0;
    }

}
;