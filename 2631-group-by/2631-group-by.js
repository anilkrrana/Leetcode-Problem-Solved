/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const grouped = {};
    this.forEach((item) => {
        let key = fn(item);
        if(!grouped[key]) grouped[key] = [];
        grouped[key].push(item);
    })
    return grouped;
};

/*
Array.prototype.groupBy = function(fn){
    return this.reduce((res, item) => {
        let key = fn(item);
        if(!res[key]) res[key] = [];
        res[key].push(item);
        return res;
    }, {})
};

*/