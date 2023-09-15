print("please input the line: ",end='')
n = int(input())
while (n > 26):
    print("行数过大")
    print("please input the line: ",end='')
    n = int(input())
print()
for i in range(1,n+1):
    for j in range(1,n-i+1):
        print(' ',end='')
    for k in range(1,2*i):
        print('*',end='')
    print()
for i in range(n):
    for j in range(i):
        print(' ',end='')
    for k in range(2*n-1-2*i):
        print('*',end='')
    print()