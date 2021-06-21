# 로그인 프로그램
# 사용자로부터 id,pw를 입력받아 일치하면 로그인 성공
# 그렇지 않으면 로그인 실패

id = input('id = ')
pw = input('pw = ')

saveid = str ('aaaa')
savepw = str ('bbbb')

if saveid == id and savepw == pw:
  print('로그인 성공')
else:
  print('로그인 실패')