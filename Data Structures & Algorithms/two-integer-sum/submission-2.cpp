class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        //{0,1,2,0}, target = 0
        //{-1, 2, 3, 1}, target = 0
        //unordered map to store <value, index>
        unordered_map<int,int> m; //{{,0}}

        for(int i = 0; i < nums.size(); i++)
        {
            //check if (target - nums[i]) in map
            if(!m.empty() && m.count(target-nums[i]))
            {
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }

            m[nums[i]] = i;
        }

        return ans;
    }
};
