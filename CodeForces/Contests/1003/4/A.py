import sys

input = sys.stdin.readline

def ii(): return int(input().strip())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def si(): return input().strip()

MOD = 10**9 + 7

def solve():
    s = input()
    print(s[:-3] + 'i')

if __name__ == "__main__":
    t = 1
    t = ii()
    for _ in range(t):
        solve()


