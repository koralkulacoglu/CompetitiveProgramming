class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        a1 = float(event1[0].replace(':', '.'))
        a2 = float(event1[1].replace(':', '.'))
        b1 = float(event2[0].replace(':', '.'))
        b2 = float(event2[1].replace(':', '.'))
        
        if a1 <= b1 <= a2: return True
        if a1 <= b2 <= a2: return True
        if b1 <= a1 <= b2: return True
        if b1 <= a2 <= b2: return True
        return False
