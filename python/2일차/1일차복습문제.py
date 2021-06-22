# 변수, 연산자, 선택문 리뷰문제
# 복권번호(두자리 정수) : 10 ~99
# 두자리 모두 일치 : 100
# 한자리만 일치 : 50
# 그외 : 없다

lotto = 55
num1 = int (input('Put in the your num = '))

if num1 == lotto:
    print('100')
elif num1 % 10 == lotto % 10 or num1 // 10 == lotto // 10:
    print('50')
else:
    print('없다')