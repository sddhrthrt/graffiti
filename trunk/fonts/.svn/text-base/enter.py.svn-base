def enterCoords(i):
	fil=open('.'.join([i, 'disp']),'w')
	print 'Letter '+str(i)+':'
	line=[]
	no=int(raw_input('Number of Points? '))
	line.append(str(no))
	for i in range(1, no+1):
		print str(i)+': '
		f=raw_input('X: ')
		line.append(str(float(f)/24))
		f=raw_input('Y: ')
		line.append(str(float(f)/24))
	no=int(raw_input('Number of Lines? '))
	line.append(str(no))
	for i in range(1, no+1):
		print str(i)+': '
		f=raw_input('X0: ')
		line.append(str(float(f)/24))
		f=raw_input('Y0: ')
		line.append(str(float(f)/24))
		f=raw_input('X1: ')
		line.append(str(float(f)/24))
		f=raw_input('Y1: ')
		line.append(str(float(f)/24))

	no=int(raw_input('Number of SemiCircles? '))
	line.append(str(no))
	for i in range(1,no+1):
		print str(i)+': '
		f=raw_input('X: ')
		line.append(str(float(f)/24))
		f=raw_input('Y: ')
		line.append(str(float(f)/24))
		f=raw_input('Radius: ')
		line.append(f)
		f=raw_input('Orintation: N-0, E-1, W-2, S-3: ')
		line.append(f)
	no=raw_input('Width? ')
	line.append(str(float(no)/24))
	l=' '.join(line)
	fil.writelines([l])


		
print "Enter all the values assuming the denominator is 24 :)"

letters= ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3','4', '5', '6', '7', '8', '9']
ch=int(raw_input('Continue from? '))
for i in letters[ch:]:
	enterCoords(i)	
	ch=int(raw_input('Stop?(0) Skip?(1) '))
	if(ch==0):
		break
	if(ch==1):
		continue
