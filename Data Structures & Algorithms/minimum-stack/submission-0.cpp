class MinStack {
public:
    MinStack() {
        
    }
      vector<int>ans;
     vector<int>mini;
    void push(int val) {
        ans.push_back(val);
        if(mini.empty() || val<=mini.back())
        {
            mini.push_back(val);
        }
       
    }
  
    void pop() {
      if(mini.back()==ans.back())
      {
        mini.pop_back();
      }
      ans.pop_back();
    }
    
    int top() {

        return ans.back();
        
    }
    
    int getMin() {
        return mini.back();
        

    }
};
