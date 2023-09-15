import random
result=set()
while len(result)<5:
    result.add(random.randint(1,10))
print(result)

month_dict={1:'J',2:'F',3:'M',4:'A',5:'M',6:'J',7:'J',8:'A',9:'S',10:'O',11:'N',12:'D'}
mon=int(input())
print(month_dict.get(mon))
