import requests
from bs4 import BeautifulSoup
import pandas as pd

url = 'https://www.kylc.com/uprate/myr.html'
page = requests.get(url)
soup = BeautifulSoup(page.content, 'html.parser')

print('CNY->MYR 汇率查询器 (括号内是与银联汇率相比)\n')


## 表 1 支付宝 银联
table = soup.find_all('table')[0]
df = pd.read_html(str(table))[0]

# 支付宝汇率
alipay_rate = float(df.iloc[0, 1])

# 银联汇率
unionpay_rate = float(df.iloc[1, 1])


print('银联汇率: \t{}\n'.format(unionpay_rate))

alipay_percentage = (alipay_rate - unionpay_rate) / unionpay_rate * 100
print('支付宝汇率: \t{} ({:+.1f}%)'.format(alipay_rate, alipay_percentage))


## 表2 银行
table = soup.find_all('table')[1]
df = pd.read_html(str(table))[0]

# a汇率
an = (df.iloc[0,0])
a = float(df.iloc[0, 1])

# b汇率
bn = (df.iloc[1,0])
b = float(df.iloc[1, 1])

# c汇率
cn = (df.iloc[2,0])
c = float(df.iloc[2, 1])

# d汇率
dn = (df.iloc[3,0])
d = float(df.iloc[3, 1])

# e汇率
en = (df.iloc[4,0])
e = float(df.iloc[4, 1])


a_percentage = (a - unionpay_rate) / unionpay_rate * 100
print(an+'汇率: \t{} ({:+.1f}%)'.format(a, a_percentage))

b_percentage = (b - unionpay_rate) / unionpay_rate * 100
print(bn+'汇率: \t{} ({:+.1f}%)'.format(b, b_percentage))

c_percentage = (c - unionpay_rate) / unionpay_rate * 100
print(cn+'汇率: \t{} ({:+.1f}%)'.format(c, c_percentage))

d_percentage = (d - unionpay_rate) / unionpay_rate * 100
print(dn+'汇率: \t{} ({:+.1f}%)'.format(d, d_percentage))

e_percentage = (e - unionpay_rate) / unionpay_rate * 100
print(en+'汇率: \t{} ({:+.1f}%)'.format(e, e_percentage))