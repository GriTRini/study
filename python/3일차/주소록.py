address = { '짱구' : '010-5458-9658', '다롱이' : '010-8754-8744'}

while True:
    num = int(input('1) 친구추가 2) 친구검색 3) 종료 '))
    if num in range(1, 3):
        if num == 1:
            name = input('name = ')
            phone = input('phone = ')
            if name in address:
                print('주소록 안에 있는 이름 입니다.')
                continue
            else:
                address[name] = phone
        elif num == 2:
            name = input('name = ')
            if name in address:
                print(address[name])
            else:
                print('주소록에 존재하지 않습니다. 추가해주세요')
                continue
    elif num == 0:
        print('end')
        break
    else:
        print('잘못 입력')
        continue