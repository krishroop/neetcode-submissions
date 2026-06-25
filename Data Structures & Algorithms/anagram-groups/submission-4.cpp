class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;

        for(const auto &s : strs)
        {
            //1.sort the chars in each string
            string key = s;  //[opst : {pots, tops}]
            sort(key.begin(), key.end());

            //2.push into the vector of its corresponding anagram key
            m[key].push_back(s);
        }

        for(const auto &p : m)
            ans.push_back(move(p.second));

        return ans;
    }
};
