#given a text file file.txt, print just 10th line of the file

#solution 1
cat file.txt | awk 'NR==10'

#solution 2
sed -n '10p' file.txt

#solution 3
awk 'NR==10' file.txt
