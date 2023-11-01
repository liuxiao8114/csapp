## 11.1
The fundamental operation in the client-server model is *transaction*. A client-server transaction consists four steps:
1. When a client need a service, it sends a request to the server.
2. The server receives the request, interprets it, and manipulates its resources in the appropriate way.
3. The server sends a response to the client and then waits for the next request.
4.

It is important to realize that clients and servers are processes and not machines,
or hosts as they are often called in this context. A single host can run many
different clients and servers concurrently, and a client and server transaction can
be on the same or different hosts. The client-server model is the same, regardless
of the mapping of clients and servers to hosts.

## 11.2 Networks
A host can send a chunk of bits called a *frame* to any other host on the segment.
Each frame includes some fixed number of *header* bits that identify the source and destination of the frame and the frame length, followed by a *payload* of data bits.

At a higher level in the hierarchy, multiple incompatible LANs can be connected by specialized computers called routers to form an internet (interconnected network). Each router has an adapter (port) for each network that it is connected to. Routers can also connect high-speed point-to-point phone connections, which are examples of networks known as WANs (wide area networks), so called because they span larger geographical areas than LANs. In general, routers can be used to build internets from arbitrary collections of LANs and WANs.

The crucial property of an internet is that it can consist of different LANs
and WANs with radically different and incompatible technologies. Each host is
physically connected to every other host, but how is it possible for some source
host to send data bits to another destination host across all of these incompatible
networks?
The solution is a layer of protocol software running on each host and router
that smooths out the differences between the different networks. This software
implements a protocol that governs how hosts and routers cooperate in order to
transfer data. The protocol must provide two basic capabilities:

Naming scheme.
  Different LAN technologies have different and incompatible ways of assigning addresses to hosts. The internet protocol smooths these differences by defining a uniform format for host addresses. Each host is then assigned at least one of these internet addresses that uniquely identifies it.
Delivery mechanism.
  Different networking technologies have different and incompatible ways of encoding bits on wires and of packaging these bits into frames. The internet protocol smooths these differences by defining a uniform way to bundle up data bits into discrete chunks called packets. A packet consists of a header, which contains the packet size and addresses of the source and destination hosts, and a payload, which contains data bits sent from the source host.

1. host A invokes a system call that copies the data from client's VPA into a kernel buffer
2.
## 11.3 The Global Internet
Each Internet host runs software that implements the TCP/IP protocol
(Transmission Control Protocol/Internet Protocol), which is supported by almost
every modern computer system. Internet clients and servers communicate using
a mix of sockets interface functions and Unix I/O functions. (We will describe the
sockets interface in Section 11.4.) The sockets functions are typically implemented
as system calls that trap into the kernel and call various kernel-mode functions in
TCP/IP.
TCP/IP is actually a family of protocols, each of which contributes different
capabilities. For example, IP provides the basic naming scheme and a delivery
mechanism that can send packets, known as datagrams, from one Internet host to
any other host. The IP mechanism is unreliable in the sense that it makes no effort
to recover if datagrams are lost or duplicated in the network. UDP (Unreliable
Datagram Protocol) extends IP slightly, so that datagrams can be transferred
from process to process, rather than host to host. TCP is a complex protocol that
builds on IP to provide reliable full duplex (bidirectional) connections between
processes. To simplify our discussion, we will treat TCP/IP as a single monolithic
protocol. We will not discuss its inner workings, and we will only discuss some of
the basic capabilities that TCP and IP provide to application programs. We will
not discuss UDP.
From a programmer’s perspective, we can think of the Internet as a worldwide
collection of hosts with the following properties:
  + The set of hosts is mapped to a set of 32-bit IP addresses
  + The set of IP addresses is mapped to a set of identifiers called Internet domain names
  + A process on one Internet host can communicate with a process on any other Internet host over a connection

### 11.3.1 IP addresses
Storing a scalar address in a structure is an unfortunate artifact from the early
implementations of the sockets interface. It would make more sense to define
a scalar type for IP addresses, but it is too late to change now because of the
enormous installed base of applications.
```c
  struct in_addr {
    uint32_t s_addr;
  }
```

Application programs can convert back and forth between IP addresses and
dotted-decimal strings using the functions inet_pton and inet_ntop.
```c
  #include <arpa/inet.h>
  int inet_pton(AF_INET, const char *src, void *dst);
  // Returns: 1 if OK, 0 if src is invalid dotted decimal, −1 on error

  const char *inet_ntop(AF_INET, const void *src, char *dst, socklen_t size);
  // Returns: pointer to a dotted-decimal string if OK, NULL on error
```

