//q1-a    Polynomial multiplication using LL

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

void insert(struct node* prev, int exp, int coeff){
    struct node* newnode=rec(exp,coeff);
    newnode->next=prev->next;
    prev->next=newnode;
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

    struct node* head3=NULL;
    struct node* temp3=NULL;
    temp1=head1;
    while(temp1!=NULL){
        temp2=head2;
        while(temp2!=NULL){
            int resultExp = temp1->exp + temp2->exp;
            int resultCoeff = temp1->coeff * temp2->coeff;
            
            if(head3==NULL){
                head3=rec(resultExp, resultCoeff);
                temp3=head3;
            }
            else{
                struct node* current = head3;
                struct node* prev = NULL;
                while(current != NULL && current->exp > resultExp){
                    prev = current;
                    current = current->next;
                }
                if(current != NULL && current->exp == resultExp){
                    current->coeff += resultCoeff;
                }
                else{
                    struct node* newNode = rec(resultExp, resultCoeff);
                    if(prev == NULL){
                        newNode->next = head3;
                        head3 = newNode;
                    }
                    else{
                        newNode->next = current;
                        prev->next = newNode;
                    }
                }
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    printf("Resultant polynomial: ");
    temp3=head3;
    while(temp3!=NULL){
        printf("%d %d    ",temp3->exp,temp3->coeff);
        temp3=temp3->next;
    }
    return 0;
}

/*How many terms in polynomial 1? 2
Enter the exp & coeff: 2 5
Enter the exp & coeff: 0 2
How many terms in polynomial 2? 2
Enter the exp & coeff: 1 3
Enter the exp & coeff: 0 1
Resultant polynomial: 3 15    2 5    1 6    0 2*/
