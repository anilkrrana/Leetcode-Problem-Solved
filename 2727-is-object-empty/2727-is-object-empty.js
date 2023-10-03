/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(object) {
    for (let key in object)
        return false;
    return true;
};