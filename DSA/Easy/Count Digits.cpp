https://www.geeksforgeeks.org/problems/count-digits5716/1
class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int original = n, count = 0;
        while(n > 0){
            int digit = n%10;
            if(digit && !(original % digit))  count++;
            n /= 10;
        }
        return count;
    }
};
