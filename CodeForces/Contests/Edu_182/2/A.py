import sys

input = sys.stdin.readline

def ii(): return int(input().strip())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def si(): return input().strip()

MOD = 10**9 + 7

def solve():
    n = ii()
    if n%3 == 0: print(0)
    if n%3 == 1: print(2)
    if n%3 == 2: print(1)

if __name__ == "__main__":
    t = 1
    t = ii()
    for _ in range(t):
        solve()


