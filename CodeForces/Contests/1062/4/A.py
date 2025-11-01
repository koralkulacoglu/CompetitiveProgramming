import sys

input = sys.stdin.readline

def ii(): return int(input().strip())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def si(): return input().strip()

MOD = 10**9 + 7

def solve():
    a, b, c, d = mi()

    print("YES" if a == b == c == d else "NO")

if __name__ == "__main__":
    t = 1
    t = ii()
    for _ in range(t):
        solve()


