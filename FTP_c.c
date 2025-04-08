#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(int argc, char **argv){
    int sockid;
    char file[2000],mes[2000];
    struct sockaddr_in server, client;
    FILE *fp;
    sockid=socket(AF_INET,SOCK_STREAM,0);
    if(sockid<0){
        printf("Couldn't create socket");
        return -1
    }
    printf("Socket created");
    server.sin_family=AF_INET;
    server.sin_port=htons(8888);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");;
    if(connect(sockid,(struct sockaddr*)&server,sizeof(server))<0){
        puts("Connect error");
        return -1;
    }
    puts("Connected");
    puts("FileNmae: ");
    scanf("%s",&file);
    if(send(sockid,file,strlen(file),0)<0){
        puts("Couldn't send");
        return -1;
    }
    fp.open("back","w");

    while(recv(sockid,message,2000,0)){
        if(strcmp(message,"EOF")){
            fputs(message,fp);
            puts(message);
        }
        else{
            fclose(fp);
        }
    }
    return 0;
}
