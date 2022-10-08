#include <stdio.h>
#include<string.h>
#include <stdlib.h>


struct node{
    int revenue;
    int netIncome;
    struct node *next;
};

struct type1{
    int revenues;
    int netIncomes;
    int counter;
};

struct node* insertingEntry(struct node *head,int a,int b){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    temp=head;
    if(head==NULL){
        head->revenue=a;
        head->netIncome=b;
        head->next=NULL;
    }
    else{
        while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->revenue=a;
            newNode->netIncome=b;
            newNode->next=NULL;
    }
    return head;  
}

struct type1  calculatingTotal(struct node *head){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct type1 t1;
    temp=head;
    t1.counter=0;
    t1.netIncomes=0;
    t1.revenues=0;
    while(temp!=NULL){
        t1.revenues=t1.revenues+temp->revenue;
        t1.netIncomes=t1.netIncomes+temp->netIncome;
        temp=temp->next;
        t1.counter++;
    }

    return t1;
}

void showingAllDay(struct node *head){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int counter=1;
    while(temp->next!=NULL){
        temp=temp->next;
        printf("\n\n-------------------------------------\n");
        printf("For Day %d\n",counter);
        printf("-------------------------------------\n");
        printf("Your revenue was: %d\n",temp->revenue);
        printf("-------------------------------------\n");
        printf("Your net income was: %d\n\n",temp->netIncome);
        printf("-------------------------------------\n\n");
        counter++;
    }

}

void increseThanYesterday(struct node *head){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node *temp1=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL){
        temp1=temp->next;
        if(temp1->next==NULL){
            break;
        }
        temp=temp->next;
    }
    printf("\n\n------------------------------------------------------\n");
    printf("Comapring your rvevnues and net income with yesterday\n");
    printf("------------------------------------------------------\n");
    int revs=temp1->revenue-temp->revenue;
    int nets=temp1->netIncome-temp->netIncome;
    if(revs>0 && nets>0){
        printf("Your revenue is increased by: %d \n",revs);
        printf("------------------------------------------------------\n");
        printf("Your net income is incresed by: %d\n",nets);
        printf("------------------------------------------------------\n\n");
    }
    else if(revs>0 && nets<0){
        printf("Your revenue is increased by: %d \n",revs);
        printf("------------------------------------------------------\n");
        printf("Your net income is decreased by: %d\n",abs(nets));
        printf("------------------------------------------------------\n\n");
    }
    else if(revs<0 && nets<0){
        printf("Your revenue is decreased by: %d \n",abs(revs));
        printf("------------------------------------------------------\n");
        printf("Your net income is decreased by: %d\n",abs(nets));
        printf("------------------------------------------------------\n\n");
    }
    else if(revs<0 && nets>0){
        printf("Your revenue is decreased by: %d \n",abs(revs));
        printf("------------------------------------------------------\n");
        printf("Your net income is increased by: %d\n",abs(nets));
        printf("------------------------------------------------------\n\n");
    }
    
    
}

int main(){
    struct node *head;
    
    head=(struct node *)malloc(sizeof(struct node));
    

    int counter=1;
    while(1){
        printf("---------------------------------------------------------------------\n");
        printf("1. For adding your today's Revenue and Net Income\n");
        printf("---------------------------------------------------------------------\n");
        printf("2. To view your total revenue and total net income\n");
        printf("---------------------------------------------------------------------\n");
        printf("3. To see your all past Revenue and Net income of each day\n");
        printf("---------------------------------------------------------------------\n");
        printf("4. To see your growth in revenue and net income relative to yesterday\n");
        printf("---------------------------------------------------------------------\n");
        printf("5. To Exit\n");
        printf("---------------------------------------------------------------------\n");
        printf("Write a number to start the program:");
        int a;
        scanf("%d",&a);

        if(a==1){
            printf("Day %d\n\n",counter);
            printf("Write your today's Revevnue:");
            int rev;
            scanf("%d",&rev);
            printf("Write your today's Net Income(Profit(+ve)/loss(-ve)):");
            int net;
            scanf("%d",&net);
            head=insertingEntry(head,rev,net);
            counter++;
        }
        else if(a==2){
            struct type1 t2;
            t2=calculatingTotal(head);
            printf("\n\n---------------------------------------------------\n");
            printf("For last %d Days\n",t2.counter-1);
            printf("---------------------------------------------------\n");
            printf("Your total Revenue is: %d\n",t2.revenues);
            printf("---------------------------------------------------\n");
            printf("Your total Net Income is: %d\n",t2.netIncomes);
            printf("---------------------------------------------------\n");
            printf("And you have %0.2f%% profit margin\n",((float)t2.netIncomes/(float)t2.revenues)*100);
            printf("---------------------------------------------------\n\n");
        }
        else if(a==3){
            showingAllDay(head);
        }
        else if(a==4){
            increseThanYesterday(head);
        }
        else if(a==5){
            break;
        }
        
    }
    

    FILE *f;
    f=fopen("growth.py","a");
    fprintf(f,"import matplotlib.pyplot as plt\n");
    fprintf(f,"revList=[]\n");
    fprintf(f,"days=[]\n");
    struct node *newtemp=(struct node *)malloc(sizeof(struct node));
    newtemp=head;
    for (int i = 1; i <=counter; i++)
    {
        int a=newtemp->revenue;
        fprintf(f,"revList.append(%d)\n",a);
        fprintf(f,"days.append(%d)\n",i);
        newtemp=newtemp->next;
    }
    fprintf(f,"plt.plot(revList,days)\n");
    fprintf(f,"plt.xlabel('Revenue')\n");
    fprintf(f,"plt.ylabel('Days')\n");
    fprintf(f,"plt.title('Revenue vs Days')\n");
    fprintf(f,"plt.show()\n");

    fprintf(f,"netList=[]\n");
    newtemp=head;
    for (int i = 1; i <=counter; i++)
    {
        int a=newtemp->netIncome;
        fprintf(f,"netList.append(%d)\n",a);
        newtemp=newtemp->next;
    }
    fprintf(f,"plt.plot(netList,days)\n");
    fprintf(f,"plt.xlabel('Net Income')\n");
    fprintf(f,"plt.ylabel('Days')\n");
    fprintf(f,"plt.title('Net Income vs Days')\n");
    fprintf(f,"plt.show()\n");

}