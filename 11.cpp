class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int f=0,l=height.size()-1,area,maxval=INT_MIN;
        while(f<l)
        {
            area=min(height[f],height[l])*abs(f-l);
            maxval=max(maxval,area);
            if(height[f]<height[l])
            {
                f++;
            }
            else
            {
                l--;
            }
        }
        return maxval;
    }
};
