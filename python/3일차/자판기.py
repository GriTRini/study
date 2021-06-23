mlist = ['뜨아', '아아', '라떼', '모카']
plist = [2000, 3000, 3500, 4000]

def pay():
    global coffee
    global total
    total = total - plist[coffee - 1]
    return total

for i in range(1, 5):
    print(i,':', mlist[i-1] , plist[i-1])

amount = int(input('how much = '))
total = amount
while True:
    coffee = int(input('메뉴선택 (종료 : 0) '))
    if total >= plist[coffee - 1] and coffee > 0:
        if coffee in range(1, 5):
            print(mlist[coffee - 1], '구매')
            print('잔액은 ', pay())
        else:
            print('메뉴를 다시 확인하세요.')
    elif coffee == 0:
        print('종료 잔액', total, '반환')
        break

    else:
        print('돈이 부족합니다.')
        break


