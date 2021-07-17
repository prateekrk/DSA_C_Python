a=[1,2,3,4,5,6]
s=10
for i in a:
    rem=s-i
    if(rem in a and i!=rem):
        print(i,rem)