#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fname "filename.txt"

//
// mygrep.c
//
// 日経Linux 2006年3月号 88ページ
//
// filename.txt の作り方
// find ./ -name "*.c" > filename.txt
//
// 1行に複数の検索文字列がある場合、同一行が複数回見つかる。

int main(int argc, char *argv[])
{
	FILE *fp, *fin;
	char line[4096], src[1024];
	int len, flen, slen, i, lineNumber, flag;

	if (argc != 2) { // 引数が2個以外なら
		printf ("Usage %s string\n", argv[0]);
		exit(1);
	}
	flen = strlen(argv[1]);
	fp = fopen(fname, "r");
	if (!fp) {
		printf ("Please make %s\n", fname);
		exit(1);
	}

	while(fgets(line, 4096, fp)){
		len = strlen(line);
		line[len - 1] = '\0';
		fin = fopen(line, "r");
		if (!fin) {
			printf ("no input file: %s\n", line);
			exit(1);
		}
		lineNumber = 1;
		flag = 0;
		while(fgets(src, 1024, fin)){
			src[strlen(src) - 1] = '\0';
			slen = strlen(src);
			for (i = 0; i < slen; i++) {
				if (!strncmp(&src[i], argv[1], flen)) {
					if (flag == 0) {
						puts(line);
						flag = 1;
					}
					printf ("%5d:%s\n", lineNumber, src);
				}
			}
			lineNumber++;
		}
		fclose(fin);
	}
	fclose(fp);
}
