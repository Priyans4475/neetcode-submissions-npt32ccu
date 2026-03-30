class MedianFinder {
public:
    MedianFinder() {
        
    }
    vector<int>ans;
    void addNum(int num) {
        ans.push_back(num);

    }
    
    double findMedian() {
        int n=ans.size();
        float val=0.0;
        sort(ans.begin(),ans.end());
        if(n%2==0)
        {
             val=ans[n/2]+ans[(n/2)-1];
             val=val/2;
        }
        else
        val=ans[n/2];

        return val;
    }
};
