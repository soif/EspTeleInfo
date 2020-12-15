#!/bin/bash

# gzip data medias
SRC_DIR='EspTeleInfo'
ROOT_DIR=$(dirname $(dirname $(readlink -f $0)))
DATA_DIR="$ROOT_DIR/$SRC_DIR/data"
#CACHE_DIR="$ROOT_DIR/.cache"

usage () { echo "Usage: $0 [-u] [-z] (Unzip or Zip)"; echo; exit 1; }

while getopts “:uz” opt; do
  case $opt in
	z ) 	echo "gzip files in $DATA_DIR" ;;
	u ) 	echo "ungzip files in $DATA_DIR";  UNZIP=1 ;;
    * ) 	usage ;;
  esac
done

if ((OPTIND == 1))
then
	usage
fi

for FILE in 'index.htm' 'css/main.css' 'js/main.js'
do
	if [ $UNZIP ]; then FILE="$FILE.gz"; fi
	FILE="$DATA_DIR/$FILE"
	echo  -n "* Processing $FILE	"
	if test -f "$FILE"; then
		echo 
		if [ $UNZIP ]; 
		then 
			gunzip $FILE
			#rm $FILE
		else
			gzip $FILE
		fi
	else 
		echo "Doesn't Exist !";
	fi
done

# try to wakeup directory when remotely mounted via sshfs
echo 
mv  "$DATA_DIR" "$DATA_DIR-"
touch "$DATA_DIR-"
sleep 1
mv  "$DATA_DIR-" "$DATA_DIR"
touch "$DATA_DIR"

#makes platformio happy
#rm -rf "$CACHE_DIR"


exit 0
