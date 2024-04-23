import matplotlib.pyplot as plt
import pandas
#import matplotlib as plt

df = pandas.read_csv("Transaktioner sparkonto.csv", parse_dates=['Bokforingsdag'])

print(df)

df.to_csv('Transaktioner sparkonto modified.csv')


datum_saldo = ['Bokforingsdag', 'Bokfort saldo']
datum = ['Bokforingsdag']
saldo = ['Bokfort saldo']

print(df[datum_saldo])

plt.scatter(datum, saldo)
plt.show()
