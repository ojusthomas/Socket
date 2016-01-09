import socket               # Import socket module

s = socket.socket()         # Create a socket object
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#host = socket.gethostname('') # Get local machine name
port = 8000                 # Reserve a port for your service.
s.bind(('',port))        # Bind to the port
f = open('torecv.txt','wb')
s.listen(5)                 # Now wait for client connection.
while True:
    c, addr = s.accept()     # Establish connection with client.
    print 'Got connection from', addr
    print "Receiving..."
    l = c.recv(1024)
    print l
    while (l!='end'):
        print "Receiving..."
        f.write(l)
        l = c.recv(1024)
        print l
    f.close()
    if(l=="end"):
        print "Done Receiving"
        c.send('Thank you for connecting')
        c.close()                # Close the connection