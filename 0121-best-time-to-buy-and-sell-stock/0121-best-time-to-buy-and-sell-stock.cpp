class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buying_price = prices[0];
        int maxProfit = 0;
        for ( int i=0; i<prices.size();i++){
            if( prices[i] < buying_price){
                buying_price = prices[i];
            }
            if ( prices[i] - buying_price > maxProfit){
                maxProfit = prices[i] - buying_price;
            }
        }
        return maxProfit;
    }
};