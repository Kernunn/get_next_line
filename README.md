# get_next_line

Function that returns a line, read from a file descriptor.

# Prototype
 ``int	get_next_line(int fd, char **line)``
 
# Return values
``1`` the line was read  
``0`` end of file  
``-1`` error  

# Usage
Calling function in a loop will then allow you to read the text
available on the file descriptor one line at a time until the end of it.

Multifd version can work with several fds at the same time, remembering the position in the file
