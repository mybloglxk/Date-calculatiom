#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void math_begin(char *buf)
{
	//first=100&second=200
	//strtok();
	int x, y;
	sscanf(buf, "a=%d&b=%d", &x, &y);

	printf("<html>\n");
	printf("<h3>%d + %d = %d</h3><br>\n", x, y, x+y);
	printf("<h3>%d - %d = %d</h3><br>\n", x, y, x-y);
	printf("<h3>%d * %d = %d</h3><br>\n", x, y, x*y);
	if(y == 0){
		printf("%d / %d = error<div zero>\n", x, y);
	}else{
		printf("<h3>%d / %d = %d</h3><br>\n", x, y, x/y);
	}
	printf("</html>\n");
}

int main()
{
	char method[64];
	char buf[1024];
	int content_length = -1;
	if(getenv("METHOD")){
		strcpy(method, getenv("METHOD"));
		if(strcasecmp(method, "GET") == 0){
			strcpy(buf, getenv("QUERY_STRING"));
		}else{
			content_length=atoi(getenv("CONTENT_LENGTH"));
			int i = 0;
			for(; i < content_length; i++){
            //从标准输入读取字符到buf
				read(0, buf+i, 1);
			}
			buf[i] = '\0';
		}
	}

	//buf
	fprintf(stderr, "cgi arg: %s\n", buf);
	math_begin(buf);
}













