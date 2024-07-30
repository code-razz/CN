from socket import *
serverName = "127.0.0.1"
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
sentence = input("\nEnter file name: ")
clientSocket.sendto(bytes(sentence,"utf-8"),(serverName, serverPort))
filecontents,serverAddress = clientSocket.recvfrom(2048)
print ('\nReply from Server:\n')
print (filecontents.decode("utf-8"))
clientSocket.close()
# clientSocket.close()




# from socket import *
# serverName='127.0.0.1'
# serverPort=12000
# client_socket=socket(AF_INET,SOCK_DGRAM)
# Naame=input("Enter file name")
# client_socket.sendto(bytes(Naame.encode("utf-8")),(serverName,serverPort))
# data,addr=client_socket.recvfrom(1024)
# data=data.decode("utf-8")
# print("received file is :" +data)