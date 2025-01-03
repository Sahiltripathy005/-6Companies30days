class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                int sum = 0;
                for (int x = max(i - 1, 0); x <= min(i + 1, m - 1); ++x) {
                    for (int y = max(j - 1, 0); y <= min(j + 1, n - 1); ++y) {
                        sum += img[x][y];
                        count++;
                    }
                }
                res[i][j] = sum / count;
            }
        }
        
        return res;
    }
};
