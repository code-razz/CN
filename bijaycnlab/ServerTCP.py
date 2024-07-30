from socket import *
serverName='127.0.0.1'
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
while 1:
    print ("The server is ready to receive")
    connectionSocket, addr = serverSocket.accept()
    sentence = connectionSocket.recv(1024).decode()
    file=open(sentence,"r")
    l=file.read(1024)
    connectionSocket.send(l.encode())
    print ('\nSent contents of ' + sentence)
    file.close()
    connectionSocket.close()





# from socket import *
# ServerName='127.0.0.1'
# ServerPort=12000
# server_socket=socket(AF_INET,SOCK_STREAM)
# server_socket.bind((ServerName,ServerPort))
# server_socket.listen(1)
# while True:
#     print("Server is ready to receive")
#     connection_socket,addr=server_socket.accept()
#     Naame=connection_socket.recv(1024)
#     try:
#         file=open(Naame.decode(),"r")
#         data=file.read()
#         connection_socket.send(data.encode())
#         # file.close()
#         print("Sent the contents of  "+Naame.decode())
#     except FileNotFoundError:
#         print("File not found")
    
 
#     connection_socket.close()