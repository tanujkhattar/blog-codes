typedef node* pnode;
int sz(pnode t){
  return t?t->size:0;
}
void upd_sz(pnode t){
  if(t)t->size=sz(t->l)+1+sz(t->r);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
  if(!t)return void(l=r=NULL);
  int curr_pos = add + sz(t->l);
  if(curr_pos<=pos)//element at pos goes to "l"
    split(t->r,t->r,r,pos,curr_pos+1),l=t;
  else	
		split(t->l,l,t->l,pos,add),r=t;
  upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r){ //l->leftarray,r->rightarray,t->resulting array
  if(!l || !r) t = l?l:r;
  else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
  else	merge(r->l,l,r->l),t=r;
  upd_sz(t);
}
