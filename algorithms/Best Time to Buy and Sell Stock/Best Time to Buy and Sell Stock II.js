/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var ret = 0; 
    var len = prices.length;
    if(len < 1) return 0; 
    for(var i = 1; i < len; i++) {
        if(prices[i] > prices[i-1]) ret += prices[i] - prices[i-1];
    }
    return ret;
};