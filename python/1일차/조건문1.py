# 파이썬 선택문(조건문)
# >=, <=, ==, !=
# 단순 선택문
n = 80
if n>=60:
    print('합격')
else:
    print('불합격')
print('end')

# 다중 선택문 if ~elif.....else
n=int(input('num = '))
if n>=90:
    grade = 'A'
elif n>=80 and n<90:
    grade = 'B'
else:
    grade = 'C'
