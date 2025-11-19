import sys

input = sys.stdin.readline

def ii(): return int(input().strip())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def si(): return input().strip()

MOD = 10**9 + 7

def reachable_states_fast2(K,max_len):
    allowed=[d for d in range(1,10) if d%K!=0]
    mask_all=(1<<K)-1
    def rot(S,dr):
        if dr==0: return S
        return ((S<<dr) & mask_all) | (S>>(K-dr))
    seen=[set() for _ in range(max_len+1)]
    seen[0].add(0)
    for length in range(max_len):
        for S in list(seen[length]):
            for d in allowed:
                dr=d%K
                newS = rot(S,dr) | (1<<dr)
                if newS & 1:  # residue0 present
                    continue
                seen[length+1].add(newS)
        print("len",length+1,"states",len(seen[length+1]))
    total_states=len(set().union(*seen))
    return total_states,[len(s) for s in seen]

def solve():
    total,levels=reachable_states_fast2(25,24)
    print(total)

if __name__ == "__main__":
    t = 1
    # t = ii()
    for i in range(t):
        print(f"Case #{i+1}")
        solve()


