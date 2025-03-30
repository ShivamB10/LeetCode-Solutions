class BrowserHistory {
private:
    stack<string> forwardHistory;
    stack<string> backward;
    string current;

public:
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        backward.push(current);
        current = url;

        while(!forwardHistory.empty()){
            forwardHistory.pop();
        }
    }
    
    string back(int steps) {
        while(steps>0 && !backward.empty()){
            forwardHistory.push(current);
            current = backward.top();
            backward.pop();
            steps--;
        }

        return current;
        
    }
    
    string forward(int steps) {
        while(steps>0 && !forwardHistory.empty()){
            backward.push(current);
            current = forwardHistory.top();
            forwardHistory.pop();
            steps--;
        }

        return current;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */