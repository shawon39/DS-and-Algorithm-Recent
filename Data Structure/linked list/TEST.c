#include<stdio.h>
    struct node
    {
        int data;
        struct node *link;
    };

    void main()
    {
        int n,i;
        printf("TOTAL:\n");
        scanf("%d",&n);
        struct node *temp,*t;
        struct node *START=NULL;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("1st:\n");
        scanf("%d",&temp->data);
        temp->link=NULL;
        START=temp;
        for(i=2;i<=n;i++)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("%d no:\n",i);
            scanf("%d",&temp->data);
            temp->link=START;
            START=temp;
        }
        t=START;
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->link;
        }
    }

