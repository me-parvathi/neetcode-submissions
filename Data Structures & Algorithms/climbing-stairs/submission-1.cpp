class Solution {
public:
    int climbStairs(int n) {
        // so you need trace all steps to reach and then add each time it is a success
        // before taking a step you can take decision 1 or 2 and based one this the number of remaining stairs keep reducing. 

        //memoising 
        vector<int> memo(n+1, -1);

        function<int(int)> solutions = [&](int steps){
            
            if(steps==0) return 1; 
            else if(steps == 1) return 1;
            else{
                if (memo[steps] != -1) return memo[steps];
                memo[steps] = solutions(steps-1) + solutions(steps-2);
                return memo[steps];
            }
        };

        int result = solutions(n);
        return result;
        
    }
};
