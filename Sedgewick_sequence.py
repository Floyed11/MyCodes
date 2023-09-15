def do0(n):
    return pow(4,n)-3*pow(2,n)+1

def do1(n):
    return 9*pow(4,n)-9*pow(2,n)+1

n=int(input())
p0=0
p1=0
list0=[]
while (do0(p0)<n):
    p0=p0+1
while (do1(p1)<n):
    p1=p1+1
p0=p0-1
p1=p1-1
while(do0(p0)>0 or do1(p1)>0):
    list0.append(max(do0(p0),do1(p1)))
    if (do0(p0)>do1(p1)):
        p0=p0-1
    else:
        p1=p1-1
print(list0)