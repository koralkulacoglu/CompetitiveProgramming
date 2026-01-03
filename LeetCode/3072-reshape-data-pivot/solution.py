import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    weather = pd.pivot_table(weather, index='month', columns='city', values='temperature', aggfunc='max')
    return weather
