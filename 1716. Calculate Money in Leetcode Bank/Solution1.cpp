class Solution1 {
public:
    int totalMoney(int n) {
        int no_of_complete_weeks = n/7;
        int firstWeekSum = 28;
        int lastWeekSum = firstWeekSum + (no_of_complete_weeks-1)*7;
        int totalSum = no_of_complete_weeks*(firstWeekSum+lastWeekSum)/2;
        no_of_complete_weeks++;
        for(int i=1; i<=(n%7); i++){
            totalSum += no_of_complete_weeks;
            no_of_complete_weeks++;
        }
        return totalSum;
    }
};