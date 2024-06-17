class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c), squareSum = 0;

        while(a <= b) {
            squareSum = a * a + b * b;

            if(squareSum < c) a++;
            else if(squareSum > c) b--;
            else if(squareSum == c) return true;
        }

        return false;
    }
};