class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //thinking should be - today is best selling price , what is minimum value i have seen before 
        int min_price = INT_MAX;
        int profit = 0;
        for(auto price : prices){
            min_price = min(min_price , price);                     //optimal approach
            profit = max(profit , price - min_price);
        }
        return profit;
    }
};