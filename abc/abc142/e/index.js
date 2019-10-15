var rows = require("fs").readFileSync("/dev/stdin", "utf8").split("\n")

var N = parseFloat(rows[0].split(" ")[0])
var M = parseFloat(rows[0].split(" ")[1])
var keys = []

for (var i = 0; i < M; i++) {
  var ab = rows[2 * i + 1].split(" ").map(parseFloat)
  var unlockable = {}

  rows[2 * i + 2].split(" ").map(parseFloat).forEach(function(boxId) {
    unlockable[boxId] = true
  })

  var key = {
    yen: ab[0],
    unlockable: unlockable
  }

  keys.push(key)
}

var getUnlockables = function (keyset) {
  return keyset.reduce(function (unlockables, key) {
    return getUnion(unlockables, key.unlockable)
  }, {})
}
var getCostOfKeyset = function (keyset) {
  return keyset.reduce(function (cost, key) {
    return cost + key.yen
  }, 0)
}
var isUnlockableKeyset = function (keyset) { return size(getUnlockables(keyset)) === N }
var unlockableKeysets = function () {
  var keysets = []

  for (var i = 0, len = Math.pow(2, M); i < len; i++) {
    var keyset = []

    for (var keyId = 0; keyId < M; keyId++) {
      var mask = Math.pow(2, keyId)

      if (M & mask === mask) {
        keyset.push(keys[keyId])
      }
    }

    if (isUnlockableKeyset(keyset)) keysets.push(keyset)
  }

  return keysets
}

var main = function () {
  console.log(unlockableKeysets())
}

if (size(getUnlockables(keys)) < N) {
  console.log(-1)
} else {
  main()
}

// ---
function getUnion (S1, S2) {
  var res = {}

  for (var key in S1) {
    res[key] = true
  }
  for (var key in S2) {
    res[key] = true
  }

  return res
}
function size (S) {
  return Object.keys(S).length
}
