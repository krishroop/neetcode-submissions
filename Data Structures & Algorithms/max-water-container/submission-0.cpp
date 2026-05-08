class Solution {
public:
    int maxArea(vector<int>& height) {
    int n = height.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int area = min(height[i], height[j]) * (j - i);
            ans = max(ans, area);
        }
    }

    return ans;
}
};
