class Spreadsheet:
    def __init__(self, rows: int):
        self.mp = {}

    def setCell(self, cell: str, value: int) -> None:
        self.mp[cell] = value
        
    def resetCell(self, cell: str) -> None:
        self.mp[cell] = 0

    def getValue(self, formula: str) -> int:
        return sum([(int(x) if x.isdigit() else (self.mp[x] if x in self.mp else 0)) for x in formula[1:].split('+')])
        


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)
