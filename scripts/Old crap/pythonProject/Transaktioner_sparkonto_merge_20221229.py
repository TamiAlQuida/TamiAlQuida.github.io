import matplotlib.pyplot as plt
import pandas
#import matplotlib as plt

df = pandas.read_csv("transaktioner_sparkonto_merge_ 20221229.csv", parse_dates=['Bokforingsdag'])

print(df)

df.to_csv('Transaktioner sparkonto modified.csv')


datum_saldo = ['Bokforingsdag', 'Bokfort saldo']
datum = ['Bokforingsdag']
saldo = ['Bokfort saldo']

print(df[datum_saldo])
print(df[datum])
plt.plot(df[datum], df[saldo])
# plt.scatter(datum, saldo)
plt.show()
