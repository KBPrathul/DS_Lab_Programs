//q1-a    Polynomial addition using LL


#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node* next;
};

struct node* rec(int e, int c){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->coeff=c;
    new->exp=e;
    new->next=NULL;
    return new;
}

int main(){
    int n;
    printf("How many terms in polynomial 1? ");
    scanf("%d", &n);
    int coeff,exp;
    printf("Enter the exp & coeff: ");
    scanf("%d %d",&exp,&coeff);
    struct node* head1=rec(exp,coeff);
    struct node* temp1=head1;
    for(int i=1;i<n;i++){
        printf("Enter the exp & coeff: ");
        scanf("%d %d",&exp,&coeff);
        temp1->next=rec(exp, coeff);
        temp1=temp1->next;
    }
    temp1=head1;
    
    int m;
    printf("How many terms in polynomial 2? ");
    scanf("%d", &m);
    printf("Enter the exp & coeff: ");
    scanf("%d %d",&exp,&coeff);
    struct node* head2=rec(exp,coeff);
    struct node* temp2=head2;
    for(int i=1;i<m;i++){
        printf("Enter the exp & coeff: ");
        scanf("%d %d",&exp,&coeff);
        temp2->next=rec(exp, coeff);
        temp2=temp2->next;
    }
    temp2=head2;
    
    printf("\n");
    struct node* head3=NULL;
    struct node* temp3=NULL;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->exp==temp2->exp){
            if(head3==NULL){
                head3=rec(temp1->exp,temp1->coeff+temp2->coeff);
                temp3=head3;
            }
            else{
                temp3->next=rec(temp1->exp,temp1->coeff+temp2->coeff);
                temp3=temp3->next;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->exp>temp2->exp){
            if(head3==NULL){
                head3=rec(temp1->exp,temp1->coeff);
                temp3=head3;
            }
            else{
                temp3->next=rec(temp1->exp,temp1->coeff);
                temp3=temp3->next;
            }
            temp1=temp1->next;
        }
        else{
            if(head3==NULL){
                head3=rec(temp2->exp,temp2->coeff);
                temp3=head3;
            }
            else{
                temp3->next=rec(temp2->exp,temp2->coeff);
                temp3=temp3->next;
            }
            temp2=temp2->next;
        }
    }
    
    while(temp1!=NULL){
        if(head3==NULL){
            head3=rec(temp1->exp,temp1->coeff);
            temp3=head3;
        }
        else{
            temp3->next=rec(temp1->exp,temp1->coeff);
            temp3=temp3->next;
        }
        temp1=temp1->next;
    }
    
    while(temp2!=NULL){
        if(head3==NULL){
            head3=rec(temp2->exp,temp2->coeff);
            temp3=head3;
        }
        else{
            temp3->next=rec(temp2->exp,temp2->coeff);
            temp3=temp3->next;
        }
        temp2=temp2->next;
    }
    
    printf("Resultant polynomial: ");
    temp3=head3;
    while(temp3!=NULL){
        printf("%d %d    ",temp3->exp,temp3->coeff);
        temp3=temp3->next;
    }
    
    return 0;
}

/*How many terms in polynomial 1? 3
Enter the exp & coeff: 3 2
Enter the exp & coeff: 2 4
Enter the exp & coeff: 0 5
How many terms in polynomial 2? 2
Enter the exp & coeff: 2 3
Enter the exp & coeff: 1 1

Resultant polynomial: 3 2    2 7    1 1    0 5 */
