a = input()
k = int(input())
b,c = a.split('.')
lb = len(b)
lc = len(c)
b0=[0] * lb
c0=[0] * lc

for i in range(lb):
    if b[i].isdigit():
        b0[i]=int(b[i])
    else:
        b0[i]=ord(b[i])-ord('a')+10
for i in range(lc):
    if c[i].isdigit():
        c0[i]=int(c[i])
    else:
        c0[i]=ord(c[i])-ord('a')+10
c0 = c0[::-1]
temp0=b0[0]
temp1=c0[0]

# print(b0)
# print(c0)

for i in range(lb-1):
    temp0 = temp0*k+b0[i+1]
for i in range(lc-1):
    temp1 = temp1/k+c0[i+1]
temp1=temp1/k
print("{:.4f}".format(temp0+temp1))