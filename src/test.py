def quick_merge(n):
    res = []
    for i in range(n):
        res += [int(x) for x in input().split()]
	
    res.sort()
    return res

n = int(input())
print(quick_merge(n))
