s = input()
x = s.count('f')
if x == 1:
    print('-1')
elif x == 0:
    print('-2')
else:
    i = s.find('f')
    s = s[i + 1:]
    print(s.find('f'))