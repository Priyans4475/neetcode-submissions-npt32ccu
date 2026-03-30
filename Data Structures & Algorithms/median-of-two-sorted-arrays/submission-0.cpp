class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);

        int left=(n+m+1)/2;
        int low=0;
        int high=n;
        while(low<=high)
        {
            int m1=(low+high)/2;
            int m2=left-m1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            if(m1<n)r1=nums1[m1];
            if(m2<m) r2=nums2[m2];
            if((m1-1)>=0)l1=nums1[m1-1];
            if((m2-1)>=0)l2=nums2[m2-1];

            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2==1)
                return max(l1,l2)/1.0;
                else
                return double(min(r1,r2)+max(l1,l2))/2.0;
            }
            else if(l1>r2)
            {
                high=m1-1;
            }
            else
            low=m1+1;


        }
        return 0;
    }
};
