var rows = require("fs").readFileSync("/dev/stdin", "utf8").split("\n")

var N = rows[0].split(" ")[0]
var K = parseFloat(rows[0].split(" ")[1])
var h = rows[1].split(" ").map(parseFloat)

console.log(h.filter(function (x) { return x >= K }).length)
