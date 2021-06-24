f = open('data.txt')

sum = 0
count = 0
fin = f.readlines()
for line in fin:
    sum += int(line)
    count += 1

print('합계 = ', sum)
print('평균 = ', sum / count)

f = open('out.txt', 'w', encoding='utf-8')

f.write('합계 = ' + str(sum) + '\n')
f.write('평균 = ' + str(sum / count) + '\n')

print('파일저장완료')
f.close()
