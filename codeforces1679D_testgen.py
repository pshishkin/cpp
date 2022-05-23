# n = 2 * 10**5
n = 200000
print("{} {} {}".format(n, n, 10 ** 17))
print(' '.join(["777777"] * (n)))
for i in range(n):
    print('{} {}'.format(i % (n + 1) + 1, (i + 1) % n + 1))