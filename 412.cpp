/*
412. Candy

There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
Have you met this question in a real interview?
Example
Given ratings = [1, 2], return 3.
Given ratings = [1, 1, 1], return 3.
Given ratings = [1, 2, 2], return 4. ([1,2,1]).
*/

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        int  cap = ratings.size();
        int* candy = new int[cap];
        fill(candy , candy + cap , 0);
         
        int k = 1;
        for(int i = 1 ; i < cap ; i++){
            if(ratings[i] > ratings[i - 1]){
                candy[i] = max(k++ , candy[i]);
            }else{
                k = 1;
            }
        }
        k = 1;
        for(int i = cap -2 ; i >= 0 ; i --){
            if(ratings[i] > ratings[i + 1]){
                candy[i] = max(k++ , candy[i]);
            }else{
                k = 1;
            }
        }
        int ans = cap;
        for(int i = 0 ; i < cap ; i++) ans += candy[i];
         
        return ans;
    }
};
