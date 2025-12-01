import re

f = open('input.txt', 'r').read()

pattern = r"mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\)"

matches = re.findall(pattern, f)

do = True
ans = 0
for i in matches:
    # print(i)
    if i == 'do()':
        do = True
    elif i == "don't()":
        do = False
    elif do:
        s = i[4:-1].split(',')
        ans += int(s[0]) * int(s[1])

print(ans)
