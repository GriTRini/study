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
