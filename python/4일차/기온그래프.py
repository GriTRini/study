# csv모듈
import csv
import matplotlib.pyplot as plt
f = open('tmp.csv')
print(csv.reader(f))
data = csv.reader(f)
header = next(data)
# print(header)
#print(list(data)) # 리스트 형태 형변환
# for row in data:
#     print(row[-1])

#1. 최고기온과 일자 새로운 리스트에 저장
uptmp = []
date = []
for row in data:
    if row[2] != '':
        date = row[0].split('-')
        if date[1] == '02' and date[2] == '26':
            uptmp.append(float(row[2]))
print(uptmp)

#2. 최고기온의 평균
sum = 0
for i in range(0, len(uptmp)):
    sum += uptmp[i]
print('합계 = ', sum)
print('평균 = ', round(sum / len(uptmp)))

plt.plot(uptmp, color = 'g', label = '최고기온')
plt.show()
f.close()






