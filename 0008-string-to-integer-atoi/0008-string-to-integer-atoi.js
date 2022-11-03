/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let i = 0;
    let res = 0;
    let isNegative = false;
    
    // 1. Skip spaces
    while (str[i] === ' ') {
        i += 1;
    }
    
    // 2. Optional +/-
    const maybeSign = str[i];
    if (maybeSign === '+' || maybeSign === '-') {
        isNegative = maybeSign === '-';
        i += 1;
    }

    // 3. Process numbers and stop once an invalid character is found
    for (; i < str.length; i += 1) {
        const code = str.charCodeAt(i) - 48; // '0' is 48
        if (code < 0 || code > 9) {
            break;
        }
        res *= 10;
        res += code;
    }
    
    if (isNegative) {
        res = -res;
    }
    
    return Math.max(-(2**31), Math.min(2**31 - 1, res));
};