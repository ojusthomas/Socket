import socket               # Import socket module
# from sendfile import sendfile
def readFromServer():
	print "readFromServer"
	s = socket.socket()         # Create a socket object
	port = 8000                 # Reserve a port for your service.
	s.connect(('', port))
	s.send("Read ")
	s.send("input.txt ")
	#s.send("start\n")
	f = open('toRecvSer.txt','wb')
	print 'Reading...'
	l = s.recv(1024)
	while (l):
	  print 'Receiving... '
	  print l
	  f.write(l)
	  l = s.recv(1024)
	  print l
	f.close()
	#s.send("end")	
	s.send("Done Receiving");
	print "Done Sending"
	print s.recv(1024)
	s.close
						 # Close the socket when done
def writeToServer():
	s = socket.socket()         # Create a socket object
	port = 8000                 # Reserve a port for your service.
	s.connect(('', port))
	m = "Write "
	s.send(m)
	print "send " +m
	m = "output.pdf "
	s.send(m)
	print "send "+ m
	f = open('input.txt','rb')
	print 'Sending...'
	m = ""
	while(m !="Start"): 
		print "Waiting for start"
		m = s.recv(1024)
	print "$$$$"+m
	
	l = f.read(1024)
	print l+" &&&&&"
	while (l):
		print '\n Sending...'
		s.send(l)
		l = f.read(1024)
		print l+" *****\n"
	f.close()
	l = "end"
	s.send(l);
	print "Done Sending"
	print s.recv(1024)
	s.close        
readFromServer()
#writeToServer()
