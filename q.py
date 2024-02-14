from decimal import Decimal, getcontext
tests = int(input())

for gg in range(0, tests):
    n = int(input())
    x = int(input())
    nums = []
    for j in range(1, 10):
        val = ""
        val = ''.join(str(j) for _ in range(n+1))
        nums.append(val)

    val = ""
    val = ''.join(str(9) for _ in range(n))
    nums.append(val)

    fans = -1
    for y in nums:
        if (fans != -1):
            break
        if (int(y) > x):
            curval = str(int(y)-x)
            if (len(curval) == n):
                fans = curval

    print(fans)