### 11.3.2 Internet Domain Names
### 11.3.4 Internet Connections
A socket is an end point of a connection. Each socket has a corresponding socket address that consists of an Internet address and a 16-bit integer port2 and is denoted by the notation address:port.
The port in the client’s socket address is assigned automatically by the kernel
when the client makes a connection request and is known as an ephemeral port.
However, the port in the server’s socket address is typically some well-known
port that is permanently associated with the service.

## 11.4 The Socket Interface
### 11.4.1 Socket Address Structures
From the perspective of the Linux kernel, a socket is an end point for communication.
From the perspective of a Linux program, a socket is an open file with a corresponding descriptor.

The connect, bind, and accept functions require a pointer to a protocol specific
socket address structure. The problem faced by the designers of the sockets
interface was how to define these functions to accept any kind of socket address
structure. Today, we would use the generic void * pointer, which did not exist in
C at that time. Their solution was to define sockets functions to expect a pointer to a generic sockaddr structure (Figure 11.13) and then require applications to cast
any pointers to protocol-specific structures to this generic structure. To simplify
our code examples, we follow Stevens’s lead and define the following type:
typedef struct sockaddr SA;

```c
struct sockaddr_in {
  uint16_t       sin_family;
  uint16_t       sin_port;
  struct in_addr sin_addr;
  char           sin_zero[8];
}

struct sockaddr {
  uint16_t sa_family;
  char     sa_data[14];
}
```

### 11.4.2 The socket function
```c
  #include <sys/types.h>
  #include <sys/socket.h>

  int socket(int domain, int type, int protocol);
```
only partially opened and cannot yet be used for reading and writing.

### 11.4.3 The connect function
```c
  #include <sys/socket.h>
  int connect(int clientfd, const struct sockaddr *addr, socklen_t addrlen);
```
A client establishes a connection with a sever by calling connect function.

### 11.4.4 The bind function
```c
  #include <sys/socket.h>
  int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
The bind function asks the kernel to associate the server’s socket address in addr with the socket descriptor sockfd.

### 11.4.5 The listen function
```c
  #include <sys/socket.h>
  int listen(int sockfd, int backlog);
```
Clients are active entities that initiate connection requests. Servers are passive
entities that wait for connection requests from clients. By default, the kernel
assumes that a descriptor created by the socket function corresponds to an active
socket that will live on the client end of a connection. A server calls the listen
function to tell the kernel that the descriptor will be used by a server instead of a client.
The listen function converts sockfd from an active socket to a listening socket
that can accept connection requests from clients. The backlog argument is a hint
about the number of outstanding connection requests that the kernel should queue
up before it starts to refuse requests. The exact meaning of the backlog argument
requires an understanding of TCP/IP that is beyond our scope. We will typically
set it to a large value, such as 1,024.

### 11.4.6 The accept function
The accept function waits for a connection request from a client to arrive on the listening descriptor listenfd, then fills in the client’s socket address in addr, and returns a connected descriptor that can be used to communicate with the client using Unix I/O functions.
```c
  #include <sys/socket.h>
  int accept(int listenfd, struct sockaddr *addr, int *addrlen);
```
The listening descriptor serves as an end point for client
connection requests. It is typically created once and exists for the lifetime of
the server. The connected descriptor is the end point of the connection that is
established between the client and the server. It is created each time the server
accepts a connection request and exists only as long as it takes the server to service a client.

### 11.4.7 Host and Service Conversion
#### The getaddrinfo Function
Given host and service (the two components of a socket address), getaddrinfo returns a result that points to a linked list of addrinfo structures, each of which points to a socket address structure that corresponds to host and service.
After a client calls getaddrinfo, it walks this list, trying each socket address in turn until the calls to socket and connect succeed and the connection is established. Similarly, a server tries each socket address on the list until the calls to socket and bind succeed and the descriptor is bound to a valid socket address.
```c
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netdb.h>

  int getaddrinfo(
    const char *host,
    const char *service,
    const struct addrinfo *hints,
    struct addrinfo **result
  );
