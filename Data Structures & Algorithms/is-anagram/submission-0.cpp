#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> m;

        for(char i : s)
            m[i]++;

        for(char i : t)
        {
            if(m[i] > 0)
                m[i]--;
            else
                return false;
        }

        return true;
    }
};
