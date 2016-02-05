for(int i=n;i>=1;i--)
{
	for(int j=0;j<SZ(rg[i]);j++)
		sdom[i] = min(sdom[i],sdom[Find(rg[i][j])]);
	if(i>1)bucket[sdom[i]].PB(i);
	for(int j=0;j<SZ(bucket[i]);j++)
	{
		int w = bucket[i][j],v = Find(w);
		if(sdom[v]==sdom[w]) dom[w]=sdom[w];
		else dom[w] = v;
	}
	if(i>1)Union(par[i],i);
}
