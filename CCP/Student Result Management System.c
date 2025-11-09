#include<stdio.h>
char getgrade(float percentage){
if (percentage >= 80)
return 'A';
else if (percentage >= 70)
return 'B';
else if (percentage >= 60)
return 'C';
else if (percentage >=50)
return 'D';
else
return 'F';
}

int main(){
char name[50];
int subjects,i;

printf ("Enter Student Name:");
scanf("%[^\n]", name);

printf ("Enter the number of Subjects:");
scanf("%d",&subjects);

char subName[subjects][20];
float marks[subjects];
float totalmarks=100;
float obtainedtotalmarks=0;

for(i=0;i< subjects;i++){
    printf("Enter Name of Subject %d:",i+1);
    scanf("%s", &subName[i]);

    printf("Enter Marks in %s(out of 100):",subName[i]);
    scanf("%f",&marks[i]);

    obtainedtotalmarks+=marks[i];
}
printf("\n========STUDENT RESULT=========\n");
printf("Student Name:'%s'\n",name);
printf("-----------------------------------\n");
printf("Subject\t\tMarks\tPercentage\tGrade\n");

for (i=0;i< subjects;i++){
    float percent=(marks[i]/totalmarks)*100;
    char grade=getgrade(percent);

    printf("%-10s\t%.2f\t%.2f%%\t\t%c\n",subName[i],marks[i],percent,grade);
}
float totalsubMarks= subjects*totalmarks;
float overallpercentage= (obtainedtotalmarks/totalsubMarks)*100;
char overallgrade= getgrade(overallpercentage);

printf("-----------------------------------\n");
printf("Total obtained marks:%.2f\n",obtainedtotalmarks);
printf("Total subject marks:%.2f\n",totalsubMarks);
printf("overall percentage:%.2f%%\n",overallpercentage);
printf("overall grade:'%c'\n",overallgrade);
printf("-----------------------------------\n");

return 0;
}
