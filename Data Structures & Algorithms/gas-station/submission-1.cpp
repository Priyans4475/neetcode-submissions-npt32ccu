class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tot_gas=accumulate(gas.begin(),gas.end(),0);
        int tot_cost=accumulate(cost.begin(),cost.end(),0);
        if(tot_gas<tot_cost)
        return -1;

          int tot=0;
          int res=0;
        for(int i=0;i<n;i++)
        {
            
            tot+=gas[i]-cost[i];

            if(tot<0)
            {
                tot=0;
                res=i+1;
            }


           

        }

       return res;
    }
};
