# CS344_Project4
 Caleb Knight
 Project 4
 CS 344
 Part 1.
 An exercise to pipe the output of a process to the input of another
 and save the output in a file
 Goal: run ls -1a and wc -l --> pipe the output of ls into wc
 % ls -1a | wc -l   --> Tells us how many files in curr dir

Part 2. 
 A program that redirects output into a file
 ex. % redirout foo.txt ls -l -a
     % cat foo.txt
     Should give us a list of files with privacy info, size, names, etc