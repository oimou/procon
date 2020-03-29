const X = 1e5;
const Y = 1e5;
const A = 1e5;
const B = 1e5;
const C = 1;

console.log(`${X} ${Y} ${A} ${B} ${C}`)

for (let i = 0; i < A; i++) {
  process.stdout.write(`${Math.ceil(Math.random() * 1e9)} `);
}
process.stdout.write('\n')
for (let i = 0; i < B; i++) {
  process.stdout.write(`${Math.ceil(Math.random() * 1e9)} `);
}
process.stdout.write('\n')
for (let i = 0; i < C; i++) {
  process.stdout.write(`${Math.ceil(Math.random() * 1e9)} `);
}
process.stdout.write('\n')
