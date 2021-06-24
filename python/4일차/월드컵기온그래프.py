import csv
import matplotlib.pyplot as plt
# csv 파일 열기
f = open('worldcup.csv')

# 헤더파일 출력
print(csv.reader(f))
data = csv.reader(f)
header = next(data)
print(header)

# 2002년 6월 최고기온, 최저기온, 평균기온, 일교차 리스트 저장
uptmp = []
lowtmp = []
avgtmp = []
datmp = []
for row in data:
    if row[2] != '':
        date = row[0].split('-')
        if date[0] == '2002' and date[1] == '06':
            uptmp.append(float(row[2]))
            lowtmp.append(float(row[3]))
            avgtmp.append(float(row[1]))
            datmp.append(float(row[4]))

# 그래프 출력
plt.title('2002 worldcup seoul tmperature')
plt.plot(uptmp, color = 'r', label = 'uptmp')
plt.plot(lowtmp, color = 'b', label = 'lowtmp')
plt.plot(avgtmp, color = 'y', label = 'avgtmp')
plt.plot(datmp, color = 'g', label = 'datmp')
plt.legend()
plt.show()
f.close()