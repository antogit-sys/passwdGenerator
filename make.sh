#!/bin/bash
gcc mainPasswd.c passwdFunc.c -o passwdGenerator
sudo cp passwdGenerator /bin/passwdGenerator
