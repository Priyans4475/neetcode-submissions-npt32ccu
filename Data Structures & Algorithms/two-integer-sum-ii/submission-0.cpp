class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int i=0;
        int j=n.size()-1;
        
        while(i<j)
        {
            if(n[i]+n[j]==target)
            break;
            else if(n[i]+n[j]<target)
            {
                i++;
            }
            else
            j--;

        }
         return {i+1,j+1};

    }
};
