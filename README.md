# SocketPair


  Create a parent function that is given the childs process id and the two
  socketpair descriptors, then performs the following tasks:
  0) closes the unneeded side of the socketpair:
  1) Reads from stdin until EOF:
   a) Writes the data from stdin to the socket.
   b) Waits for the child to respond (i.e. reads from the socket)
   c) Writes the response to the screen (stdout)
  2) Closes the socket when EOF on the terminal is reached.
  3) Waits for the child to complete.
 
