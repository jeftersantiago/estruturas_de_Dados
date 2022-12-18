from braba_log import graph,floydwarshall,INF

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