class KthLargest {
public:
   priority_queue<int>pq;
   int x=0;
    KthLargest(int k, vector<int>& nums) {
        for(auto i:nums)
        {
            pq.push(i);
        }
        x=k;
    }
    
    int add(int val) {
        pq.push(val);
        vector<int>temp;
        int a=0;
        int siz=x;
        while(siz--)
        {
            a=pq.top();
            pq.pop();
            temp.push_back(a);

        }
        for(auto i:temp)
        {
            pq.push(i);
        }

        return a;


    }
};
