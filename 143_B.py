def flag(str):
    str0=str.lower()
    if str0 == str0[::-1]:
        return 1
    else:
        return 0
count=0

try:
    while True:    
        str=input()
        for i in str.split(" "):
            count+=flag(i)
except:
    pass
print(count)