var subarraysDivByK = function(M, N) {

    let freq = new Array(N).fill(0); // "moduloK : Times I've seen it so far"


    freq[0]=1 //  Explained below

    // This is the accumulative sum of the elements of A
    let sum = 0;

    // The count of wanted subarrays, whose Sum%K= zero
    let count=0;

    for(let i = 0; i < M.length; i++){

        sum=sum+M[i]


        var remainder= sum%N

        //ALWAYS CHOOSE THE POSITIVE REMAINDER
        if(remainder<0)remainder+=N // Explained below


        count+=freq[remainder]

        freq[remainder]++
    }
    return count
    

};