const N = 100
const M = 100

console.log(`${N} ${M}`)

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    process.stdout.write(Math.random() < 0.3 ? 'W' : '.')
  }
  process.stdout.write('\n')
}
