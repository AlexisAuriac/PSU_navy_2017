if [ $# -eq 2 ]; then
    pos1=$1
    pos2=$2
else
    ./bonus/create_map.py bonus/pos1
    ./bonus/create_map.py bonus/pos2
    pos1='bonus/pos1'
    pos2='bonus/pos2'
fi

xfce4-terminal --execute ./navy $pos1
sleep 0.1
./navy $(pidof navy) $pos2
