import pandas as pd

def market_analysis(users: pd.DataFrame, orders: pd.DataFrame, items: pd.DataFrame) -> pd.DataFrame:
    orders_2019 = orders[orders['order_date'].dt.year == 2019]
    orders_count = orders_2019.groupby('buyer_id').size().reset_index(name='orders_in_2019')
    result = pd.merge(users, orders_count, left_on='user_id', right_on='buyer_id', how='left')
    result['orders_in_2019'] = result['orders_in_2019'].fillna(0).astype(int)
    result = result[['user_id', 'join_date', 'orders_in_2019']]
    result.columns = ['buyer_id', 'join_date', 'orders_in_2019']
    return result
