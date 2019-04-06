def DPChange(M , c , d):
    taken = []
    bestnumcoins = [100000] * (M+1)
    bestnumcoins[0] = 0
    for i in range(1 , M+1):
        for j in range(1 , d+1):
            if M > c[j]:
                if bestnumcoins[i - c[j]] + 1 < bestnumcoins[i]:
                    bestnumcoins[i] = bestnumcoins[i - c[j]] + 1
                    par[i] = i -c[j]
                    
        
    return bestnumcoins[M]

d = input("Number of coins? :")
d = int(d)
c = [0] * (d+1)
for i in range(1 , d+1):
    c[i] = input()
    c[i] = int(c[i])
M = input("Amount? :")
M = int(M)
par = [0] * (M+1)
a = DPChange(M , c , d)
print(a)
i = M
print("Taken :")
while i != 0:
    print(i - par[i])
    i = par[i]
