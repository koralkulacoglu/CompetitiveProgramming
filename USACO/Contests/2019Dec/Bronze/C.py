from collections import defaultdict as dd
fin = open("lineup_bronze_dec19/7.in", "r")
fout = open("lineup.out", "w")

def isIn(i, order):
    for j in range(len(order)):
        if i in order[j]:
            return j
    return -1

s = set()
rules = dd(list)
c = int(fin.readline())
for i in range(c):
    a, b = fin.readline().strip().split(' must be milked beside ')
    rules[a].append(b)
    s.add(a)
    s.add(b)

order = []
for i in rules.keys():
    idx = isIn(i, order)
    if idx != -1:
        indx = order[idx].index(i)
        if indx == 0:
            order[idx].insert(indx, rules[i][0])
        else:
            order[idx].append(rules[i][0])
 
    else:
        for j in rules[i]:
            idx = isIn(j, order)

            if idx != -1:
                indx = order[idx].index(j)
                if indx == 0:
                    order[idx].insert(indx, i)
                else:
                    order[idx].append(i)
            else:
                order.append([])
                order[-1].append(rules[i][0])
                order[-1].append(i)
                if len(rules[i])==2:
                    order[-1].append(rules[i][1])
                break

for i in range(len(order)):
    if order[i][0] > order[i][-1]:
        order[i].reverse()

order = sorted(order, key=lambda a:a[0])
print(order)

cows = ['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue']
for cow in cows:
    if cow not in s:
        for i in range(len(order)):
            if order[i][0] > cow:
                order.insert(i, [cow])
                s.add(cow)
                break
            if i == len(order)-1:
                order.append([cow])

order = [item for sublist in order for item in sublist]
for i in order:
    fout.write(i+'\n')

