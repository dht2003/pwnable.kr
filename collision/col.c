#include <stdio.h>
#include <string.h>
unsigned long hashcode = 0x21DD09EC;
unsigned long check_password(const char* p){
	int* ip = (int*)p;
	int i;
	int res=0;
	for(i=0; i<5; i++){
		res += ip[i];
	}
	printf("arr: %x,%x,%x,%x,%x\n",ip[0],ip[1],ip[2],ip[3],ip[4]);
	printf("one part : %lx\n", hashcode / 5);
	return res;
}

int main(int argc, char* argv[]){
	if(argc<2){
		printf("usage : %s [passcode]\n", argv[0]);
		return 0;
	}
	if(strlen(argv[1]) != 20){
		printf("argv : %s , len = %ld\n",argv[1],strlen(argv[1]));
		printf("passcode length should be 20 bytes\n");
		return 0;
	}

	printf("sum: %lx\n",check_password(argv[1]));
	if(hashcode == check_password( argv[1] )){
		printf("good\n");
		return 0;
	}
	else
		printf("wrong passcode.\n");
	return 0;
}
