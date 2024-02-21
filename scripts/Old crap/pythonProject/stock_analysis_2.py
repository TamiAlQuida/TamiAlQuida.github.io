import time

from pandas_datareader import data
import matplotlib.pyplot as plt
import pandas as pd
import scrapy

from lxml import html
import requests

# ticker = input("What stock/ticker do you want to analyse?")

""" Request the page"""
page_summary = requests.get('https://finance.yahoo.com/quote/AAPL?p=AAPL')
page_analysis = requests.get('https://finance.yahoo.com/quote/AAPL/analysis?p=AAPL')

"""Parsing the page
(We need to use page.content rather than 
page.text because html.fromstring implicitly
expects bytes as input.)"""
tree_summary = html.fromstring(page_summary.content)
tree_analysis = html.fromstring(page_analysis.content)

print("V = EPS * (8.5 + 2*g) * 4.4 / Y")
print("V = Intrinsic Value \n"
      "EPS = Earnings per share \n"
      "8.5 = P/E Base for s No-Growth company \n"
      "g = Growth rate fo next 5 years \n"
      "4.4 = Average yield of AAA corporate Bonds"
      "Y = Current yield of AAA Corporate bonds")

"""copy/paste xpath directly from web page to get the wanted values"""
PE_ratio = tree_summary.xpath('/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/div/div/div/div[2]/'
                              'div[2]/table/tbody/tr[3]/td[2]/text()')
print('PE_ratio:', PE_ratio)

time.sleep(1)

EPS = tree_summary.xpath('/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/div/div/div/div[2]/div[2]/'
                         'table/tbody/tr[4]/td[2]/text()')
print('EPS:', EPS)

time.sleep(1)

g = tree_analysis.xpath('/html/body/div[1]/div/div/div[1]/div/div[3]/div[1]/div/div[1]/'
                        'div/div/section/table[6]/tbody/tr[6]/td[2]/text()')

print("g (growth rate for next 5 years per year):", g)
