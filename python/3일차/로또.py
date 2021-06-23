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