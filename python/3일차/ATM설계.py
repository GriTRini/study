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

def question():
    while True:
        doing = (input('다른 업무를 진행하시겠습니까? y/n '))
        if doing == 'y' or doing == 'n':
            if doing == 'y':
                return True
            elif doing == 'n':
                return False
        else:
            print('다시 입력해주세요')
            continue


# 잔액변수
balance = 0
while True:

    do = int(input('조회(1), 입금(2), 출금(3) what do you want? '))
    if do in range(1, 4):
        if do == 1:
            print('현재 통잔잔고는 = ', inquiry(), '원 입니다.')
        elif do == 2:
            amount = int(input('please input your money = '))
            print('현재 통잔잔고는 = ', deposit(amount), '원 입니다.')
        elif do == 3:
            amount = int(input('please input your money = '))
            if balance >= amount:
                print('현재 통잔잔고는 = ', withdrawal(amount), '원 입니다.')
            else:
                print('통장에 있는 금액이 부족합니다. 현재 통장에 있는 금액은', inquiry(), '입니다.')
                continue
    else:
        print('숫자를 다시 입력해 주세요')

    if question():
        continue
    else:
        break

