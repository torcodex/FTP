#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(int argc, char **argv){
    int sockid, new_sock,c;
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
    server.sin_addr.s_addr=INADDR_ANY;

    if(bind(sockid,(structsockaddr*)&server,sizeof(server))<0){
        puts("bind failed");
        return 0;
    }
    printf("Bind done");
    listen(sockid,3);
    puts("listening...");
    c=sizeof(struct sockaddr_in);
    new_sock=accept(sockid,(struct sockaddr*)&client,sizeof(client));
    if(new_sock<0){
        puts("couldn't accept");
        return -1;
    }
    puts("connection accepted");
    recv(new_sock,file,2000,0);
    fp=fopen("hello.txt",r);
    if(fp==NULL){
        strcpy(message,"File not found");
        send(new_sock,message,2000,0);
        puts(message);
    }
    else{
        while(fgets(message,2000,fp)){
            send(new_sock,message,2000,0);
            puts(message);
        }
        fclose(fp);
    }
    strcpy(message,"EOF");
    send(new_sock,message,2000,0);
    return 0;
}
