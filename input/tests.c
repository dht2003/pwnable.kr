// modified file to test my exploit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[], char* envp[]){
        printf("Welcome to pwnable.kr\n");
        printf("Let's see if you know how to give input to program\n");
        printf("Just give me correct inputs then you will get the flag :)\n");

        // argv
        if(argc != 100) { 
                printf("not enoguth args");
                return 1;
        }
        if(strcmp(argv['A'],"\x00")) {
                printf("A not xoo");
                return 2;
        }
        if(strcmp(argv['B'],"\x20\x0a\x0d")) {
                printf("B not ");
                return 3;
        }
        printf("Stage 1 clear!\n");

        // stdio
        char buf[4];
        read(0, buf, 4);
        if(memcmp(buf, "\x00\x0a\x00\xff", 4)) {
                printf("stdio 1 fail");
                return 4;
        }
        read(2, buf, 4);
        if(memcmp(buf, "\x00\x0a\x02\xff", 4)) {
                printf("stdio 2 fail");
                return 5;
        }
        printf("Stage 2 clear!\n");

        // env
        if(strcmp("\xca\xfe\xba\xbe", getenv("\xde\xad\xbe\xef"))) {
                printf("env failed");
                return 6;
        }
        printf("Stage 3 clear!\n");

        // file
        FILE* fp = fopen("\x0a", "r");
        if(!fp) {
                printf("Cannot find fp\n");
                return 7;
        }
        if( fread(buf, 4, 1, fp)!=1 ) {
                printf("Incorrect file read len\n");
                return 8;
        }
        if( memcmp(buf, "\x00\x00\x00\x00", 4) ) {
                printf("Incorrect read value\n");
                return 9;
        }
        fclose(fp);
        printf("Stage 4 clear!\n");

        // network
        int sd, cd;
        struct sockaddr_in saddr, caddr;
        sd = socket(AF_INET, SOCK_STREAM, 0);
        if(sd == -1){
                printf("socket error, tell admin\n");
                return 10;
        }
        saddr.sin_family = AF_INET;
        saddr.sin_addr.s_addr = INADDR_ANY;
        saddr.sin_port = htons( atoi(argv['C']) );
        if(bind(sd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0){
                printf("bind error, use another port\n");
                return 11;
        }
        listen(sd, 1);
        int c = sizeof(struct sockaddr_in);
        cd = accept(sd, (struct sockaddr *)&caddr, (socklen_t*)&c);
        if(cd < 0){
                printf("accept error, tell admin\n");
                return 12;
        }
        if( recv(cd, buf, 4, 0) != 4 ) return 13;
        if(memcmp(buf, "\xde\xad\xbe\xef", 4)) return 14;
        printf("Stage 5 clear!\n");
        return 0;
        // here's your flag
        system("/bin/cat flag");
        return 0;
}

