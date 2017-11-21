/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var len = prices.length; 
    if(len < 1) return 0; 
    var left = new Array(len);
    // console.log(left);
    var minValue = prices[0];
    left[0] = 0;
    for(var i = 1; i < len; i++) {
        minValue = Math.min(minValue, prices[i]);
        left[i] = Math.max(left[i-1], prices[i] - minValue);
        // console.log(left[i]);
    }
    var maxValue = prices[len - 1]; 
    var ret = 0; 
    for(var i = len - 1; i >= 0; i--) {
        maxValue = Math.max(maxValue, prices[i]);
        ret = Math.max(ret, left[i] + maxValue - prices[i]);
    }
    return ret;
};