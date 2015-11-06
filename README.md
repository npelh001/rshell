Nicholas Pelham

<h3>Overview</h3>
rshell is a simple shell program that serves as an interface between a user and their operating system.
rshell allows a user to chain commands together with specified connectors.
The connectors included in rshell are:
* (cmd1) && (cmd2) - Executes the second command only if the first command executes succesfully
* (cmd1) || (cmd2) - Executes the second command only if the first command fails to execute properly
* (cmd1) ; (cmd2) - Executes both commands regardless of the success or failure of the other

<h3>Known Bugs:</h3>
* Connectors don't work properly
    * Every command returns true unless a fatal error occurs
* Segmentation Fault if the first input is blank or includes only whitespace
* Certain expected commands found built into most shells do not work. Including but not limited to:
    * cd
    * alias
    * logout
* All output from rshell is monocolored. Output colors expected from commands like ls are not displayed.
* exit does not work in several cases:
    * when surrounded by whitespace
    * when followed by a comment
    * when connected to other commands with a valid connector
