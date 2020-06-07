class BrowserHistory {
    // vector<string> urls(5123, "");  
    string urls[5123];
    int idx = 0; 
    int upper_idx = 0; 
public:
    BrowserHistory(string homepage) {
        urls[idx] = homepage; 
        // upper_idx ++; 
    }
    
    void visit(string url) {
        urls[++idx] = url; 
        upper_idx =idx; 
    }
    
    string back(int steps) {
        idx -= steps; 
        if(idx < 0) idx=0; 
        return urls[idx]; 
    }
    
    string forward(int steps) {
        idx += steps; 
        if(idx > upper_idx) idx = upper_idx; 
        return urls[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */