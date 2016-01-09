# usr/bin/python -tt
import socket               # Import socket module

def startServer ():   
	print "started server"
	s = socket.socket()         # Create a socket object
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	#host = socket.gethostname() # Get local machine name
	print "started server1111111111"
	port = 8000                 # Reserve a port for your service.
	s.bind(('', port))        # Bind to the port
	f = open('torecv.txt','wb')
	s.listen(5)                 # Now wait for client connection. 5 clients can be in wait queue
	print "started server22222222"
	while(1):
		print "inside loop"
		c, addr = s.accept()     # Establish connection with client.
		print "started server333333"
		print 'Got connection from', addr
		print "Receiving..."
		l = c.recv(1024)
		print l
		msg = l.split()
		print msg[0]
		if(msg[0] == "Read"): # For Reading File in Server from client
			print "@@@@ "+msg[1]
			print " opening "+msg[1]
			f1 = open(msg[1],'rb')
			if(f1):
				print msg[1]+" open "
				l = f1.read(10240000)
				while (l):
					print "&&"+l
					print "Sending..."
					c.sendall(l)
					l = f1.read(10240000)
				print l
			else : print "Sorry file didnot open"
			f1.close()
		if(msg[0] == "Write"): # For writing to File in server from client
			c.send("Start")			
			print "@@@11"+msg[1]
			print "Writing to "+msg[1]
			f1 = open(msg[1],'wb')
			if(f1):
				print "Open File "+ str(msg[1])
				l = c.recv(10240000)
				print l
				while(l != "end"):
					print l
					f1.write(l)
					l = c.recv(10240000)
			f1.close()
		print "Done "
		# c.send('Thank you for connecting')
		break
		
	c.close()                # Close the connection
while(1):
	startServer();
