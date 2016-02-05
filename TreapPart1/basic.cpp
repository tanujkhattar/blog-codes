typedef struct node{
	int val,prior,size;
	struct node *l,*r;
}node;
typedef node* pnode;
int sz(pnode t){
	return t?t->size:0;
}
void upd_sz(pnode t){
	if(t)t->size = sz(t->l)+1+sz(t->r);
}
void split(pnode t,pnode &l,pnode &r,int key){
	if(!t)l=r=NULL;
	else if(t->val<=key)split(t->r,t->r,r,key),l=t;//elem=key comes in l
	else split(t->l,l,t->l,key),r=t;
	upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r){
	if(!l || !r)t=l?l:r;
	else if(l->prior > r->prior)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_sz(t);
}
