/* libs/cutils/socket_network_client.c
**
** Copyright 2006, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License"); 
** you may not use this file except in compliance with the License. 
** You may obtain a copy of the License at 
**
**     http://www.apache.org/licenses/LICENSE-2.0 
**
** Unless required by applicable law or agreed to in writing, software 
** distributed under the License is distributed on an "AS IS" BASIS, 
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
** See the License for the specific language governing permissions and 
** limitations under the License.
*/

#include <cutils/sockets.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

#ifndef HAVE_WINSOCK
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#endif


/* Connect to port on the IP interface. type is
 * SOCK_STREAM or SOCK_DGRAM. 
 * return is a file descriptor or -1 on error
 */
int socket_network_client(const char *host, int port, int type)
{
    struct hostent *hp;
    union {
        struct sockaddr_in in;
        struct sockaddr generic;
    } addr;
    socklen_t alen;
    int s;

    hp = gethostbyname(host);
    if(hp == 0) return -1;
    
    memset(&addr.in, 0, sizeof(addr.in));
    addr.in.sin_family = hp->h_addrtype;
    addr.in.sin_port = htons(port);
    memcpy(&addr.in.sin_addr, hp->h_addr, hp->h_length);

    s = socket(hp->h_addrtype, type, 0);
    if(s < 0) return -1;

    if(connect(s, &addr.generic, sizeof(addr.in)) < 0) {
        close(s);
        return -1;
    }

    return s;

}
