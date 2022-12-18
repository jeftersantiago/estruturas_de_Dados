from math import sqrt
from copy import deepcopy
INF=99999

class graph:

	def __init__(self,N):
		self.nodes=N
		self.edge_costs=[]
		for i in range(N):
			self.edge_costs.append([INF]*N)
		self.pos={}

	def addNode(self,x,y,i):
		self.pos[(x,y)]=i
		self.edge_costs[i][i]=0

	def addEdge(self,x1,y1,x2,y2):
		i1=self.pos[(x1,y1)]
		i2=self.pos[(x2,y2)]
		d=sqrt((x1-x2)**2+(y1-y2)**2)
		self.edge_costs[i1][i2]=d

	def getEdges(self):
		return self.edge_costs
	def getNodes(self):
		return self.nodes
	def getPos(self,i):
		return list(self.pos.keys())[i]

def floydwarshall(graph):
	V=graph.getNodes()
	dist=deepcopy(graph.getEdges())
	for k in range(V):
		for i in range(V):
			for j in range(V):
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
	return dist

if __name__=='__main__':

	N=int(input())
	citys = graph(N)
	for i in range(N):
		x,y=[int(j) for j in input().split(',')]
		citys.addNode(x,y,i)



	M=int(input())
	for i in range(M):
		edge=[int(j) for j in input().replace(':',',').split(',')]
		citys.addEdge(edge[0],edge[1],edge[2],edge[3])

	dists=floydwarshall(citys)

	max_dists=[]
	for i in dists:
		max_dists.append(max(i))

	biggest=0
	smallest=INF

	for i,j in enumerate(max_dists):
		if j>biggest:
			biggest=j
			big_index=i
		if j<smallest:
			smallest=j
			small_index=i

	a,b=citys.getPos(small_index)
	print(str(a)+','+str(b))
	a,b=citys.getPos(big_index)
	print(str(a)+','+str(b))

	biggest=0

	for i,j in enumerate(dists[big_index]):
		if j>biggest:
			biggest=j
			big2_index=i

	a,b=citys.getPos(big2_index)
	print(str(a)+','+str(b))
