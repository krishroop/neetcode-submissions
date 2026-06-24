class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

      unordered_set<int> seen;

      for(auto i : nums)
      {
          if(!seen.count(i))
            seen.insert(i);
          else
          {
              if(seen.count(i) == 1)
                return true;
          }
      } 

      return false; 
    }
};