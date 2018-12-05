#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//the structe
struct music{
    char name[20];
    int id;
    struct music *lpoint;
    struct music *rpoint;
};
typedef struct  music music;
void add_music(struct music **start,struct music **end){
    printf("Enter the name of the music ");
    music *m1=(struct music *)malloc(sizeof(music));
    scanf("%s",m1->name);
    m1->id=rand()%1000+1;
    
    fflush(stdin);
    if(*start==NULL){
        *start=m1;
        *end = *start;
        m1->rpoint=m1;
        m1->lpoint=m1;
        }
    else{
        m1->lpoint=*end;
        (*end)->rpoint=m1;
        (*start)->lpoint=m1;
        m1->rpoint=*start;
        *end= m1;
    }
//    struct music *temp= (struct music *)malloc(sizeof(music));
//    temp=*start;
//    while(temp!=*end){
//        printf("%s \t",temp->name);
//        temp = temp->rpoint;
//    }
}
void delete_music(struct music **start,struct music **end){
    
    if(*start==NULL){
        printf("\n\tempty list");
        return;
    }
    else{
        printf("Enter the name of the music to delete?\n");
        struct music *var=NULL;
        scanf("%s",var->name);
        fflush(stdin);
        if(*start==*end && (*start)->name==var->name){
            *start=NULL;
            *end=NULL;
            return;
        }
        else{
            struct music *temp=(struct music *)malloc(sizeof(music));
            temp=*start;
          do{
              if(temp->name==var->name){
                  music *ptr=temp;
                  temp->lpoint->rpoint=temp->rpoint;
                  temp->rpoint->lpoint= temp->lpoint;
                  temp=temp->rpoint;
                  free(ptr);
                  printf("you are deleted 1 item");
                  return;
                  
              }
              temp=temp->rpoint;
          } while(temp != (*end)->rpoint);
            printf("The name you selected is not found");
        }
        
    }
}
 void display_music(struct music **start,struct music **end){
     if(*start==*end){
         printf("Music play list:\tID \t Name\n \t\t\t %d\t %s \n",(*start)->id,(*start)->name);
     }
     else{
         struct music *temp=(struct music *)malloc(sizeof(music));
            temp=*start;
         printf("Music play list:\tID \t Name\n");
          do{
               printf("\t\t\t %d\t %s \n",temp->id,temp->name);
          
              temp=temp->rpoint;
          } while(temp != (*end)->rpoint);
     }
 
     
 }
void play_music(struct music **start){
    struct music *temp;
    temp=*start;
    char c;
    printf("\n\n\n\n \t\t\t\t....................now Playing..................\n");
    printf("\n\t\t\t\t..... %s.........\n",temp->name);
    while(1){
  //      clrscr();
        printf("\npress ..... <<=1 \t\t\t\t2=>> \t\t\t c to 'cancel'");
        scanf("%c",&c);
        switch(c){
            case '1':
                {
                    temp=temp->lpoint;
                printf("\n\n\n\n \t\t\t\t....................now Playing..................\n");
                printf("\n\t\t\t\t..... %s.........\n",temp->name); 
                }
                break;
            case '2':
                 {
                temp=temp->rpoint;
                printf("\n\n\n\n \t\t\t\t....................now Playing..................\n");
                printf("\n\t\t\t\t..... %s.........\n",temp->name); 
                }
                break;
            case 'c':
                return;
                break;
        }
    }
}
int main(){
    
    struct music *start=(struct music *)malloc(sizeof(music));
    struct music *end = (struct music *)malloc(sizeof(music));
    end= start=NULL;
        char c;
    while(1){
         printf("Choose one of the following\n");
        printf("1) ADD NEW MUSIC\n");
        printf("2) REMOVE MUSIC FROM LIST\n");
        printf("3) DISPLAY ALL MUSIC FROM LIST\n");
        printf("4) PLAY ALL\n");
        printf("5) CLOSE\n");
        
        
       scanf("%c",&c);
        
        
        
        fflush(stdin);
        switch(c){
            case '1':
                add_music(&start,&end);
                break;
            case '2':
                delete_music(&start,&end);
                break;
            case '3':
                display_music(&start,&end);
                break;
            case '4':
                play_music(&start);
                break;
            case '5':
                exit(0);
        }
        
    }
}
