void insert(pnode &t,pnode it){
	if(!t) t=it;
	else if(it->prior>t->prior)split(t,it->l,it->r,it->val),t=it;
	else insert(t->val<=it->val?t->r:t->l,it);
	upd_sz(t);
}
void erase(pnode &t,int key){
	if(!t)return;
	else if(t->val==key){pnode temp=t;merge(t,t->l,t->r);free(temp);}
	else erase(t->val<key?t->r:t->l,key);
	upd_sz(t);
}
void unite (pnode &t,pnode l, pnode r) {
	if (!l || !r) return void(t = l ? l : r);
	if (l->prior < r->prior) swap (l, r);
	pnode lt, rt;
	split (r,lt, rt,l->val);
	unite (l->l,l->l, lt);
	unite (l->r,l->r, rt);
	t=l;upd_sz(t);
}
pnode init(int val){
	pnode ret = (pnode)malloc(sizeof(node));
	ret->val=val;ret->size=1;ret->prior=rand();ret->l=ret->r=NULL;
	return ret;
}
