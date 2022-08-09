'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

function pageCount(n, p) {
    let numTurnsStart = 0;
    let numTurnsEnd = 0;
    
    // turning from 1
    if(p == 1){
        return numTurnsStart;
    }
    else{
        let currentPage = 1;
        while(true){
            currentPage += 2;
            numTurnsStart += 1;
            if(p <= currentPage){
                break;
            }
        }
    }
    
    // turning from n
    if(p == n || (n % 2 != 0 && p == n - 1)){
        return numTurnsEnd;
    }
    else{
        let currentPage = (n % 2 == 0) ? n : n - 1;
        while(true){
            currentPage -= 2;
            numTurnsEnd += 1;
            if(p >= currentPage){
                break;
            }
        }
    }

    return (numTurnsStart < numTurnsEnd) ? numTurnsStart : numTurnsEnd;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine().trim(), 10);

    const p = parseInt(readLine().trim(), 10);

    const result = pageCount(n, p);

    ws.write(result + '\n');

    ws.end();
}
