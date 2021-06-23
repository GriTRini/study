def gugudan(d):
    if 2<=d:
        for i in range(d, d+1):
            for j in range(1, 10):
                print(i, 'x', j, '=', i*j)
    else:
        print('잘못 입력됨')

d = int (input('please input gugudan num = '))
gugudan(d)
print('end')
