from random import randrange
i = 0
tableau = []
print("./push_swap",end='')
while i < 100:
	a = randrange(1, 300)
	if a not in tableau:
		tableau.append(a)
		i+=1
i = 0
while i < 100:
	print(tableau[i]," ",end='')
	i+=1
print("| wc")
