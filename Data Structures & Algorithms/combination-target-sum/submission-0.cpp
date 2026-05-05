class Solution {
public:
    void backtrack(int idx, int target, vector<int>& nums,
               vector<int>& curr, vector<vector<int>>& res) {
    
    if (target == 0) {
        res.push_back(curr);
        return;
    }

    if (target < 0) return;

    for (int i = idx; i < nums.size(); i++) {
        curr.push_back(nums[i]);
        backtrack(i, target - nums[i], nums, curr, res); // reuse same i
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> curr;

    backtrack(0, target, nums, curr, res);
    return res;
}
};
