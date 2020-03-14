const N = 2 * 1e5;
const K = 1e9;

console.log(`${N} ${K}`);

for (let i = 0; i < N; i++) {
  process.stdout.write(`${Math.floor(Math.random() * 1e9)} `);
}
process.stdout.write('\n');
