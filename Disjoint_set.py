'''making representative of their own'''
def makeset(n):
    par[n] = n

'''making friend by merging two representitive'''
def union(a,b):
    u = find(a)
    v = find(b)
    if u == v:
        print("Already friends") 
    else:
        print("Made", u ,"and", v ,"friend")
        par[u] = v

'''finding representitive recursively'''
def find(n):
    if par[n] == n:
        return n
    
    par[n] = find(par[n])
    return par[n]
        
def isfriend(a , b):
    u = find(a)
    v = find(b)
    if u == v:
        print(a , "and" , b , "are friends")
    else:
        print(a , "and" , b , "are not friends")

element = 5
par = [None] * (element+1)

for i in range(1 , element+1):
    makeset(i)
    
union(1,5)
union(1,5)
isfriend(1,3)
isfriend(1,5)
