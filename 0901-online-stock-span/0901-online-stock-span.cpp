class StockSpanner {
    vector<int> prices;
    vector<int> spans;
public:
    StockSpanner() {}
    int next(int price) {
        int span = 1;
        int p = prices.size()-1;
        while(p >= 0 && prices[p] <= price){
            span += spans[p];
            p -= spans[p];
        }
        prices.push_back(price);
        spans.push_back(span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */