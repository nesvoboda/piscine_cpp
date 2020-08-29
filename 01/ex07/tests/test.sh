#! /bin/bash 

function check_exit_status {
	if [ $? -eq $1 ]
	then
		printf "\033[1;32m ✓ PASS\033[0m\n"
	else
		printf "\033[0;31mFAIL\033[0m\n"
	fi
}

function check_file_contents {
	if [ $? -eq 0 ]
	then
		DIFF=$(diff $1 $2) 
		if [ "$DIFF" == "" ] 
		then
			printf "\033[1;32m ✓ PASS\033[0m\n"
			return
		fi
	fi
	printf "\033[0;31mFAIL\033[0m\n"
}

# Make the binary if it's not ready
make -C ../

# No arguments
echo "Test 1 — no arguments"

../replace 

check_exit_status 1

# Test 2
echo "Test 2 — only one argument"

../replace /dev/null

check_exit_status 1

# Test 3
echo "Test 3 — two arguments"

../replace /dev/null "string"

check_exit_status 1

# Test 4
echo "Test 4 — nonvalid infile"

../replace ./donttouchme "string" "tring"

check_exit_status 1

# Test 5
echo "Test 5 — nonvalid outfile"

../replace /dev/null "string" "tring"

check_exit_status 1

# Test 6
echo "Test 6 — nonvalid outfile"

../replace /dev/null "string" "tring"

check_exit_status 1

# Test 7
echo "Test 7 — replace one letter"

../replace test07_input.txt "e" "a"

check_file_contents test07_input.txt.replace test07_output.txt

# Test 8
echo "Test 8 — War and Peace by Leo Tolstoy"

../replace test08_input.txt "war" "peace"

check_file_contents test08_input.txt.replace test08_output.txt

# Test 9
echo "Test 9 — Replace x by xy"

../replace test09_input.txt "drive" "overdrive"

check_file_contents test09_input.txt.replace test09_output.txt

# Test 10
echo "Test 10 — Replace x by xy -> newline"

../replace test10_input.txt "drive" "drive"

check_file_contents test10_input.txt.replace test10_output.txt