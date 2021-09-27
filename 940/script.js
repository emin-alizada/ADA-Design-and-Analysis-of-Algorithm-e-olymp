const fs = require('fs')

fs.readFile('input.txt', 'utf8', (err, data) => {
    if (err) {
        console.error(err)
        return
    }

    const lines = data.split("\n");

    const n = lines[0];
    const numbers = lines[1].split(" ");

    const obj = {};

    numbers.forEach(num => {
        obj[num] ? obj[num]++ : obj[num] = 1;
    })

    let res = -1;
    Object.keys(obj).forEach(num => {
        if (obj[num] > n/2) {
            res = num;
        }
    })

    console.log(res);
})