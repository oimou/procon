const cache = {};

let counter = 0;
const gcd = function (a, b, show) {
  // if (show) process.stdout.write(`= (${a}, ${b})\t`);
  if (b == 0) return a
  counter++;
  return gcd(b, a%b, show)
};

let checkpointCounter = 1;
const checkpoints = {}

for (let a = 1; a < 1e9; a++) {
  for (let b = parseInt((a + 1) / 2, 10); b < a; b++) {
    if (a % 2 == 0 &&  b % 2 == 0) continue;

    counter = 0;
    const g = gcd(a, b, false);

    cache[`${a},${b}`] = [g, counter];

    if (counter >= checkpointCounter) {
      console.log(counter, a, b);
      checkpointCounter++;
    }
    if (counter >= 30) {
      process.exit(0);
    }

    // process.stdout.write(`${counter}\t${g}\t`);

    // counter = 0;
    // gcd(a, b, true);

    // process.stdout.write("\n");
  }
  // console.log('---');
}
