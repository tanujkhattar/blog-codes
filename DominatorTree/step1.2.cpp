void dfs0(int u)
{
	T++;arr[u]=T;rev[T]=u;
	label[T]=T;sdom[T]=T;dsu[T]=T;
	for(int i=0;i<SZ(g[u]);i++)
	{
		int w = g[u][i];
		if(!arr[w])
		{
			dfs0(w);
			par[arr[w]]=arr[u];
		}
		rg[arr[w]].PB(arr[u]);
	}
}
