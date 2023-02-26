let n = 50;

function collatz(n) {
    document.write(n + '<br>');
    if (n === 1) {
        document.write('end');
    } else if (n % 2 === 0) {
        collatz(n / 2);
    } else {
        collatz(n * 3 + 1);
    }
}

collatz(n);