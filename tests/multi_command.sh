#!/bin/sh

{ echo "echo ls ; cat makefile ; ls -l src" ;
    echo "ls ; cat makefile ; ls -l src" ;
    echo "echo badcommand; ls -l" ;
    echo "badcommand ; ls -l" ;
    echo "echo ls -l ; badcommand" ;
    echo "ls -l ; badcommand" ;
    echo "echo cat makefile || ls -l" ;
    echo "cat makefile || ls -l" ;
    echo "echo badcommand || ls -l" ;
    echo "badcommand || ls -l" ;
    echo "echo cat makefile || ls -l src || ls -a" ;
    echo "cat makefile || ls -l src || ls -a" ;
    echo "echo cat makefile && ls -l src" ;
    echo "cat makefile && ls -l src" ;
    echo "echo cat makefile || ls -l src && ls -a" ;
    echo "cat makefile || ls -l src && ls -a" ;
    echo "echo badcommand && cat makefile" ;
    echo "badcommand && cat makefile" ; 
    echo "echo exit" ;
    echo "exit" ; } | bin/rshell
