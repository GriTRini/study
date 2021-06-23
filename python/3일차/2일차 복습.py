
while True:
    pw = 'admin'
    count = 0
    upw = input('please input password = ')

    if upw == pw:
        print('환영합니다.')
        break
    else:
        print('암호가 틀립니다')
        count += 1

    if count == 3:
        print('접속을 거부합니다.')
        break
