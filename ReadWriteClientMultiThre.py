import socket               # Import socket module
#Importing all from thread
from thread import *
def readFromServer(port,ip,fromFile,toFile):
	print "readFromServer"
	s = socket.socket()         # Create a socket object
	port = 8000                 # Reserve a port for your service.
	s.connect(('192.168.42.11', port))
	s.send("Read ")
	s.send(fromFile)
	#s.send("start\n")
	f = open(toFile,'wb')
	print 'Reading...'
	l = s.recv(10240000)
	while (l):
	  print 'Receiving... '
	  print l
	  f.write(l)
	  l = s.recv(10240000)
	f.close()
	print l
	#s.send("end")	
	s.send("Done Receiving");
	print "Done Sending"
	print s.recv(1024)
	s.close 						 # Close the socket when done
	
def writeToServer(port,ip,fromFile,toFile):
	s = socket.socket()         # Create a socket object
	port = 8000                 # Reserve a port for your service.
	s.connect(('192.168.42.11', port))
	m = "Write "
	s.send(m)
	print "send " +m
	s.send(toFile)
	print "send "+ toFile
	f = open(fromFile,'rb')
	print 'Sending...'
	m = ""
	while(m !="Start"): 
		print "Waiting for start"
		m = s.recv(1024)
	print "$$$$"+m
	
	l = f.read(10240000)
	print l+" &&&&&"
	while (l):
		print '\n Sending...'
		s.sendall(l)
		l = f.read(10240000)
		print l+" *****\n"
	f.close()
	l = "end"
	s.send(l);
	print "Done Sending"
	print s.recv(1024)
	s.close   
while True:
	print "\n ********* Python Program to transfer File between two systems  ********* \n"     
	operation = raw_input(" \n Enter the operation required read / write : ")
	print operation
	if(operation == "read"):
		start_new_thread(readFromServer,(8000,'',"output.txt","toRecvSer.txt"))
		#readFromServer(8000,'',"output.txt","toRecvSer.txt")
	elif(operation == "write"):
		start_new_thread(writeToServer,(8000,'',"final.txt","output.txt"))
