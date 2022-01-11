'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-11-30 20:14:02
LastEditors: lxp
LastEditTime: 2021-11-30 20:14:05
'''
name = input('Enter file:')
handle = open(name, 'r')
counts = dict()

for line in handle:
    words = line.split()
    for word in words:
        counts[word] = counts.get(word, 0) + 1

bigcount = None
bigword = None
for word, count in list(counts.items()):
    if bigcount is None or count > bigcount:
        bigword = word
        bigcount = count

print(bigword, bigcount)

# Code: http://www.py4e.com/code3/words.py
