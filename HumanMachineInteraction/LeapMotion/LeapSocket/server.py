#!/usr/bin/env python
from socket import socket, gethostbyname, AF_INET, SOCK_DGRAM
import sys, datetime

PORT_NUMBER = 5000
SIZE = 1024

def server():
    host_name = gethostbyname('localhost')
    my_socket = socket(AF_INET, SOCK_DGRAM)
    my_socket.bind((host_name, PORT_NUMBER))

    print("Test server listening on port {0}\n").format(PORT_NUMBER)
    
    try:
        while True:
            (data, addr) = my_socket.recvfrom(SIZE)
            date = datetime.datetime.now().strftime('%Y-%m-%d %H:%M')
            #print('{0}\t{1}\n{2}\n'.format(addr[0], date, data))
            print(data)
            
    except KeyboardInterrupt:
        print("Server closed down by user") 
        sys.exit(0)
    except:
        print("Server error, closing down")
        sys.exit(1)


if __name__ == '__main__':
    server()
   
