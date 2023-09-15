import math
def avr(arg):
    temp=0.0
    for i in arg:
        temp+=i
    temp=temp / len(arg)
    return temp

def covariance(arg1,arg2):
    average1=avr(arg1)
    average2=avr(arg2)
    temp=0.0
    for i in range(len(arg1)):
        temp+=(arg1[i]-average1)*(arg2[i]-average2)
    temp=temp / (len(arg1)-1)
    return temp

def highest_score(arg):
    temp=[liName[arg.index(max(arg))],max(arg)]
    return temp

liYu=[86,97,98,77,92,94,99,97]
liMa=[92,91,93,88,96,91,91,88]
liEn=[100,96,94,60,97,92,93,86]
liName=['太史慈','臧霸','张角','曹真','王朗','马谡','姜维','徐庶']
print("语文课的平均成绩{}，最高分：{}（{}分）".format(avr(liYu),highest_score(liYu)[0],highest_score(liYu)[1]))
print("数学课的平均成绩{}，最高分：{}（{}分）".format(avr(liMa),highest_score(liMa)[0],highest_score(liMa)[1]))
print("英语课的平均成绩{}，最高分：{}（{}分）".format(avr(liEn),highest_score(liEn)[0],highest_score(liEn)[1]))
print("语文与数学的协方差是{:.3f}".format(covariance(liYu,liMa)))
print("英语与数学的协方差是{:.3f}".format(covariance(liEn,liMa)))
print("语文与英语的协方差是{:.3f}".format(covariance(liYu,liEn)))