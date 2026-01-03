class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        vals = sentence.split(' ')
        for i in range(len(vals)):
            if vals[i][0] == '$' and vals[i][1:].isdigit():
                val = float(vals[i][1:])
                val -= val*(discount/100)
                vals[i] = '$' + '{0:.2f}'.format(val)
        return ' '.join(vals)
