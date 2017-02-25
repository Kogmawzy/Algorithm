
def print_per(a,b):
    if(len(b)==0):
        print a
    else:
        for i in b:
            print_per(a+[i],b-set([i]))


s=set([1,2,3,4,5])
a=[]
print_per(a,s)