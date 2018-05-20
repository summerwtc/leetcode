#include <iostream>

using namespace std;


class Solution {
public:
	int reverse(int x) {
		int flag = x < 0 ? -1 : 1;

		int64_t num = x;
		if (num < 0) {
			num = -num;
		}

		int64_t answer = 0;
		while (num) {
			int remainder = num % 10;
			answer = answer * 10 + remainder;
			num /= 10;
		}
		if ((answer < INT_MIN) || (answer > INT_MAX)) {
			return 0;
		}
		else {
			return (int)(answer * flag);
		}
	}
};


class Test {
public:
	void testSolution() {
		int x = 123;
		test_resvers(x);
		cout << endl;

		x = -230;
		test_resvers(x);

		//x = -2147483648;
		//test_resvers(x);
	}
private:
	void test_resvers(int x) {
		Solution solution;
		int result = solution.reverse(x);
		cout << "Before reverse : " << x << endl;
		cout << "After reverse : " << result << endl;
	}
};

int main() {
	Test test;
	test.testSolution();
	return 0;
}