/*
to do:
    implement an epoll loop
    set up sockets
    pass file descriptors to epoll
    catch events and respond
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>

#define MAXEVENTS 64
#define UDPPORT
#define	TCPPORT

main() {
  int i,epollfd; //iterator, epoll file descriptor 
  int s = 0; //holds return values
  struct epoll_event event;
  struct epoll_event *events;
  int sockets[3] = {0,1,2};//0 for UDP 1 for TCP single line 2 for TCP until EOF.
  int socketfd[3];

  for(i=0;sizeof(socketfd)/sizeof(socketfd[0]);i++){

    socketfd[i] = create_socket(sockets[i]);

    s = listen(socketfd[i], SOMAXCONN);
    if(s == -1) goto Echo_Error; //Error checking

    epollfd = epoll_create1(0);
    if(epollfd == -1) goto Echo_Error; //Error checking

    event.data.fd = socketfd[i];
    event.events = EPOLLIN | EPOLLET;
    s = epoll_ctl (epollfd, EPOLL_CTL_ADD, socketfd[i], &event);
    if(s == -1) goto Echo_Error; //Error checking

  } //ends bind loop

  while(1){ //begin server loop
    int n,i;//number of active sockets, iterator.
    for(i=0; i<n;i++){
      if(events[i].events & EPOLLIN){//new connections
	if(events[i].data.fd = socketfd[0]){//UDP

	  }
	else if(events[i].data.fd = socketfd[1]){//TCP

	  }
	else if(events[i].data.fd = socketfd[2]){//TCP until EOF

	  }



      }//EPOLLIN if
      else if((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP)){
	fprintf (stderr, "epoll error\n");//error checking without an errno value
	close (events[i].data.fd);
      }// if errors
      else
	
    }//for
  }//while: end server loop


  //s = server_loop();
  //if(s == -1) goto Echo_Error; //Error checking

  free (events);
  close (socketfd);
  return 0;


  Echo_Error:
  free (events);
  close (socketfd);
  perror("Echo_Error");
  return -1;
}

int server_loop(){
}

static int create_socket(int proto int port) {
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int s = 0; //holds return values
  int sfd = 0; 
  memset (&hints, 0, sizeof (struct addrinfo));

  //build addrinfo struct
  hints.ai_family = AF_UNSPEC;

  if (proto = 0) 
    hints.ai_socktype = SOCK_DGRAM;
  else 
    hints.ai_socktype = SOCK_STREAM;
  
  hints.ai_flags = AI_PASSIVE;

  s = getaddrinfo(NULL, port, &hints, &result);
  if (s != 0) goto Socket_Error; //Error checking
  
  for(rp = result; rp != NULL; rp->ai_next)
  {
    sfd = socket (rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1)
      continue;
    s = bind (sfd, rp->ai_addr, rp->ai_addrlen);
    if (s == 0)
    {
      /* We managed to bind successfully! */
      break;
    }
    close (sfd);
  }
  if (rp == NULL) goto Socket_Error; //Error checking
  
  
  freeaddrinfo (result);
  return make_non_bind(fd); //makes the socket non-binding
  
  Socket_Error:
  freeaddrinfo (result);
  perror("create_socket");
  return -1;
}


static int make_non_bind(int fd){
  int flags, s;
  flags = fcntl (fd, F_GETFL, 0);
  
  if (flags = -1) goto Bind_Error; //Error checking
  
  flags |= O_NONBLOCK;
  s = fcntl (sfd, F_SETFL, flags);
  
  if (s = -1) goto Bind_Error; //Error checking

  return 0

  Bind_Error:
  perror("fcntl");
  return -1;
}





!s && {perror(""); goto Echo_Error;};

