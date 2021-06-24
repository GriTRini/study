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