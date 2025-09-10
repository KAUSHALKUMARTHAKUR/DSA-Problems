/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1*/

// Approach - 1

class Solution {
public:
    int reverse(int x) {
        long long num = x;
       string s = to_string(abs(num));
string str = "";

for (int i = s.size() - 1; i >= 0; i--) {
    str += s[i];
}

long long res = stoll(str);

if (x < 0) {
    res = -res;
}

if (res > INT_MAX || res < INT_MIN) return 0;

return (int)res;
    }
};

// Approach - 2

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x != 0) {
            int digit = x % 10;   // take last digit
            x /= 10;              // remove last digit

            // check if res will overflow after multiplying by 10
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) return 0;

            res = res * 10 + digit;  // put digit at the end
        }

        return res;
    }
};
