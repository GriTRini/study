## 반환값이 없는 함수정의
```python
# 함수 정의
def sing(name): # 매개변수 = parameter
    print(name,'학생')
    print('생일축하합니다')
    print('생일축하합니다')

# 메인코드
# 함수호출
name = input('name : ')
sing(name)
print('end')
```

## 반환값이 있는 함수정의
```python
def add(n1, n2):
    result = n1 + n2
    return result

def div(n1, n2):
        result = n1 / n2
        return result

def mul(n1, n2):
    result = n1 * n2
    return result

def sub(n1, n2):
    result = n1 - n2
    return result

while True:
    n1 = int (input('please first num = '))
    code = input('please code = ')
    n2 = int (input('please second num = '))

    if code == '+':
        print('add : ', add(n1, n2))
    elif code == '*':
        print('mul : ', mul(n1, n2))
    elif code == '/':
        if n2 == 0:
            print('error')
        else:
            print('div : ', div(n1, n2))
    elif code == '-':
        if n2 >= n1:
            n1, n2 = n2, n1
            print('sub : ', sub(n1, n2))
        else:
            print('sub : ', sub(n1, n2))

    c = input('continue ? y/n ')

    if c == 'n':
        break
```
## 지역변수, 전역변수
```python
# 함수정의
def func1():
    a = 20 # 지역변수
    print(a)

# 메인코드
a = 10 # 전역변수
func1()
print(a)
```
```python
# ATM 설계
# 조회(inquiry), 인출(Withdrawal), 입금(Deposit)
def deposit(amount):
    global balance
    balance += amount
    return balance
    
def withdrawal(amount):
    global balance
    balance -= amount
    return balance

def inquiry():
    return balance

# 잔액변수
balance = 0
while True:
    amount = int (input('please input your money = '))
    print('조회, 인출, 출금')
    do = input('what do you want? ')
    if do == '조회':
        print('현재 통잔잔고는 = ', inquiry(),'원 입니다.')
    elif do == '입금':
        print('현재 통잔잔고는 = ', deposit(amount),'원 입니다.')
    elif do == '출금':
        if balance >= amount:
            print('현재 통잔잔고는 = ', withdrawal(amount),'원 입니다.')
        else:
            print('통장에 있는 금액이 부족합니다.')
            continue
```

## random
```python
# random, turtle, tkinter
# import random as r
from random import *
# 함수정의
def getNum():
    r = randint(1, 45)
    return r

lotto = []
while True:
    r = getNum()
    # 중복체크
    if lotto.count(r) == 0:
        lotto.append(r)
    if len(lotto) == 6:
        break
# 출력
print('추첨된 로또 번호', end = ' ')
lotto.sort()
for i in range(6):
    print(f'{lotto[i]}', end = ' ')

# 추가문제 : 보너스 번호
while True:
    bonus = getNum()
    if lotto.count(bonus) == 0:
        break
print()
print(f'{lotto} + {bonus}')
```