class Solution {
public:
    int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        // found target
        if (nums[mid] == target)
            return mid;

        // LEFT HALF SORTED
        if (nums[l] <= nums[mid]) {

            // target lies inside left half
            if (nums[l] <= target && target < nums[mid]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        // RIGHT HALF SORTED
        else {

            // target lies inside right half
            if (nums[mid] < target && target <= nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }

    return -1;
}
};
