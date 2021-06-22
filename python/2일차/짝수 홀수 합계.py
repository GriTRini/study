s = int (input('start num = '))
e = int (input('end num = '))

sum1 = 0
sum2 = 0
for i in range(s, e):
    if i%2 == 0:
        sum1 += i
    else:
        sum2 += i

print('짝수의 합 = ', sum1)
print('홀수의 합 = ', sum2)
print('합계 = ', sum1+sum2)
