#include<stdio.h>
#include<stdlib.h>
struct Tree{
  int data;
  struct Tree*left,*right;
};
struct Stack{
  struct Tree*link;
  struct Stack*next;
};
struct Queue{
  struct Tree*link;
  struct Queue*next;
};
struct Tree*create_node(int value);
struct Tree* free_node(struct Tree*);
void pop(struct Stack**);
void push(struct Tree*,struct Stack**);
void reverse_level(struct Tree*);
void dequeue(struct Queue**);
struct Queue* enqueue(struct Tree*);
struct Tree*create_node(int value){
  struct Tree*new_node=(struct Tree*)malloc(sizeof(struct Tree));
  if(new_node!=NULL){
    new_node->data=value;
    new_node->left=new_node->right=NULL;
    return new_node;
  }else{
    printf("\n Memory overflow.");
    return NULL;
  }  
}
void inorder_data(struct Tree*temp){
 if(temp){
  inorder_data(temp->left);
  printf("  %d",temp->data);
  inorder_data(temp->right);
}else
return;
}
void dequeue(struct Queue**head){
  struct Queue*remove=*head;
  if(remove!=NULL){
    remove->link=NULL;
    *head=remove->next;
    remove->next=NULL;
    free(remove);
    remove=NULL;
  }
}
struct Queue* enqueue(struct Tree*temp){
  struct Queue*new_node=(struct Queue*)malloc(sizeof(struct Queue));
  if(new_node){
    new_node->link=temp;
    new_node->next=NULL;
    return new_node;
  }
  else{
    printf("\n Queue overflow");
    return NULL;
  }
}
void reverse_level(struct Tree*temp){
  if(temp==NULL){
    printf("\n Empty Tree");
    return;
  }
  struct Stack*top=NULL,*helper=NULL;
  struct Queue*head=NULL,*tail=NULL,*auxiliary;
  head=tail=enqueue(temp);
  while(head!=NULL){
    auxiliary=head;
    if(auxiliary && auxiliary->link->left !=NULL){
      tail->next=enqueue(auxiliary->link->left);
      tail=tail->next;
    }
    if(auxiliary && auxiliary->link->right !=NULL){
      tail->next=enqueue(auxiliary->link->right);
      tail=tail->next;
    }
    if(auxiliary){
      push(auxiliary->link,&top);
      auxiliary=NULL;
      dequeue(&head);
    }
  }
  printf("\n Reverse level order traversal : ");
  while(top!=NULL){
    printf(" %d",top->link->data);
    pop(&top);
  }
}
void push(struct Tree*node,struct Stack**top){
  struct Stack*new_node=(struct Stack*)malloc(sizeof(struct Stack));
  if(new_node!=NULL){
    new_node->link=node;
    new_node->next=*top;
    *top=new_node;
  }else{
    printf("\n Memory overflow.");
    return ;
  }
}
void pop(struct Stack**top){
  if(*top!=NULL){
    struct Stack*remove=*top;
    *top=(*top)->next;
    remove->link=NULL;
    remove->next=NULL;
    free(remove);
    remove=NULL;
  }
}
struct Tree* free_node(struct Tree*temp){
 if(temp){
  temp->left=free_node((temp->left));
  temp->right=free_node(temp->right);
  free(temp);
  temp=NULL;
return NULL;
 }
}

int main(){
  struct Tree*root=NULL;
  root                      = create_node(1);
  root->left                = create_node(2);
  root->right               = create_node(3);
  root->left->left          = create_node(4);
  root->left->right         = create_node(5);
  root->right->right        = create_node(6);
  root->left->right->left   = create_node(7);
  root->right->right->right = create_node(8);
  reverse_level(root);
  free_node(root);
  return 0;
}