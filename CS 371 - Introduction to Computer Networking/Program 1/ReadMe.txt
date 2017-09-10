To run, type make to execute Makefile.
The two files are Server.h and Server.c

Executing the Makefile will create an executable server file.
Parameters for executable server file:
        1st: Root Directory to be used.
        2nd: Port Number to be used.

Limitations: No post, put or delete algorithms available.

No known bugs were found.

Program Flow:
        Socket created, server begins listening for a client connection.
        A browser sends a request and connects to the server.
        A new process is created and the get request is evaluated and the
                required parameters get extracted so the correct file can be returned.
        If the file exists the body is sent to the server along with the HTTP 200 response
                If the file does not exist, a 404 Error response is sent to the client.
        The child process is reaped afterwards.
