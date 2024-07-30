# ClientTCP.py
from socket import *
serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
sentence = input("Enter file name: ")

clientSocket.send(sentence.encode())
filecontents = clientSocket.recv(1024).decode()
print ('\nFrom Server:\n')
print(filecontents)
clientSocket.close()





# from socket import *
# ServerName='127.0.0.1'
# ServerPort=12000
# client_socket=socket(AF_INET,SOCK_STREAM)
# client_socket.connect((ServerName,ServerPort))
# naame=input("Enter the file name")
# client_socket.send(naame.encode())
# data=client_socket.recv(1024)
# print("from server\n")
# print(data.decode())