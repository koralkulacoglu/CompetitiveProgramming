import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    # return students[students['student_id'] == 101].drop('student_id', axis=1)
    return students.loc[students['student_id'] == 101, ['name', 'age']]
