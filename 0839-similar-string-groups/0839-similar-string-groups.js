/**
 * @param {string[]} strs
 * @return {number}
 */
var numSimilarGroups = function(strs) {
    const graph = new Map();
    
    // add nodes to the graph
    for (const str of strs) {
        graph.set(str, []);
    }
    
    // add edges to the graph
    for (let i = 0; i < strs.length; i++) {
        for (let j = i + 1; j < strs.length; j++) {
            if (isSimilar(strs[i], strs[j])) {
                graph.get(strs[i]).push(strs[j]);
                graph.get(strs[j]).push(strs[i]);
            }
        }
    }
    
    // count the number of connected components in the graph using DFS
    let numGroups = 0;
    const visited = new Set();
    for (const [node, edges] of graph) {
        if (!visited.has(node)) {
            dfs(node, visited, edges, graph);
            numGroups++;
        }
    }
    
    return numGroups;
};

// check if two strings are similar
function isSimilar(str1, str2) {
    if (str1 === str2) {
        return true;
    }
    if (str1.length !== str2.length) {
        return false;
    }
    let numSwaps = 0;
    for (let i = 0; i < str1.length; i++) {
        if (str1[i] !== str2[i]) {
            numSwaps++;
        }
        if (numSwaps > 2) {
            return false;
        }
    }
    return numSwaps === 2;
}

// perform DFS on the graph to visit all connected nodes
function dfs(node, visited, edges, graph) {
    visited.add(node);
    for (const neighbor of edges) {
        if (!visited.has(neighbor)) {
            dfs(neighbor, visited, graph.get(neighbor), graph);
        }
    }
}