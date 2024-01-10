from decimal import Decimal, getcontext
tests = int(input())

for gg in range(0, tests):
    n = int(input())
    val = 10**(n-1)
    val = int(val**0.5)

    if n <= 15:
        fdict = {}
        while True:
            curval = val * val
            digit_count = {0: 0, 1: 0, 2: 0, 3: 0,
                           4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0}
            for x in str(curval):
                digit_count[int(x)] += 1
            dict_tuple = tuple(digit_count.items())
            if dict_tuple not in fdict:
                fdict[dict_tuple] = [curval]
            else:
                fdict[dict_tuple].append(curval)

            if len(fdict[dict_tuple]) == n:
                for i in range(0, n):
                    print(fdict[dict_tuple][i])
                break
            val = val + 1

    else:

        ans = []
        getcontext().prec = 50
        val = Decimal(10**(n-1))
        val = int(val.sqrt())+12
        sub = 12
        cnt = n/2-3
        while cnt > 0:
            curval = val * val
            ans.append(curval)
            val = val-sub
            sub = sub*10
            val = val+sub
            cnt = cnt-1

        val = Decimal(10**(n-1))
        val = int(val.sqrt())+21
        sub = 21
        cnt = n/2-3
        while cnt > 0:
            curval = val * val
            ans.append(curval)
            val = val-sub
            sub = sub*10
            val = val+sub
            cnt = cnt-1

        val = Decimal(10**(n-1))
        val = int(val.sqrt())+102
        sub = 102
        res = 2
        while res > 0:
            curval = val * val
            ans.append(curval)
            val = val-sub
            sub = sub*10
            val = val+sub
            res = res-1

        val = Decimal(10**(n-1))
        val = int(val.sqrt())+201
        sub = 201
        res = 2
        while res > 0:
            curval = val * val
            ans.append(curval)
            val = val-sub
            sub = sub*10
            val = val+sub
            res = res-1
        
        
        val = Decimal(10**(n-1))
        val = int(val.sqrt())+1002
        sub = 1002
        res = 1
        while res > 0:
            curval = val * val
            ans.append(curval)
            val = val-sub
            sub = sub*10
            val = val+sub
            res = res-1

        # print(len(ans))
        for i in range(0, len(ans)):
            print(ans[i])
