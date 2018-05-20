/**
Website: https://leetcode.com/problems/two-sum/

1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//Method 1
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int size = nums.size();
		std::vector<int> result;

		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				if ((nums[i] + nums[j]) == target) {
					if (nums[i] < nums[j]) {
						result.push_back(i);
						result.push_back(j);
						return result;
					}
					else {
						result.push_back(i);
						result.push_back(j);
						return result;
					}
				}
			}
		}
		return result;
	}
};


//Method 2 
//using hashmap the save the value and index
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int>map;
		std::vector<int> answer;
		int size = nums.size();

		//using hashmap to keep numbers[index] and index
		for (int i = 0; i < size; ++i) {
			map[nums[i]] = i;
		}

		std::unordered_map<int, int>::const_iterator it;
		for (int index = 0; index < size; ++index) {
			//find the answer
			it = map.find(target - nums[index]);
			if (it != map.end()) {
				//it->second saves the index 
				if (index == it->second) {
					//same index
					continue;
				}

				if (index < it->second) {
					answer.push_back(index);
					answer.push_back(it->second);
				}
				else {
					answer.push_back(it->second);
					answer.push_back(index);
				}
				return answer;
			}
		}
		return answer;
	}
};

class Test {
public:
	void testSolution() {
		vector<int>nums1 = { 2, 7, 11, 15 };
		int target = 9;
		test_twoSum(nums1, 9);

		vector<int>nums2 = { 1, 3, 5, 7 };
		target = 8;
		test_twoSum(nums2, target);
	}
private:
	void test_twoSum(vector<int>& nums, int target) {
		Solution solution;
		vector<int> result = solution.twoSum(nums, target);
		cout << "Input nums : ";
		showVector(nums);
		cout << "Input target : " << target << endl;
		cout << "Output : " ;
		showVector(result);
		cout << endl;
	}

	void showVector(vector<int> & nums) {
		for (int num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
};

int main() {
	Test  test;
	test.testSolution();
	return 0;
}
