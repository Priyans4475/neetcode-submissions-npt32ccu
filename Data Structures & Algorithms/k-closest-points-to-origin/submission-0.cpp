class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;

vector<vector<int>> ans;

for (auto it : points)
{
    int x = it[0];
    int y = it[1];

    int dist = x * x + y * y;   // no sqrt needed

    pq.push({dist, {x, y}});
}

while (k--)
{
    auto it = pq.top();
    pq.pop();
    ans.push_back({it.second.first, it.second.second});
}

return ans;
    }
};
