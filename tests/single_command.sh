#!/bin/sh

{ echo "echo ls" ;
    echo "ls" ;
    echo "echo touch newfile" ;
    echo "touch newfile" ;
    echo "echo ls -l" ;
    echo "ls -l" ;
    echo "echo rm newfile" ;
    echo "rm newfile" ;
    echo "echo ls -l -a" ;
    echo "ls -l -a" ;
    echo "echo exit" ;
    echo "exit" ; } | bin/rshell
