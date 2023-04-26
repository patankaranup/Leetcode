class Solution {
public:
    int sum = 0;
    int countOfDigits(int num){
        int count = 0;
        sum = 0;
        while(num!=0){
            sum += num%10;
            num /= 10;
            count++;
        }
        return count;
    }
    int addDigits(int num) {
        while(countOfDigits(num)>1){
            num = sum;
        }
        return sum;
    }
};
