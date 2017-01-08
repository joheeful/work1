#include <stdio.h>
#include <string.h>

void appendx(char* outbuff, char* at);
void appendc(char* outbuff, char at);

int offset = 0;

int main(int argc, char** argv) {

	if (argc < 4) {
		printf("error!");
		return 0;
	}

	printf("%s\n", argv[0]);

	char buffer[1024];
	char outbuffer[1024];

	memset(buffer, '\0',1024);
	memset(outbuffer, '\0', 1024);

	int size;
	size = strlen(argv[1]);

	for (int a = 0; a < strlen(argv[1]); a++) {
		for (int b = 0; b < strlen(argv[2]); b++) {
			printf("%c %c\n", argv[1][a+b],argv[2][b]);
			if (argv[1][a + b] == argv[2][b]) {
				printf("%c", argv[1][a + b]);
				//	argv[1][a + b] = 'x';
				//	outbuffer[0] = argv[1][a + b];
					//printf("find : %c\n",outbuffer[0]);
				if (strlen(argv[2]) == (b + 1)) {
					printf("%c", argv[2][b]);
					printf("yes!\n");	
			//		memcpy(outbuffer+a,argv[3],strlen(argv[3]));
					appendx(outbuffer,argv[3]);
					a = a+b;
				}
			}
			else {
				appendc(outbuffer, argv[1][a]);
//				outbuffer[a] = argv[1][a];
				break;
			}
			//break;
		}
		printf("%c", argv[1][a]);
	}
	printf("find : %s\n", outbuffer);

	memcpy(buffer, "hello", 5);
	printf("%s", buffer);
	for (int i = 0; i < 5; i++) {
		if (buffer[i] == 'l') {
			buffer[i] = 'x';
		}
		printf("%c", buffer[i]);
	}


}
void appendx (char* outbuff, char* at) {
	outbuff; //outbuff여넣기 <- 그 다음 argv 받은 문자열
	//int a = strlen(outbuff);
	memcpy(outbuff + offset, at, strlen(at));
	offset += strlen(at);
	//outbuff[a] = at;
}
void appendc(char* outbuff, char at) {
	outbuff; //outbuff여넣기 <- 그 다음 argv 받은 문자열
	//int a = strlen(outbuff);
	memcpy(outbuff + offset, &at,1);
	++offset;
	//outbuff[a] = at;
}
