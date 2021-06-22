menu = {}
menu['김밥'] = 1000
menu['라면'] = 3000
menu['참치마요'] = 4000
print('물품리스트', list(menu.keys()))
m = input('menu: ')
if m in menu:
    print(m, menu[m])
else:
    print('error')
