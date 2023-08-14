int sockfd;
struct sockaddr_in saddr;

sockfd = socket(PF_INET, SOCK_STREAM, 0);
saddr.sin_family = AF_INET;
saddr.sin_port = htons();
saddr.sin_addr.s_addr = inet_addr();

bind(sockfd, (sockaddr *)&saddr, sizeof saddr);
