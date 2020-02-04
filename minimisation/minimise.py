import csv

class inter:
	def __init__(self, a = 0):
		self.core = ''.join(reversed(bin(a)[2:]))

	def appendS(self, other):
		self.core = self.core + other

	def __add__(self, other):
		m = min([len(self.core), len(other.core)])
		new = inter()
		new.core = str()

		for i in range(m):
			if self.core[i]	== other.core[i]:
				new.appendS(self.core[i])
			else:
				new.appendS('-')

		for i in range(m):
			print(self.core[i])
		for i in range(m):
			print(other.core[i])
		diff = max([len(self.core), len(other.core)]) - m
		if diff != 0:
			new.appendS(max([self.core, other.core], key = lambda k: len(k))[m:])
		return new

	def __str__(self):
		return self.core

	def __repr__(self):
		return self.core

	def oneDiff(self):
		return (self.core.count("-") == 1)

state=2
ins=1

ones = []
dontcare = []

with open('data.csv') as csv_file:
	csv_reader = csv.reader(csv_file, delimiter=',')
	line_count = 0
	for row in csv_reader:
		num = 0
		for i in range(state + ins):
			if row[i] == '1':
				num += 2**i

		if row[state + ins] == '1':
			ones.append(num)		
		
		if row[state + ins] == '2':
			dontcare.append(num)

table_aggr = {}
for one in ones:
	if bin(one).count("1") in table_aggr.keys():
		table_aggr[bin(one).count("1")].append(inter(one))
	else:
		table_aggr[bin(one).count("1")] = [inter(one)]
print(table_aggr)