```
To avoid memory leaks, the application must eventually free the list by calling freeaddrinfo. If getaddrinfo returns a nonzero error code, the application can call gai_strerror to convert the code to a message string.
The host argument to getaddrinfo can be either a domain name or a numeric address (e.g., a dotted-decimal IP address). The service argument can be either a service name (e.g., http) or a decimal port number. If we are not interested in converting the hostname to an address, we can set host to NULL. The same holds for service. However, at least one of them must be specified. The optional hints argument is an addrinfo structure (Figure 11.16) that provides finer control over the list of socket addresses that getaddrinfo returns. When passed as a hints argument, only the ai_family, ai_socktype, ai_protocol, and ai_flags fields can be set. The other fields must be set to zero (or NULL). In practice, we use memset to zero the entire structure and then set a few selected fields:

  . By default, getaddrinfo can return both IPv4 and IPv6 socket addresses. Setting ai_family to AF_INET restricts the list to IPv4 addresses. Setting it to AF_INET6 restricts the list to IPv6 addresses.
  . By default, for each unique address associated with host, the getaddrinfo function can return up to three addrinfo structures, each with a different ai_socktype field: one for connections, one for datagrams (not covered), and
one for raw sockets (not covered). Setting ai_socktype to SOCK_STREAM
restricts the list to at most one addrinfo structure for each unique address,
one whose socket address can be used as the end point of a connection. This
is the desired behavior for all of our example programs.
. The ai_flags field is a bit mask that further modifies the default behavior.
You create it by oring combinations of various values. Here are some that we
find useful:
AI_ADDRCONFIG. This flag is recommended if you are using connections
[34]. It asks getaddrinfo to return IPv4 addresses only if the
local host is configured for IPv4. Similarly for IPv6.
AI_CANONNAME. By default, the ai_canonname field is NULL. If this
flag is set, it instructs getaddrinfo to point the ai_canonname field in
the first addrinfo structure in the list to the canonical (official) name
of host (see Figure 11.15).
AI_NUMERICSERV. By default, the service argument can be a service
name or a port number. This flag forces the service argument to be
a port number.
AI_PASSIVE. By default, getaddrinfo returns socket addresses that can
be used by clients as active sockets in calls to connect. This flag
instructs it to return socket addresses that can be used by servers as
listening sockets. In this case, the host argument should be NULL.
The address field in the resulting socket address structure(s) will be
the wildcard address, which tells the kernel that this server will accept
requests to any of the IP addresses for this host. This is the desired
behavior for all of our example servers.

When getaddrinfo creates an addrinfo structure in the output list, it fills in each field except for ai_flags. The ai_addr field points to a socket address structure, the ai_addrlen field gives the size of this socket address structure, and the ai_next field points to the next addrinfo structure in the list. The other fields describe various attributes of the socket address.
One of the elegant aspects of getaddrinfo is that the fields in an addrinfo
structure are opaque, in the sense that they can be passed directly to the functions
in the sockets interface without any further manipulation by the application code.
For example, ai_family, ai_socktype, and ai_protocol can be passed directly
to socket. Similarly, ai_addr and ai_addrlen can be passed directly to connect
and bind. This powerful property allows us to write clients and servers that are
independent of any particular version of the IP protocol.

#### The getnameinfo Function
The getnameinfo function is the inverse of getaddrinfo. It converts a socket address structure to the corresponding host and service name strings. It is the modern replacement for the obsolete gethostbyaddr and getservbyport functions, and unlike those functions, it is reentrant and protocol-independent.
```c
  #include <sys/socket.h>
  #include <netdb.h>
  int getnameinfo(
    const struct sockaddr *sa, socklen_t salen,
    char *host, size_t hostlen,
    char *service, size_t servlen,
    int flags
  );
  // Returns: 0 if OK, nonzero error code on error
```

The sa argument points to a socket address structure of size salen bytes, host
to a buffer of size hostlen bytes, and service to a buffer of size servlen bytes.
The getnameinfo function converts the socket address structure sa to the corresponding
host and service name strings and copies them to the host and service buffers. If getnameinfo returns a nonzero error code, the application can convert
it to a string by calling gai_strerror.
If we don’t want the hostname, we can set host to NULL and hostlen to zero.
The same holds for the service fields. However, one or the other must be set.
The flags argument is a bit mask that modifies the default behavior. You
create it by oring combinations of various values. Here are a couple of useful ones:
NI_NUMERICHOST. By default, getnameinfo tries to return a domain name in host. Setting this flag will cause it to return a numeric address string instead.
NI_NUMERICSERV. By default, getnameinfo will look in /etc/services and if possible, return a service name instead of a port number. Setting this flag forces it to skip the lookup and simply return the port number

### 11.4.8 Helper Functions for the Sockets Interface

we declare clientaddr as type struct sockaddr_storage rather than struct sockaddr_in. By definition, the sockaddr_storage structure is large enough to hold any type of socket address, which keeps the code protocol-independent.

## 11.5.4 Serving Dynamic Content
+ How does the client pass any program arguments to the server?
request parameters

+ How does the server pass these arguments to the child process that it creates?

+ How does the server pass other information to the child that it might need to generate the content?
response status
response body

+ Where does the child send its output?

##
