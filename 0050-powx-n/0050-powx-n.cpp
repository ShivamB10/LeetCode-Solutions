class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long pow = n;

        if(n < 0){
            pow = -pow;
        }

        while(pow){
            if(pow%2 == 1){
                ans *=x;
            }
            x *= x;
            pow /=2;
        }

        if(n < 0){
            ans = 1.0/ans;
        }

        return ans;
    }
};