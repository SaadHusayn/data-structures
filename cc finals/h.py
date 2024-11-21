n = int(input())

sum=0
while(n>0):
    sum+=n%10
    n//=10

if sum%9==0:
    print("Yes\n")
else:
    print("No\n")
