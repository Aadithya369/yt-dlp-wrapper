#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  char link[1000];
  char command[2000];
  char file_name[200];
  snprintf(file_name, sizeof(file_name), "./links.txt");
  FILE *file = fopen(file_name, "r+");
  if (file == NULL) {
    perror("File cant be opened");
    return 1;
  }
  while ((fgets(link, sizeof(link), file))) {
    snprintf(command, sizeof(command), "yt-dlp -x %s -P /home/aadithya/Music/",
             link);
    system(command);
  }
  FILE *truncate_file = fopen(file_name, "w");
  fclose(truncate_file);
  fclose(file);
  return 0;
}
