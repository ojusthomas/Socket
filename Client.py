import socket               # Import socket module
# from sendfile import sendfile
s = socket.socket()         # Create a socket object
#host = socket.gethostname('') # Get local machine name
port = 8000                 # Reserve a port for your service.

s.connect(('', port))
s.send("Hello server!")
f = open('tosend.txt','rb')
#blocksize = os.path.getsize("tosend.txt")
print 'Sending...'
l = f.read(1024)
print l
while (l):
    print 'Sending...'
    #sent = sendfile(sock.fileno(), file.fileno(), offset, blocksize)
    s.send(l)
    l = f.read(1024)
f.close()
l = "end"
s.send(l);
print "Done Sending"
print s.recv(1024)
s.close                     # Close the socket when done