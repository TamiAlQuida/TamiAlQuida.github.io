#tickers = [ 'AAPL', 'MSFT', 'BRK-B','AMZN', 'TSLA', 'META', 'UNH', 'V', 'NVDA', 'JNJ', 'XOM', 'WMT', 'JPM', 'PG', 'MA', 'HD', 'LLY', 'PFE', 'CVX', 'BAC', 'KO', 'ABBV', 'COST', 'PEP', 'MRK', 'TMO', 'AVGO', 'DHR', 'VZ', 'ORCL', 'ABT', 'ADBE', 'ACN', 'DIS', 'CMCSA', 'MCD', 'CSCO', 'CRM', 'QCOM', 'NKE', 'TMUS', 'INTC', 'WFC', 'UPS', 'BMY', 'NEE', 'TXN', 'AMD', 'MS', 'PM', 'LIN', 'RTX', 'T', 'UNP', 'AMGN', 'LOW', 'SPGI', 'HON', 'CVS', 'MDT', 'INTU', 'SCHW', 'AMT', 'COP', 'IBM', 'AXP', 'GS', 'ELV', 'LMT', 'C', 'NFLX', 'BLK', 'DE', 'CAT', 'PYPL', 'SBUX', 'BA', 'EL', 'PLD', 'NOW', 'ADP', 'AMAT', 'ADI', 'ZTS', 'MDLZ', 'CI', 'CHTR', 'ISRG', 'DUK', 'MMC', 'CB', 'GOOG', 'GOOGL', 'MO', 'GILD', 'MMM', 'SYK', 'SO', 'GE', 'CCI', 'TJX', 'BKNG', 'CME', 'TGT', 'VRTX', 'USB', 'NOC', 'MU', 'BDX', 'CSX', 'MRNA']
#
#tickers_string = ""
#
#for i in tickers:
#    tickers_string += i + ","
#
#print(tickers_string)

import pandas as pd

data = pd.read_csv("/home/tomcarl/TamiAlQuida.github.io/scripts/Old_crap/pythonProject/s&p500list.csv")
print(data)

data_string = ""

for i in data['Symbol']:
    data_string += i + ","

#print(data_string)

data_string_formated = data_string.replace(".", "-")

print(data_string_formated)