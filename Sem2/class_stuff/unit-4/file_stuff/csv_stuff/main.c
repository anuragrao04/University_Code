//  Given a CSV File, Perform the following operations:
//  - Count the number of matches played in 2008
//  - Count the number of matches played in each year
//  - Count the number of times that the toss_winner is the same as winner
//  - Display the number of matches played between KKR and RCB
//  - Display the winner of each match played in 2016
//  - Display the list of *players-of-the-match* when there was a match between
//  RCB and CSK in the year 2010
//
//  The output of all the above should be written to an output file
//  Here's the link to the csv file
//  https://drive.google.com/drive/folders/1dqVOi0WaUXtgHxYqylR5gxjW8RNmVs-z

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  FILE *csv_file = fopen("matches.csv", "r");
  int count_matches_2008 = 0;
  int count_toss_win_same_win = 0;
  int count_kkr_vs_rcb = 0;
  char winners_2016[64][64];
  int winners_2016_i = 0;
  char players_of_match[64][64];
  int players_of_match_i = 0;
  char line[1024];
  while ((fgets(line, 512, csv_file)) != NULL) {
    strtok(line, ","); // sl no
    char *year = strtok(NULL, ",");
    strtok(NULL, ","); // city
    strtok(NULL, ","); // date
    char *team1 = strtok(NULL, ",");
    char *team2 = strtok(NULL, ",");
    char *toss_winner = strtok(NULL, ",");
    strtok(NULL, ","); // toss decision
    strtok(NULL, ","); // result
    strtok(NULL, ","); // dl applied
    char *winner = strtok(NULL, ",");
    strtok(NULL, ","); // win by runs
    strtok(NULL, ","); // win by wickets
    char *player_of_match = strtok(NULL, ",");

    if (!strcmp(year, "2008")) {
      count_matches_2008++;
    }

    if (!strcmp(toss_winner, winner)) {
      count_toss_win_same_win++;
    }

    int t1rcb_t2kkr = !strcmp(team1, "Royal Challengers Bangalore") &&
                      !strcmp(team2, "Kolkata Knight Riders");
    int t1kkr_t2rcb = !strcmp(team1, "Kolkata Knight Riders") &&
                      !strcmp(team2, "Royal Challengers Bangalore");

    if (t1kkr_t2rcb || t1rcb_t2kkr) {
      count_kkr_vs_rcb++;
    }

    if (!strcmp(year, "2016")) {
      strcpy(winners_2016[winners_2016_i], winner);
      winners_2016_i++;
    }

    if (!strcmp(year, "2010")) {
      int t1rcb_t2csk = !strcmp(team1, "Royal Challengers Bangalore") &&
                        !strcmp(team2, "Chennai Super Kings");
      int t1csk_t2rcb = !strcmp(team1, "Chennai Super Kings") &&
                        !strcmp(team2, "Royal Challengers Bangalore");

      if (t1rcb_t2csk || t1csk_t2rcb) {
        strcpy(players_of_match[players_of_match_i], player_of_match);
        players_of_match_i++;
      }
    }
  }
  fclose(csv_file);

  FILE *output_file = fopen("output.txt", "w");
  fprintf(output_file, "Number of matches in 2008: %d\n", count_matches_2008);
  fprintf(output_file, "Number of times toss_winner same as winner: %d\n",
          count_toss_win_same_win);
  fprintf(output_file, "Number of matches between KKR and RCB: %d\n",
          count_kkr_vs_rcb);
  fprintf(output_file, "\n\n%d winners of every match played in 2016: \n",
          winners_2016_i);

  for (int i = 0; i < winners_2016_i; i++) {
    fprintf(output_file, "%s\n", winners_2016[i]);
  }

  fprintf(output_file, "\n\n\n");

  fprintf(
      output_file,
      "\n\n%d players Of Match for every match between RCB and CSK in 2010: \n",
      players_of_match_i);

  for (int i = 0; i < players_of_match_i; i++) {
    fprintf(output_file, "%s\n", players_of_match[i]);
  }

  fclose(output_file);
  return EXIT_SUCCESS;
}
