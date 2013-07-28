#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

char *path_cat (const char *str1, char *str2);

int main () {
	struct dirent *dp;

        // enter existing path to directory below
	const char *dir_path="testing/";
	DIR *dir = opendir(dir_path);
	while ((dp=readdir(dir)) != NULL) {
		char *tmp;
		tmp = path_cat(dir_path, dp->d_name);
		printf("%s\n", tmp);
		free(tmp);
		tmp=NULL;
	}
	closedir(dir);
	return 0;
}

char *path_cat (const char *str1, char *str2) {
	size_t str1_len = strlen(str1);
	size_t str2_len = strlen(str2);
	char *result;
	result = (char*)malloc((str1_len+str2_len+1)*sizeof(char));
	strcpy (result,str1);
	int i,j;
	for(i=str1_len, j=0; ((i<(str1_len+str2_len)) && (j<str2_len));i++, j++) {
		result[i]=str2[j];
	}
	result[str1_len+str2_len]='\0';
	return result;
}
