

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */ 
    Node*merge(Node*a,Node*b){
        Node*d = new Node(0) ; 
        Node*r = d ; 
        
        while(a && b){
            if(a->data < b->data){
                d->bottom=a;
                d=d->bottom;
                a=a->bottom;
            }
            else{
                d->bottom=b;
                d=d->bottom;
                b=b->bottom;
            }
        }
        if(!a) d->bottom=b;
        if(!b) d->bottom=a;
        
        return r->bottom;
    }
Node *flatten(Node *root)
{
    Node*h1 = root , *h2 = h1->next ; 
    while(h2){
        h1=merge(h1,h2) ; 
        h2=h2->next;
    }
    return h1;
}
