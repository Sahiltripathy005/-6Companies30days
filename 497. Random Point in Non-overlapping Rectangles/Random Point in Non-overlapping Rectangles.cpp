class Solution {
    vector<vector<int>> rects;
    vector<int> weights;
    int total_weight;

public:
    Solution(vector<vector<int>>& rects) : rects(rects), total_weight(0) {
        srand(time(0));
        for (const auto& rect : rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            total_weight += area;
            weights.push_back(total_weight);
        }
    }
    
    vector<int> pick() {
        int rand_weight = rand() % total_weight;
        int rect_index = lower_bound(weights.begin(), weights.end(), rand_weight + 1) - weights.begin();
        auto& rect = rects[rect_index];
        
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
