
class Solution {
    public:
        const int mod = 1e9 + 7;
    
        long long power(long long x, long long n) {
            long long result = 1;
            x %= mod;  // Ensure x is within mod
            
            while (n > 0) {
                if (n % 2 == 1) result = (result * x) % mod; // Multiply when odd
                x = (x * x) % mod;  // Square x and apply mod
                n /= 2;
            }
            return result;
        }
    
        int countGoodNumbers(long long n) {
            long long odd = (n + 1) / 2;
            long long even = n / 2;
    
            return (power(5, odd) * power(4, even)) % mod;  // Corrected modulo application
        }
    };