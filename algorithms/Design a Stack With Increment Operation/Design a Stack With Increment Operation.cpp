class CustomStack {
    int max_size; 
    int stack[1123]; 
    int idx; 
public:
    CustomStack(int maxSize) {
        max_size = maxSize; 
        idx=0; 
    }
    
    void push(int x) {
        if(idx >= max_size) return ; 
        stack[idx++] = x; 
    }
    
    int pop() {
        if(idx <= 0) return -1; 
        return stack[--idx]; 
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < idx; i++) {
            stack[i] += val; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */