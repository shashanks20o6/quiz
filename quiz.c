#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void remove_newline(char *str) {     //we are using * because we have to modify the original array not the copy of the array
    str[strcspn(str, "\n")] = '\0';  // Remove newline character "\n" and replace it by '/0'if it exists
}

int main()
{
    char ans[256],uans[256];
    float score=0;
    FILE *ptr = fopen("quiz1.txt","r");
    char ch[256];
   
  for(int k=0;k<5;k++)              //there are 5 questions in the file 
  {            
    for(int i=0;i<7;i++){           //there are 7 lines alloted to each line 
        if(fgets(ch,sizeof(ch), ptr)!=NULL)
        {
            if (i==5)
            {              //at line 5 of each question the ans is written
                strcpy(ans,ch);     //this copies the answer to the ans string 
            remove_newline(ans);    //this remover new line from ans
                continue;           //ths skips printing the answer
            }
            else 
            printf("%s",ch);
         }
        }
         
        scanf("%s",&uans);          //this takes user input or answere of user 
        if (strcmp(uans,ans)==0)
        {
            printf("correct answer\n");
            score= score+1; 
        }
        else 
        printf("wrong\n");
 }
   float per = ((score)/5)*100;
   printf("your percentage is  %f",per);
   
  
  fclose(ptr);
  return 0;
}