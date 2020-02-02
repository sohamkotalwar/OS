#! /bin/bash

display() {
	echo "-------------------STUDENT DATA--------------------"
	echo -e "Name\tRollNumber\tMob Number"
	cat student.txt
	echo "---------------------------------------------------"

}

insert() {
	echo " Enter Details :-"
	
	echo " Enter Name :-"
	read sname

	echo "Enter Roll Number :-"
	read roll

	echo "Enter Mobile Number :-"
	read mob

	echo -e $sname"\t"$roll"\t\t"$mob >> student.txt

	echo "Record Inserted Successfully!"
}

search() {
	echo "Enter Roll Number to be searched:"
	read roll

	echo -e "\nName\tRoll Number\t\tMob Number\n"

	grep -w $roll student.txt
}

delete() {
	echo "Enter Roll Number to be deleted:"
	read roll

	grep -v $roll student.txt > temp.txt
	#sed "/"$roll"/d" student.txt > temp.txt
	mv temp.txt student.txt

	echo "Record deleted Successfully!!"
}
create() {
					echo "enter no. of records:"
					read m
					j=0
					for (( ; $j < $m ; j++ ))
				 	do
						echo "Enter Details :-"
	
						echo "Enter Name :-"
						read sname

						echo "Enter Roll Number :-"
						read roll

						echo "Enter Mobile Number :-"
						read mob

						echo -e $sname"\t"$roll"\t\t"$mob >> student.txt
						#	i=`expr $i + 1`
					done
 
}

while(true)
	do
	echo "-----------------STUDENT DATABASE------------------"
	echo "1.create Record  "
	echo "2.Insert Record  "
	echo "3.Display Record "
	echo "4.Search Record  "
	echo "5.Delete Record  "
	echo "6.Exit"
	echo "---------------------------------------------------"
	echo "Enter your choice:-"
	read choice

		case $choice in
				1)create;;
				2) insert;;
				3) display;;
				4) search;;
				5) delete;;
				6) exit;;
				*) echo "\nYou entered wrong choice"
		esac 
	done
