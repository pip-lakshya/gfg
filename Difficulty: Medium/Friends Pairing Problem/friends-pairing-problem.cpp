class Solution {
public:
    int countFriendsPairings(int n) {

        const int mod = 1000000007;

        if(n<=2)
            return n;

        long long a = 1;
        long long b = 2;

        for(int i=3;i<=n;i++){
            long long c = (b + (long long)(i-1)*a)%mod;
            a = b;
            b = c;
        }

        return b;
    }
};