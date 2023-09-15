import string
str = "IT WAS the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity. How many times you failed the test? A lot of times?"
s = str.split(' ')
dic = {}
for element in s:
    if not(element.isalpha()):
        element = element[0:len(element)-1]
    # print(element)
    if (element.lower() in dic.keys()):
        dic[element.lower()]+=1
    else:
        dic[element.lower()]=1
L = sorted(dic.items(),key=lambda item:item[1],reverse=True)
for i in L[0:6]:
    print(i,end=' ')