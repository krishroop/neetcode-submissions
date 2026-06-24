class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;

        for(auto i : s)
            m[i]++;

        for(auto i : t)
        {
            if(m.count(i))
            {
                m[i]--;
                if(m[i] == 0)
                    m.erase(i);
            }
            else
                return false;
        }

        if(m.empty())
            return true;
        else
            return false;
    }
};
