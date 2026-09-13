class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> A,B;
        int n = img1.size();
         // 1. img1 ke saare 1 coordinates
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j] == 1)
                    A.push_back({i,j});

                if(img2[i][j] == 1)
                    B.push_back({i,j});
            }
        }
        //mp
        map<pair<int,int>, int> mp;
        int ans=0;
        // 2. Har A ke 1 ko har B ke 1 se compare
        for(auto a:A)
        {
            for(auto b : B)
            {
                int x= b.first - a.first;
                int y= b.second - a.second;
                mp[{x,y}]++;
                ans = max(ans,mp[{x,y}]);
            }
        }
        return ans;
    }
};