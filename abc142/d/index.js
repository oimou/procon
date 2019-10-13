var rows = require("fs").readFileSync("/dev/stdin", "utf8").split("\n")

var A = parseFloat(rows[0].split(" ")[0])
var B = parseFloat(rows[0].split(" ")[1])

var isPrime = function (n) {
  if (n === 1) return false
  if (n === 2) return true
  if (n === 3) return true

  var sqrtn = Math.sqrt(n)

  for (var i = 2; i < sqrtn + 1; i++) {
    if (n % i === 0) return false
  }

  return true
}
var getPrimeFactors = function (n) {
  var sqrtn = Math.sqrt(n)
  var res = {}

  for (var i = 1; i < sqrtn + 1; i++) {
    if (n % i !== 0) continue

    var I = parseInt(n / i, 10)

    if (isPrime(i)) res[i] = true
    if (isPrime(I)) res[I] = true
  }

  return res
}
var getIntersection = function (S1, S2) {
  var res = {}
  var Base = Object.keys(S1) < Object.keys(S2) ? S1 : S2

  for (var key in Base) {
    if (S1[key] && S2[key]) res[key] = true
  }

  return res
}
var size = function (S) {
  return Object.keys(S).length
}
var commonPrimeFactors = getIntersection(getPrimeFactors(A), getPrimeFactors(B))

console.log(size(commonPrimeFactors) + 1)
