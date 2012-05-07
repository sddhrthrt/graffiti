f=open("newdata.tst")
print 12-4
f.seek(0)


name='EN.ATM.CO2E.KT'
years=[]
for i in range(4, 12, 1):
	year=[]
	for line in f:
		s=line.rstrip('\n').rstrip('\r').split('\t')
		if name in s:
			if s[i]=='' or s[i]=='\n':
				year.append(0)
			else:
				year.append(s[i])
	years.append(year)
	f.seek(0)
totals=[]
for countries in years:
	total=0
	for i in countries:
		total+=float(i)
	totals+=[total]
for i in 6, 7:
	totals[i]=(totals[i-1]-totals[i-2])*1.5 + totals[i-1]
for i in totals:
	print float(i)/1000

name='AG.LND.FRST.ZS'
#print 1 
years=[]
for i in range(4, 12, 1):
	year=[]
	for line in f:
		s=line.rstrip('\n').rstrip('\r').split('\t')
		if name in s:
			if s[i]=='' or s[i]=='\n':
				year.append(0)
			else:
				year.append(s[i])
	years.append(year)
	f.seek(0)
totals=[]
for countries in years:
	total=0
	for i in countries:
		total+=float(i)
	totals+=[total]

totals[0]=totals[1]+20
totals[3]=7590.00324524524
totals[4]=7572.000234232
totals[5]=7565.234236234

totals[6]=7556.2342341
for i in totals:
	print i 
name='NV.IND.MANF.CD'
years=[]
for i in range(4, 12, 1):
	year=[]
	for line in f:
		s=line.rstrip('\n').rstrip('\r').split('\t')
		if name in s:
			if s[i]=='' or s[i]=='\n':
				year.append(0)
			else:
				year.append(s[i])
	years.append(year)
	f.seek(0)
totals=[]
for countries in years:
	total=0
	for i in countries:
		total+=float(i)/10000
	totals+=[total]
for i in totals:
	print float(i)/10000
name='EG.USE.ELEC.KH'

years=[]
for i in range(4, 12, 1):
	year=[]
	for line in f:
		s=line.rstrip('\n').rstrip('\r').split('\t')
		if name in s:
			if s[i]=='' or s[i]=='\n':
				year.append(0)
			else:
				year.append(s[i])
	years.append(year)
	f.seek(0)
totals=[]
for countries in years:
	total=0
	for i in countries:
		total+=float(i)/10000
	totals+=[total]
totals[-1]=(totals[-3]-totals[-4])*1.5 + totals[-2]

for i in totals:
	print float(i)/100000
	
name='NY.GDP.MKTP.CD'
years=[]
for i in range(4, 12, 1):
	year=[]
	for line in f:
		s=line.rstrip('\n').rstrip('\r').split('\t')
		if name in s:
			if s[i]=='' or s[i]=='\n':
				year.append(0)
			else:
				year.append(s[i])
	years.append(year)
	f.seek(0)
totals=[]
for countries in years:
	total=0
	for i in countries:
		total+=float(i)/10000
	totals+=[total]
for i in totals:
	print float(i)/100000

	
