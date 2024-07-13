class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        bool flag = false;
        while(n){
            if(n&1){
                if(flag) return false;
                flag = true;
            }
            n>>=1;
        }
        return true;
    }
};
