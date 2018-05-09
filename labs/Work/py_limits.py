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
    print(reader.__next__())


