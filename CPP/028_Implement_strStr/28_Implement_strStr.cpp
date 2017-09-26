/*
Link : https://leetcode.com/problems/implement-strstr/description/

28. Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        if (haystack_size < needle_size) {
            return -1;
        }

		int start = 0;
        for (int index = 0; index <= haystack_size - needle_size; ++index) {
            for (start = 0; start < needle_size; ++start) {
                if (haystack[start + index] != needle[start]) {
					break;
                }
            }
            //Returns the index to the first occurrence of needle in haystack
			if (start == needle_size) {
			    return index;
			}
        }
        
        // needle is not part of haystack.
        return -1;
    }
};
