/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var len = prices.length;
    if(len < 1) return 0;
    var minValue = prices[0];
    var ret = 0; 
    for(var index in prices){
        minValue = Math.min(minValue, prices[index]);
        ret = Math.max(ret, prices[index] - minValue);
    }
    return ret;
};