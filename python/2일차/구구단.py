import random

while True:
  f = random.randint(1, 9)
  r = random.randint(1, 9)
  ua = int(input(f'{f} * {r} = '))
  ca = f * r

  if ua == ca:
    print('정답')
  elif ua == 0:
    print('사용자에 의해 프로그램 종료')
    break
  else:
    print('오답')