grep --include='*.c' -rnw '.' -e "main" -l | \
	awk -F'/' '{print $2;}' | \
	awk 'NR  { if (index($0, ".c") !=0 ) printf " "$0;next;}1' 
