# 파일 입출력 단계
## 파일출력
## 1. 파일열기
```python
f=open('data.txt')
```
## 2. 파일처리
> readline() - str 반환,   readlines() - list 반환
```python
for fin in range(0, 3):
    fin = f.readline()
    print(fin, end = '')
```    
```python
while True:
    fin = f.readline()      # 한줄씩 읽어옴
    if fin == '':
        break
    print(fin, end = '')

```
```python
print(type(f.read()))
print(f.read())
```
## 3. 파일닫기
```python
f.close()
```

## 파일 입력
```python
f=open('member.txt', 'w', encoding='utf-8')
f.write('seonghyeon' + '\n')
for i in range(3):
    name = input('name : ')
    f.write(name + '\n')
print('파일저장완료')
f.close()
```
## 전처리 함수 (map)
> str을 int형으로 형변환
```python
num = ['10', '30', '40']
result = list(map(int,num))
print(result)
```

## 그래프 그리기
```python
import matplotlib.pyplot as plt
plt.plot([10, 20, 30, 40])
plt.show()
```
> title - 제목, color - 색추가, legend(), label - 범례
```python
import matplotlib.pyplot as plt
plt.title('mid score')
plt.plot([10, 20, 30, 40], color = 'r', label = 'min')
plt.plot([20, 30, 50, 10], color = 'g', label = 'man')
plt.legend()
plt.show()
```

##  csv파일 가져와서 그래프 만들기
```python
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
```

## 위젯 만들기
```python
#import tkinter
from tkinter import *
from tkinter.messagebox import  *
from tkinter.font import *

def ok():
    t.config(image = photo2)

def cancel():
    showinfo('cancel', '취소 버튼이 눌러짐')
w = Tk()    # 윈도우 생성
w.title('첫번째 gui')
f = Font(family = '맑은 고딕', size = 22)

#이미지 불러오기
photo1 = PhotoImage(file = 'good2.png')
photo2 = PhotoImage(file = 'good1.png')

t = Label(w, image = photo1, fg = 'red', bg = 'white', font = f)
id = Entry(w)
pw = Entry(w, show = '*')

btn1 = Button(w, text = '확인', command = ok)
btn2 = Button(w, text = '취소', command = cancel)
btn3 = Button(w, text = '종료', command = quit)
#위젯배치   : pack(), place(), grid()
t.pack()
id.pack()
pw.pack()
btn1.pack()
btn2.pack()
btn3.pack()

w.geometry('1000x800')

w.mainloop()
```

## 로그인 위젯 만들기
```python
from tkinter import *
from tkinter.messagebox import  *

def login():
    if id.get() == '20177088' and pw.get() == '950226':
        showinfo('Logged IN Successfully', '로그인에 성공하셨습니다')
    else:
        showinfo('Check your Usernam/Password', '아이디 또는 비밀번호를 확인해주세요')
def cancel():
    showinfo(('cancel', '취소'))

#윈도우창 만들기
w = Tk()
w.title('순천대학교에 오신걸 환영합니다')

#이미지 불러오기
photo1 = PhotoImage(file = 'scnu.png')

t1 = Label(w, image = photo1)

# 버튼 만들기
id = Entry(w)
pw = Entry(w, show = '*')

btn1 = Button(w, text = 'Login', command = login)
btn2 = Button(w, text = 'Cancel', command = cancel)
btn3 = Button(w, text = '종료', command = quit)

#위젯배치   : pack(), place(), grid()
t1.pack()
id.pack()
pw.pack()
btn1.pack()
btn2.pack()
btn3.pack()


w.geometry('700x500')

w.mainloop()
```


