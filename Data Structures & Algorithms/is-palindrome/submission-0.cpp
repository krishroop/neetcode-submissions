class Solution {
public:
    bool isPalindrome(string s) {

        //2 pointer approach
        int first = 0 ,last = s.length() - 1;

        while(first < last)
        {
            //move to next alphanumeric 
            while(first < last && !isalnum(s[first])) first++;
            while(first < last && !isalnum(s[last])) last--;

            if(toupper(s[first]) != toupper(s[last]))
                return false;

            first++; last--;
        }

        return true; 
    }
};
