/**
Website: https://leetcode.com/problems/climbing-stairs/

    70. Climbing Stairs


    You are climbing a stair case. It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
*/


/**
method 1: 
    Time Complexity:   O(n)
    space complexity:  O(n)
*/
class Solution {
public:
    int climbStairs(int n) {
        //f(n) = f(n - 1) + f(n - 2)
        std::vector<int> vec(n);
        if (n < 2) {
            return n;
        }
        vec[0] = 1;
        vec[1] = 2;
    
        for (int i = 2; i < n; ++i) {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[n - 1];
    }
};



/**
method 2:
    Time Complexity:   O(n)
    space complexity:  O(n)
*/

class Solution {
public:
    int climbStairs(int n) {
        //f(n) = f(n - 2) + f(n - 1)
        if (n < 2) {
            return n;
        }
        int f0 = 1;
        int f1 = 1;
        int temp = 0;
    
        for (int i = 2; i <= n; ++i) {
            temp = f0+ f1;
            f0 = f1;
            f1 = temp;
        }
    
        return f1;
    }
};
