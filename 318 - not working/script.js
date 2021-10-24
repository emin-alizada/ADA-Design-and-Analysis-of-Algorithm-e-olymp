const c = [];

function binomCoef(n, k) {
    if (n === k || k === 0) {
        return 1;
    }

    const left = c[n - 1]?.[k - 1] ? c[n - 1]?.[k - 1] : binomCoef(n - 1, k - 1);
    const right = c[n - 1]?.[k] ? c[n - 1]?.[k] : binomCoef(n - 1, k);
    if (!c[n-1]) {
        c[n-1] = [];
    }
    c[n-1][k-1] = left;
    c[n-1][k] = right;

    return left + right;
}

const fs = require('fs')

fs.readFile('input.txt', 'utf8', (err, data) => {
    if (err) {
        console.error(err)
        return
    }

    const lines = data.split("\n");

    const testNumbers = lines[0];
    const answers = []

    for (let i = 1; i <= testNumbers; i++) {
        const [n,k] = lines[i].split(" ");

        answers.push(binomCoef(parseInt(n), parseInt(k)))
    }

    console.log(answers.join("\n"));
})