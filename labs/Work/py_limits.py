# 1. import and parse the header
# 2. find side, active volume and filled volume, price
# 3. count BOV, SOV, BTV, STV
# 4. show table (identical to the one in the Front End)
import csv
import sys


#1
filename = str(sys.argv[1])

with open(filename, 'r', newline='') as fn:
    reader = csv.reader(fn, delimiter=';')
    header = reader.__next__()

    #2
    columns = {}
    columnKeys = ['Active #', 'Filled #', 'Price', 'Side', 'Factor']
    for key in columnKeys:
        for i in range(len(header)):
            if header[i] == key:
                columns[key] = i
    if len(columns) != len(columnKeys):
        print("Warning! Some values are absent.")
    print(columns['Side'])

    buyOrderVolume = 0
    buyOrderValue = 0
    buyTradeVolume = 0
    buyTradeValue = 0

    sellOrderVolume = 0
    sellOrderValue = 0
    sellTradeVolume = 0
    sellTradeValue = 0


    #3
    for row in reader:
        if(row[columns['Side']] == 'Buy'):
            buyOrderVolume += float(row[columns['Active #']])
            buyOrderValue += float(row[columns['Active #']])*float(row[columns['Price']])* float(row[columns['Factor']])
            buyTradeVolume += float(row[columns['Filled #']])
            buyTradeValue += float(row[columns['Filled #']])*float(row[columns['Price']])*float(row[columns['Factor']])
        if (row[columns['Side']] == 'Sell'):
            sellOrderVolume += float(row[columns['Active #']])
            sellOrderValue += float(row[columns['Active #']]) * float(row[columns['Price']]) * float(row[columns['Factor']])
            sellTradeVolume += float(row[columns['Filled #']])
            sellTradeValue += float(row[columns['Filled #']]) * float(row[columns['Price']]) * float(row[columns['Factor']])
    print("buyOrderVolume = {}\nbuyOrderValue = {}\nbuyTradeVolume = {}\nbuyTradeValue = {}\n".format(buyOrderVolume,\
        buyOrderValue, buyTradeVolume,buyTradeValue))
    print("sellOrderVolume = {}\nsellOrderValue = {}\nsellTradeVolume = {}\nsellTradeValue = {}\n".format(sellOrderVolume,\
        sellOrderValue, sellTradeVolume,sellTradeValue))
print("L Vol pI\tS Vol pI\tL Vol pU\tS Vol pU\tL Val pI\tS Val pI\tL Val pU\tS Val pU\tNV\tN Vol pI\tN vol pU\tGV\n");
print("{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\n".format(buyOrderVolume, sellOrderVolume, \
    buyOrderVolume, sellOrderVolume, \
    buyOrderValue+buyTradeValue-sellTradeValue, sellOrderValue+sellTradeValue-buyTradeValue, \
    buyOrderValue + buyTradeValue - sellTradeValue, sellOrderValue + sellTradeValue - buyTradeValue, \
    max(buyOrderValue+buyTradeValue-sellTradeValue, sellOrderValue+sellTradeValue-buyTradeValue), \
    max(buyOrderVolume+buyTradeVolume-sellTradeVolume, sellOrderVolume+sellTradeVolume-buyTradeVolume), \
    max(buyOrderVolume + buyTradeVolume - sellTradeVolume, sellOrderVolume + sellTradeVolume - buyTradeVolume), \
    buyOrderValue + buyTradeValue + sellOrderValue + sellTradeValue))


