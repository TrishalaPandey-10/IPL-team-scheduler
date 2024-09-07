#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
 char name[50];
} Team;
typedef struct {
 char team1[50];
 char team2[50];
 char date[20];
} Match;
int main() {
 int num_teams;
 printf("Enter the number of teams: ");
 scanf("%d", &num_teams);
 Team teams[20];
 printf("Enter team names:\n");
 for (int i = 0; i < num_teams; i++) {
 printf("Team %d: ", i+1);

scanf("%s", teams[i].name); 
}
 int num_matches = num_teams * (num_teams - 1) / 2;
 Match matches[num_matches];
 int count = 0;
 printf("Enter match dates:\n");
 for (int i = 0; i < num_teams; i++) {
 
 for (int j = i+1; j < num_teams; j++) {
 printf("%s vs %s (DD/MM/YYYY): ", teams[i].name, teams[j].name);
 scanf("%s", matches[count].date);
 strcpy(matches[count].team1, teams[i].name);
 strcpy(matches[count].team2, teams[j].name);
 count++;
 }
 }
 printf("\nMatch Schedule:\n");
 printf("Date\t\tTeam 1\t\tTeam 2\n");
 for (int i = 0; i < num_matches; i++) {
 printf("%s\t%s\t\t%s\n", matches[i].date, matches[i].team1, matches[i].team2);
 }
 

 FILE *fp;
fp = fopen("schedule.txt", "w");
fprintf(fp, "Match Schedule:\n");
 fprintf(fp, "Date\t\tTeam 1\t\tTeam 2\n");
 for (int i = 0; i < num_matches; i++) {
fprintf(fp, "%s\t%s\t\t%s\n", matches[i].date, matches[i].team1, matches[i].team2);
 }
 fclose(fp);
 printf("Match schedule saved to schedule.txt.\n");
 return 0;
}

