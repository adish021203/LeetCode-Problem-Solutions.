class Solution {
public:
    void mergeArrays(vector<int> nums1,vector<int> nums2, vector<int>& nums3,int a,int b)
    {
        if(a>=nums1.size() && b>=nums2.size())
        {
            return;
        }
        if(a>=nums1.size())
        {
            for(int i=b;i<nums2.size();i++)
            {
                nums3.push_back(nums2[i]);
            }
            return;
        }
        if(b>=nums2.size())
        {
            for(int i=a;i<nums1.size();i++)
            {
                nums3.push_back(nums1[i]);
            }
            return;
        }
        while(a<nums1.size() && nums1[a]<=nums2[b])
        {
            nums3.push_back(nums1[a]);
            a++;
        }
        mergeArrays(nums2,nums1,nums3,b,a);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        double med;
        int n=nums1.size();
        int m=nums2.size();
        vector<int> nums3;
        mergeArrays(nums1,nums2,nums3,0,0);
        int size=nums3.size();
        if(size%2==1)
        {
            int mid=(size-1)/2;
            med=nums3[mid];
        }
        else
        {
            med=0.5 * (nums3[(size/2)-1]+nums3[size/2]);
        }
        return med;        
    }
};
