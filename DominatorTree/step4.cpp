for(int i=2;i<=n;i++)
{
	if(dom[i]!=sdom[i])dom[i]=dom[dom[i]];
	tree[rev[i]].PB(rev[dom[i]]);
	tree[rev[dom[i]]].PB(rev[i]);
}
