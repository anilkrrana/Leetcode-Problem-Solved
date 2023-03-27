/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    let row=grid.length;
    let col=grid[0].length;
    
    for(let i=1; i<col; i++){
        grid[0][i]+=grid[0][i-1];
    }
    for(let i=1; i<row; i++){
        grid[i][0]+=grid[i-1][0];
    }
    for(let i=1; i<row; i++){
        for(let j=1; j<col; j++)
            grid[i][j]+=Math.min(grid[i-1][j],grid[i][j-1])
    }
    return grid[row-1][col-1];
};




// var minPathSum = function(grid) {
//     for(let i = 1; i < grid[0].length; i++) {
//         grid[0][i] += grid[0][i - 1]
//     }
//     for(let i = 1; i < grid.length; i++) {
//         grid[i][0] += grid[i - 1][0]
//     }
    
//     for(let i = 1; i < grid.length; i++) {
//         for(let j = 1; j < grid[0].length; j++){
//             grid[i][j] += Math.min(grid[i - 1][j], grid[i][j - 1]) 
//         }
//     }
    
//     return grid[grid.length - 1][grid[0].length - 1]
// };