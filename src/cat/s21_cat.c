// Copyright (c) 2022 Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See License file in the project root for
// license information.
//  Created by greengrb on 05.11.2022.
//

#include "./files.h"

int main(int argc, char* argv[]) { cat(argc, argv); }
int cat(int argc, char* argv[]) {
  int number_noblank = 0, number = 0, show_tabs = 0, show_endlines = 0,
      squeeze = 0, show_tabs_out_v = 0, show_endlines_out_v = 0,
      invisible_characters = 0;

  int flag_ret = 1;

  const char* short_options = "+benstvET";
  const struct option long_options[] = {
      {"number-nonblank", 0, NULL, 'b'},
      {"number", 0, NULL, 'n'},
      {"squeeze-blank", 0, NULL, 's'},
      {NULL, 0, NULL, 0},
  };
  int flag = 0;
  while ((flag = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (flag) {
      case 'b': {
        number_noblank = 1;
        number = 0;
        break;
      }
      case 'e': {
        show_endlines = 1;
        break;
      }
      case 'n': {
        if (number_noblank == 1) {
          number = 0;
        } else {
          number = 1;
        }
        break;
      }
      case 's': {
        squeeze = 1;
        break;
      }
      case 't': {
        show_tabs = 1;
        break;
      }
      case 'E': {
        show_endlines_out_v = 1;
        break;
      }
      case 'T': {
        show_tabs_out_v = 1;
        break;
      }
      case 'v': {
        invisible_characters = 1;
        break;
      }
      case '?': {
        fprintf(stderr, "usage: cat [-benstv] [file ...]\n");
        flag_ret = 0;
      }
    }
  }
  if (flag_ret == 1) {
    FILE* fin;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        fin = fopen(argv[i], "r");
        if (fin == NULL) {
          fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
        } else {
          fseek(fin, 0, SEEK_END);
          long size = ftell(fin);
          fseek(fin, 0, SEEK_SET);
          char* infa_masiv = (char*)malloc(size);
          char simvol_masiva;
          int flag_combo_etv = 0;
          int counter = 1;
          int line_count = 1;
          int j = 0;
          while (fscanf(fin, "%c", &simvol_masiva) != EOF) {
            counter = 1;
            if (squeeze == 1 && j > 1 && infa_masiv[j - 2] == '\n' &&
                infa_masiv[j - 1] == '\n' && simvol_masiva == '\n') {
              counter = 0;
            }  // s
            if (number == 1 && j == 0) {
              printf("%6d\t", line_count);
              line_count++;
            } else if ((number == 1 && j != 0 && infa_masiv[j - 1] == '\n') &&
                       counter == 1) {
              printf("%6d\t", line_count);
              line_count++;
            }  // n
            if (simvol_masiva != '\n' && j == 0 && number_noblank == 1) {
              printf("%6d\t", line_count);
              line_count++;
            } else if (j != 0 && infa_masiv[j - 1] == '\n' &&
                       simvol_masiva != '\n' && number_noblank == 1) {
              printf("%6d\t", line_count);
              line_count++;
            }  // b
            if (invisible_characters == 1 && counter == 1) {
              symbol(&simvol_masiva, &counter, &flag_combo_etv);
            }  // -v
            if (show_tabs == 1 && counter == 1) {
              if ((simvol_masiva >= 0) && (simvol_masiva <= 31) &&
                  (simvol_masiva != 10) && (simvol_masiva != 9) &&
                  flag_combo_etv == 0) {
                printf("^%c", simvol_masiva + 64);
                counter = 0;
                flag_combo_etv = 1;
              } else if (simvol_masiva == 127 && flag_combo_etv == 0) {
                printf("^?");
                counter = 0;
                flag_combo_etv = 1;
              } else if (simvol_masiva == '\t') {
                printf("^I");
                counter = 0;
              }  // -t
            }    // -t ++v
            if (show_tabs_out_v == 1 && simvol_masiva == '\t') {
              printf("^I");
              counter = 0;
            }  // T --v
            if (show_endlines == 1) {
              if (simvol_masiva == '\n' && counter == 1) {
                printf("$");
              }
              if (flag_combo_etv == 0) {
                symbol(&simvol_masiva, &counter, &flag_combo_etv);
              }
            }  // -e ++v
            if ((show_endlines_out_v == 1) && (simvol_masiva == 10)) {
              printf("$");
            }  // -E

            if (counter == 1) {
              printf("%c", simvol_masiva);
            }
            infa_masiv[j] = simvol_masiva;
            j++;
            flag_combo_etv = 0;
          }
          free(infa_masiv);
          fclose(fin);
        }
      }
    }
  }
  return flag_ret;
}
void symbol(const char* simvol_masiva, int* counter, int* flag_combo_etv) {
  if ((*simvol_masiva >= 0) && (*simvol_masiva <= 31) &&
      (*simvol_masiva != 10) && (*simvol_masiva != 9)) {
    printf("^%c", *simvol_masiva + 64);
    *counter = 0;
    *flag_combo_etv = 1;
  } else if (*simvol_masiva == 127) {
    printf("^?");
    *counter = 0;
    *flag_combo_etv = 1;
  }
}
