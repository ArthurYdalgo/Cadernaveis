import math
entrada = input()

list = entrada.split()
v = int(list[0])
n = int(list[1])

pct = v*n/10
nums = []
for i in range(1,10):
    nums.append(math.ceil(pct*i))

print(' '.join(map(str,nums)))


