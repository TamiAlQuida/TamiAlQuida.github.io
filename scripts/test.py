import pandas as pd
import numpy as np
from matplotlib import pyplot as plt

dagar = [0, 5, 6, 8, 9]

df3 = pd.DataFrame({'person':'Tom', 'danskadagar':[5, 2, 3, 7, 9], 'dagar':dagar})

df1 = pd.DataFrame({'person':'Pauline', 'danskadagar':[5, 6, 1, 2, 3], 'dagar':[9, 5, 7, 1, 3]})

df2 = df1.append(df3)

#print(df3)
#print(df1)

print(df2)

keys = df2
danskadagar= df2['danskadagar']
dagar= df2['dagar']
print(keys)
print(danskadagar)

plt.bar('danskadagar', danskadagar)
plt.bar('dagar', dagar)
plt.show()
