#!/usr/bin/env python
from socket import socket, AF_INET, SOCK_DGRAM
import sys

SERVER_IP = 'localhost'
PORT_NUMBER = 5000
SIZE = 1024

def client():
    if len(sys.argv) > 1:
        server_ip = sys.argv[1]
    else:
        server_ip = SERVER_IP
    
    print("Test client sending packages to IP {0}, via port {1}"
        .format(server_ip, PORT_NUMBER))

    my_socket = socket(AF_INET, SOCK_DGRAM)
    
    try:
        while True:
            #message = raw_input("Send message to server: ")
            message2 = 'fasf'
            my_socket.sendto(message2, (SERVER_IP, PORT_NUMBER))
    except KeyboardInterrupt:
        print("Client exited by user")
        sys.exit(0)


if __name__ == '__main__':
    client()
        
