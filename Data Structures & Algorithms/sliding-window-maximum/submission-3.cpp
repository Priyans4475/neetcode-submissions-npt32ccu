class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
       for(int i=0;i<k;i++)
       {
        pq.push({nums[i],i});
       }
       auto it = pq.top();
       ans.push_back(it.first);

        
        for(int i=k;i<n;i++)
        {
            priority_queue<pair<int,int>> temp;
      while(!pq.empty()){
        auto it = pq.top();
    if(it.second != i-k) 
    temp.push(pq.top());
    pq.pop();
}
pq = temp;
pq.push({nums[i],i});

         auto it = pq.top();
       ans.push_back(it.first);
        
             
        }
        return ans;

    }
};
