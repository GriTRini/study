while True:
    count = 0
    print('1번, 2번, 3번, 4번, 5번 옷중에')
    select = input('원하는 옷을 선택해주세요 ')
    if select == '1':
        select1 = input('옷 가격이 35000원 입니다. 구매하시겠습니까? Y/N ')
        if select1 == 'Y':
            count += 35000
            yn1 = input('다른 옷을 추가로 구매하겠습니까? Y/N ')
            if yn1 == 'Y':
                print('현재 금액은', count, '입니다.')
                continue
            else:
                break
        else:
            continue
    if select == '2':
        select2 = input('옷 가격이 25000원 입니다. 구매하시겠습니까? Y/N ')
        if select2 == 'Y':
            count += 25000
            yn2 = input('다른 옷을 추가로 구매하겠습니까? Y/N ')
            if yn2 == 'Y':
                print('현재 금액은', count, '입니다.')
                continue
            else:
                break
        else:
            continue
    if select == '3':
        select3 = input('옷 가격이 15000원 입니다. 구매하시겠습니까? Y/N ')
        if select3 == 'Y':
            count += 15000
            yn3 = input('다른 옷을 추가로 구매하겠습니까? Y/N ')
            if yn3 == 'Y':
                print('현재 금액은', count, '입니다.')
                continue
            else:
                break
        else:
            continue
    if select == '4':
        select4 = input('옷 가격이 40000원 입니다. 구매하시겠습니까? Y/N ')
        if select4 == 'Y':
            count += 40000
            yn4 = input('다른 옷을 추가로 구매하겠습니까? Y/N')
            if yn4 == 'Y':
                print('현재 금액은', count, '입니다.')
                continue
            else:
                break
        else:
            continue
    if select == '5':
        select5 = input('옷 가격이 10000원 입니다. 구매하시겠습니까? Y/N ')
        if select5 == 'Y':
            count += 10000
            yn5 = input('다른 옷을 추가로 구매하겠습니까? Y/N ')
            if yn5 == 'Y':
                print('현재 금액은', count, '입니다.')
                continue
            else:
                break
        else:
            continue

print('총 금액은 ', count, '입니다. ')

