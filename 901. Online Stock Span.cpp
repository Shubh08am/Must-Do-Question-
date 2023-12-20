class StockSpanner {
public:
    stack<pair<int,int>>PrevGreater;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!PrevGreater.empty() && PrevGreater.top().first<=price) {
            span+=PrevGreater.top().second;
            PrevGreater.pop();
        }
        PrevGreater.push({price,span});
    return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
