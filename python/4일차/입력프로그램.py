f = open('out.txt', 'w', encoding='utf-8')

for i in range(3):
    num = input('num : ')
    f.write(num + '\n')
print('파일저장완료')
f.close()
