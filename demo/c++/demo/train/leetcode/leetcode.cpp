#include "leetcode.h"


void CLeetcode::test() 
{
    string str1("pwwkew");
    lengthOfLongestSubstring(str1);

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(3);

    vector<int> nums2;
    nums2.push_back(2);
    
}

int CLeetcode::lengthOfLongestSubstring(string s)
{
    map<int, int> last;
    for(int i = 0; i < s.size(); ++i)
    {
        last[s[i]] = -1;
    }
    
    int start = 0;
    int max_len = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        if (last[s[i]] > start) 
        {
            max_len = max_len > i - start ? max_len : i - start;
            start = last[s[i]] + 1;
        }

        last[s[i]] = i;
    }

    return max_len;
}

double CLeetcode::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    if(n1>n2) return findMedianSortedArrays(nums2, nums1);
    const int k = (n1 + n2 + 1)/2;
    int left = 0;
    int right = n1;
    while(left < right){
        const int m1 = left + (right - left)/2;
        const int m2 = k - m1;
        if(nums1[m1]<nums2[m2-1])
            left = m1 + 1;
        else
            right = m1;
    }
    const int m1 = left;
    const int m2 = k - left;
    const int c1 = max(m1 <= 0 ? INT_MIN:nums1[m1-1],
                        m2 <= 0 ? INT_MIN:nums2[m2-1]);
    if((n1 + n2)%2 == 1)
        return c1;
    const int c2 = min(m1 >= n1 ? INT_MAX: nums1[m1],
                    m2 >= n2 ? INT_MAX : nums2[m2]);
    return (c1 + c2) * 0.5;
}