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
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

const step = (direction)=>{
    if(direction == "D"){
        return -1;
    }
    else if(direction == "U"){
        return 1;
    }
}

function countingValleys(steps, path) {
    let alt = 0;
    let prevAlt;
    let numValleys = 0;
    
    let valleyStart = false;
    let valleyEnd = false;
    
    for(let s of path){
        prevAlt = alt;
        alt += step(s);
        
        if(prevAlt == 0 && alt < 0){
            valleyStart = true;
        }
        else if(prevAlt < 0 && alt == 0){
            valleyEnd = true;
        }
        
        if(valleyStart && valleyEnd){
            numValleys += 1;
            valleyStart = false;
            valleyEnd = false;
        }
    }
    
    return numValleys;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const steps = parseInt(readLine().trim(), 10);

    const path = readLine();

    const result = countingValleys(steps, path);

    ws.write(result + '\n');

    ws.end();
}
