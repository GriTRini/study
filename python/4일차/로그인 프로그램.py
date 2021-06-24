from tkinter import *
from tkinter.messagebox import  *

def login():
    if id.get() == '20177088'and pw.get() == '950226':
        showinfo('Logged IN Successfully', '로그인에 성공하셨습니다')
    elif id.get() != '20177088':
        showinfo('Check your ID', '아이디를 확인해주세요')
    elif id.get() == '20177088' and pw.get() != '950226':
        showinfo('Check your Password', '비밀번호를 확인해주세요')
    elif id.get() != '20177088' and pw.get() != '950226':
        showinfo('Check your ID/Password', '아이디 또는 비밀번호를 확인해주세요')

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