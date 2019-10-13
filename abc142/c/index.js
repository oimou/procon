var rows = require("fs").readFileSync("/dev/stdin", "utf8").split("\n")

var N = rows[0].trim()
var A = rows[1].split(" ").map(parseFloat)
var A_ = A.map(function (x, i) { return { x: x, i: i + 1 } })

A_.sort(function asc(a, b) {
    return a.x - b.x
  })

console.log(A_.map(function (p) { return p.i }).join(" "))
