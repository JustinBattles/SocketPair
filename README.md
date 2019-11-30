# SocketPair


 ``` 
 Create a parent function that is given the childs process id and the two
  socketpair descriptors, then performs the following tasks:
  0) closes the unneeded side of the socketpair:
  1) Reads from stdin until EOF:
   a) Writes the data from stdin to the socket.
   b) Waits for the child to respond (i.e. reads from the socket)
   c) Writes the response to the screen (stdout)
  2) Closes the socket when EOF on the terminal is reached.
  3) Waits for the child to complete.
 
Create a child function that is given the socket descriptors and does the
  following:
  0) closes the unneeded side of the socketpair.
  1) Reads messages from the socket until EOF is reached:
   a) Scans the message and rot13's each character.  Uppercase characters
    should remain uppercase, lowercase should remain lowercase.
    The conversion function is:
     a-z -> n-z,a-m
   b) Writes the converted message back to the socket.
 2) closes the socket on EOF and exits.
 
 Complete the main function that performs the following:
  1) Creates a socketpair (man 2 socketpair), it should likely be a SOCK_STREAM
     socket.
  2) Forks a new process and launches the parent() / child() functions
     accordingly.
