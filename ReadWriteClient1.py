import socket               # Import socket module
# from sendfile import sendfile
                # Close the socket when done
def writeToServer():
	s = socket.socket()         # Create a socket object
	port = 8000                 # Reserve a port for your service.
	s.connect(('', port))
	s.send("Write")
	f = open('tosend.txt','rb')
	print 'Sending...'
	l = f.read(1024)
	print l
	while (l):
		print 'Sending...'
        s.send(l)
    	l = f.read(1024)

	f.close()
	l = "end"
	s.send(l);
	print "Done Sending"
	print s.recv(1024)
	s.close        
readFromServer()