import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals.sort_values(by='weight', ascending=False)[animals['weight'] > 100][['name']]
