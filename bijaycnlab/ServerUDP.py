from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(("127.0.0.1", serverPort))
print ("The server is ready to receive")
while 1:
    sentence, clientAddress = serverSocket.recvfrom(2048)
    sentence = sentence.decode("utf-8")
    file=open(sentence,"r")
    con=file.read(2048)
    serverSocket.sendto(bytes(con,"utf-8"),clientAddress)
    print ('\nSent contents of ', end = ' ')
    print (sentence)
    # for i in sentence:
    # print (str(i), end = '')
    file.close()





# from socket import *
# serverName='127.0.0.1'
# serverPort=12000
# server_socket=socket(AF_INET,SOCK_DGRAM)
# server_socket.bind((serverName,serverPort))
# print("Server is ready to receive")
# while True:
#     data,addr=server_socket.recvfrom(1024)
#     data=data.decode("utf-8")
#     try:
#         file=open(data,"r")
#         sentence=file.read()
#         server_socket.sendto(bytes(sentence.encode("utf-8")),addr)
#         print("Sent contents of "+data)
#         file.close()
#     except FileNotFoundError:
#         print("File not found")
        
#         server_socket.sendto(bytes("error opening that file".encode("utf-8")),addr)