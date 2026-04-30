#include <ctype.h>
#include <dirent.h>
#include <stdio.h>

// Remember:
// (*entry).d_name == entry->d_name

//---------------------------

int is_numeric(const char *str); // Function declaration used by main.

//---------------------------

int main(void) {
  DIR *dir;

  struct dirent
      *entry; // a pointer to one directory entry returned by `readdir()`

  dir = opendir("/proc"); // Open the `/proc` directory
  if (dir == NULL)
    return 1;

  //-------------
  while ((entry = readdir(dir)) != NULL) {
    if (is_numeric(entry->d_name)) {
      printf("%s\n", entry->d_name);
    }
  }
  // read all files/folders and when don't have anything to read, return `NULL`.
  //-------------

  closedir(dir);
  return 0;
}

//---------------------------

int is_numeric(const char *str) {
  int i = 0;

  while (str[i] != '\0') {
    if (!isdigit(str[i])) {
      return 0;
    }
    i++;
  }
  return 1;
}
