class MinStack {
    private: 
    vector<pair<int,int> > data;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(!data.empty()){
            int newMin = min(val, this->getMin());
            data.push_back({val, newMin});
        }else{
            data.push_back({val, val});
        }
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back().first;
    }
    
    int getMin() {
        return data.back().second;
    }
};

class MinStack {
    private: 
    vector<pair<int,int> > data;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(!data.empty()){
            int newMin = min(val, this->getMin());
            data.push_back({val, newMin});
        }else{
            data.push_back({val, val});
        }
    }
    
    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back().first;
    }
    
    int getMin() {
        return data.back().second;
    }
};