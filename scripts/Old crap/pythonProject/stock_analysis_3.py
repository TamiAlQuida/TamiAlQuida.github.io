
import pandas as pd
import requests

# ticker = input("What stock/ticker do you want to analyse?")
ticker = 'AAPL'

""" Request the page"""
page_summary = f'https://finance.yahoo.com/quote/{ticker}?p={ticker}'
page_analysis = f'https://finance.yahoo.com/quote/{ticker}/analysis?p={ticker}'

headers = {'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/113.0'}

print("V = EPS * (1 + r) * P/E")
print("V = Intrinsic Value \n"
      "EPS = Earnings per share \n"
      "r = Expected earnings growth rate \n"
      "P/E = price per earnings \n")

"""Parsing the page"""
summary_EPS_PE = pd.read_html(requests.get(page_summary, headers=headers).text)[1]
analysis_growth_estimates = pd.read_html(requests.get(page_analysis, headers=headers).text)[5]
print(summary_EPS_PE)
#print(analysis_growth_estimates)

summary_EPS_PE_numbers = summary_EPS_PE[1]
pe = float(summary_EPS_PE_numbers.values.tolist()[2])
eps = float(summary_EPS_PE_numbers.values.tolist()[3])

growth_estimates_ticker = analysis_growth_estimates[ticker]
r = float(growth_estimates_ticker.values.tolist()[-2].replace("%",""))

print(summary_EPS_PE_numbers)
print(pe)
print(eps)
print(r)

v = pe * eps * r
print(v)
