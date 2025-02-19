#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int sign = 1;
        long ans = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (i < s.length() && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (i < s.length() && s[i] == '+')
            i++;
        while (i < s.length())
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX && sign == -1)
                    return INT_MIN;
                if (ans > INT_MAX)
                    return INT_MAX;
            }
            else
                break;
            i++;
        }
        return ans * sign;
    }
};