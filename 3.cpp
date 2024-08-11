class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s. length();
        if(n==0)
        {
            return n;
        }
        int i, j, len, max=1,space_c=0;
        unordered_map<char,int> mp;
        for(i=0;i<n;i++)
        {
            if(isspace(s[i]))
            {
                space_c++;
            }
        }
        if(space_c==n)
        {
            return 1;
        }
        for(i=0;i<n;i++)
        {
            mp.clear();
            for(j=i;j<n;j++)
            {
                mp[s[j]]++;
                if(mp[s[j]]>1)
                {
                    break;
                }
            }
            len=j-i;
            if(len>max)
            {
                max=len;
            }
        }
        return max;

    }
};
