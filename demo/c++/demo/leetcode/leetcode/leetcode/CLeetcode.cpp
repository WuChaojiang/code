#include "CLeetcode.h"

void CLeetcode::test()
{
	string str1 = "abcabcbb";
	int len = lengthOfLongestSubstring(str1);
	printf("The length Of Longest Substring of %s is %d", str1.c_str(), len);

	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(3);

	vector<int> nums2;
	nums2.push_back(2);
	double median = findMedianSortedArrays(nums1, nums2);

}

int CLeetcode::lengthOfLongestSubstring(string s)
{
	map<int, int> last;
	for (int i = 0; i < s.size(); ++i)
	{
		last[s[i]] = -1;
	}

	int start = 0;
	int max_len = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (last[s[i]] >= start)
		{
			max_len = max_len > i - start ? max_len : i - start;
			start = last[s[i]] + 1;
		}

		last[s[i]] = i;
	}

	max_len = max_len > s.size() - start ? max_len : s.size() - start;

	return max_len;
}

/*
 示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

*/

double CLeetcode::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	if (nums2.size() < nums1.size())
	{
		return findMedianSortedArrays(nums2, nums1);
	}
	int n = nums1.size(), m = nums2.size();
	int left = 0, right = n;
	double max_left = -1, min_right = -1;
	while (true)
	{
		int i = (right + left) / 2;
		int j = (m + n + 1) / 2 - i;
		if (i < n && nums1[i] < nums2[j - 1]) //i is small
		{
			left = i + 1;
		}
		else if (i > 0 && nums1[i - 1] > nums2[j])// i is big
		{
			right = i - 1;
		}
		else
		{
			if (i == 0)max_left = nums2[j - 1];
			else if (j == 0)max_left = nums1[i - 1];
			else max_left = max(nums1[i - 1], nums2[j - 1]);
			if ((n + m) % 2)return max_left;
			if (i == n)min_right = nums2[j];
			else if (j == m)min_right = nums1[i];
			else min_right = min(nums1[i], nums2[j]);
			return (min_right + max_left) / 2;
		}
	}
	return -1;
}
