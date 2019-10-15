var rows = require("fs").readFileSync("/dev/stdin", "utf8").split("\n")

var N = parseInt(rows[0].trim(), 10)
var isEven = function (n) {
  return n % 2 === 0
}
var nOdd = function (n) {
  return isEven(n) ? n / 2 : (n + 1) / 2
}

console.log(nOdd(N) / N)
