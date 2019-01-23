#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> result;
		for (int i = 0; i < nums.size(); i++)
			result[nums[i]] = i + 1;
		for (int i = 0; i < nums.size(); i++)
		{
			int j = result[target - nums[i]];
			if (j!= 0) {
				vector<int> output;
				output.push_back(i);
				output.push_back(j - 1);
				return output;
			}
		}
	}
};