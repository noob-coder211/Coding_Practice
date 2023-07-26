class Solution {
public:
    double pow(double y, long long int n)
    {
        cout<<n<<endl;
        if(n == 1)
            return y;
        double val = pow(y, n/2);
        if(n%2 == 0)
            return val * val;
        else
            return y * val * val;
    }

    double myPow(double x, int n) {

        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        if(n<0)
        {
            double y = 1/x;
            long long z = -1 * (long long)n;
            return pow(y, (long long)z);
        }
        return pow(x, (long long)n);
    }
};