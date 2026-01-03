class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        for i in words:
            temp = chars
            wk = True
            for j in i:
                if j not in temp:
                    wk = False
                    break
                temp = temp.replace(j, "", 1)

            ans += wk*len(i)

        return ans
