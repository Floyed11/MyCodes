y = int(input("请输入年份："))
m = int(input("请输入月份："))
d = int(input("请输入日期："))
flag_leap = y % 400 == 0 or ((y % 4 == 0) and (y % 100 != 0))
m0 = m-1
num = d
num += 31 * m0 - (m0 >= 2)*3 - (m0 >= 4) - (m0 >= 6) - (m0 >= 9) - (m0 >= 11)
if m >= 3:
    num+=flag_leap
print("你输入的日期：{}年{}月{}日是该年的第{}天".format(y,m,d,num))