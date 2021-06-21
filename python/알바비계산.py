#응용문제1 : Part-time calculation Program
name = str(input('alba name : '))
hour = int(input('hour: '))
pay = int(input('pay : '))

total = hour * pay

print(total)

#출력방법
#1. 콤마연산자사용
print(name ,'님의 총 금액은',total, '원 입니다. 수고많으셨습니다.^^')

#2. 형식문자(서식문자) 사용 : 정수(%d), 실수(%f), 문자열(%s)
print('알바생의 이름은 %s 입니다' % name)
print('총금액은 %d 입니다' % total)

#3. 문자열 .format()함수
print('알바생의 이름은{}입니다'.format(name))
print('%s님의 총금액은 %d원입니다.' % (name, total))

#4. f-string 사용
print(f'알바생의 이름은 {name}입니다.')
print(f'총금액은 {total}입니다.')


