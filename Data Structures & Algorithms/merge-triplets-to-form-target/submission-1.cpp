class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x=0;
        int y=0;
        int z=0;
        int n=triplets.size();
        for(int i=0;i<n;i++)
        {
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2])
            continue;
            x=max(x,triplets[i][0]);
            y=max(y,triplets[i][1]);
            z=max(z,triplets[i][2]);
        }
        cout<<x<<" "<<y<<" "<<z;
        if(x==target[0] && y==target[1] && target[2]==z)
        return true;
        else
        return false;
    }
};
