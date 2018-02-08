/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    var ret = ""; 
    var len1 = num1.length; 
    var len2 = num2.length;
    var i = len1-1, j = len2-1; 
    var last = 0; 
    while(i >= 0 && j >= 0) {
        var val = last + (num1[i] - '0') + (num2[j] - '0'); 
        ret += val%10; 
        last = parseInt(val / 10); 
        i--; j--;
    }
    while(i >= 0) {
        var val = last + (num1[i] - '0'); 
        ret += val%10; 
        last = parseInt(val / 10); 
        i--; 
    }
    while(j >= 0) {
        var val = last + (num2[j] - '0'); 
        ret += val%10; 
        last = parseInt(val / 10); 
        j--; 
    }
    if(last != 0) ret += last;
    return ret.split("").reverse().join("");
};