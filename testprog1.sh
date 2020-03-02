#!/bin/bash
std=0

echo 'Hello =)'
cat /etc/passwd

echo 'Please, choose number of the option and press Enter: '
echo '1 - Block user'
echo '2 - Unblock user'
echo '0 - Exit'

while [ $std = 0 ]
do
	read number
	case $number in
	1)
		echo 'Please, choose one of the username:'
		read username
		passwd -l $username
		echo 'Do you want continue? Please press y - "Yes" or n - "No"'
		read std1
		if [ $std1 = 'n' ]
		then	
			std=1
		fi
		;;
	2)
		echo 'Please, choose one of the username:'
		read username
		passwd -u $username
		echo 'Do you want continue? Please press y - "Yes" or n - "No"'
		read std1
		if [ $std1 = 'n' ]
		then
			std1=1	
		fi
		;;
	0)
		exit 0
		;;
	*)
		echo 'Please, insert true number'
		echo 'I know then you can =^.^='
		;;
	esac
done


	

