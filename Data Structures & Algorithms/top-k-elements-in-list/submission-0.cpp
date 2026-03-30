class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
        {
          pq.push({it.second,it.first});
        }
vector<int>ans;
        while(k--)
        {
      auto it=pq.top();
      pq.pop();
        ans.push_back(it.second);
        }
        return ans;
    }
};
