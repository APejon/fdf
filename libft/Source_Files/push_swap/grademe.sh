#!/bin/bash

###############################################################################

DEFAULT='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
PURPLE='\033[0;35m'
CYAN='\033[1;36m'

###############################################################################
echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN START
echo -e $CYAN----------------------------------------------------------------------------------------------
COUNTER=0

# COUNTER_FAIL=0

# increment () {
# 	if [ ./push_swap $ARG | wc -l | sed 's/ //g' -le 5 ]; then echo -ne $YELLOW"Moves: "$GREEN \
# 	./push_swap $ARG | wc -l | sed 's/ //g' \
# 	let COUNTER++ 
# 	else [ echo -ne $YELLOW"Moves: "$RED \
# 	./push_swap $ARG | wc -l | sed 's/ //g' \
# 	let COUNTER_FAIL++ ]
# 	fi
# }

ARG="1 2 3"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="1 3 2"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="2 1 3"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="2 3 1"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t\t"

ARG="3 1 2"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t\t"

ARG="3 2 1"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t\t\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="1 2 3 4"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="1 2 4 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="1 3 2 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="1 3 4 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t\t"

ARG="1 4 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t\t"

ARG="1 4 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t\t\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="2 1 3 4"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"


ARG="2 1 4 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"


ARG="3 1 2 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="3 1 4 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="4 1 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="4 1 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="2 3 1 4"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"


ARG="2 4 1 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"


ARG="3 2 1 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="3 4 1 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="4 2 1 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="4 3 1 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="2 3 4 1"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"


ARG="2 4 3 1"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"


ARG="3 2 4 1"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="3 4 2 1"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="4 2 3 1"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t"

ARG="4 3 2 1"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t\t\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="1 2 3 4 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="1 2 3 5 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="1 2 5 3 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="1 2 4 3 5"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 2 4 5 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 2 5 4 3"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\n"
echo

ARG="1 3 2 4 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 3 2 5 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 3 4 2 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 3 4 5 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 3 5 2 4"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 3 5 4 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="1 4 2 3 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="1 4 2 5 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="1 4 3 2 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="1 4 3 5 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 4 5 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 4 5 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\n"
echo

ARG="1 5 2 3 4"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 5 2 4 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 5 3 2 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 5 3 4 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 5 4 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="1 5 4 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="2 1 3 4 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="2 1 3 5 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="2 1 4 3 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++
echo -ne $DEFAULT$ARG"\t"

ARG="2 1 4 5 3"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 1 5 3 4"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 1 5 4 3"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\n"

echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\n"
echo

ARG="3 1 2 4 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 1 2 5 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 1 4 2 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 1 4 5 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 1 5 2 4"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 1 5 4 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="4 1 2 3 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 1 2 5 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 1 3 2 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 1 3 5 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 1 5 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 1 5 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"
echo

ARG="5 1 2 3 4"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 1 2 4 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 1 3 2 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 1 3 4 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 1 4 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 1 4 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="2 3 1 4 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 3 1 5 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 4 1 3 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 4 1 5 3"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 5 1 3 4"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 5 1 4 3"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"
echo

ARG="3 2 1 4 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 2 1 5 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 4 1 2 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 4 1 5 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 5 1 2 4"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 5 1 4 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="4 2 1 3 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 2 1 5 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 3 1 2 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 3 1 5 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 5 1 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 5 1 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"
echo

ARG="5 2 1 3 4"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 2 1 4 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 3 1 2 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 3 1 4 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 4 1 2 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 4 1 3 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="2 3 4 1 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 3 5 1 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 4 3 1 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 4 5 1 3"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 5 3 1 4"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 5 4 1 3"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"
echo

ARG="3 2 4 1 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 2 5 1 4"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 4 2 1 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 4 5 1 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 5 2 1 4"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 5 4 1 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="4 2 3 1 5"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 2 5 1 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 3 2 1 5"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 3 5 1 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 5 2 1 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 5 3 1 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"
echo

ARG="5 2 3 1 4"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 2 4 1 3"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 3 2 1 4"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 3 4 1 2"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 4 2 1 3"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 4 3 1 2"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="2 3 4 5 1"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 3 5 4 1"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 4 3 5 1"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 4 5 3 1"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 5 3 4 1"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="2 5 4 3 1"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"
echo

ARG="3 2 4 5 1"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 2 5 4 1"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 4 2 5 1"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 4 5 2 1"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 5 2 4 1"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="3 5 4 2 1"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN----------------------------------------------------------------------------------------------

ARG="4 2 3 5 1"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 2 5 3 1"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 3 2 5 1"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 3 5 2 1"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 5 2 3 1"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="4 5 3 2 1"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"
echo

ARG="5 2 3 4 1"
OUTPUT1=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT1=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 2 4 3 1"
OUTPUT2=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT2=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 3 2 4 1"
OUTPUT3=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT3=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 3 4 2 1"
OUTPUT4=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT4=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 4 2 3 1"
OUTPUT5=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT5=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\t"

ARG="5 4 3 2 1"
OUTPUT6=$(./push_swap $ARG | ./checker $ARG)
NOUTPUT6=$(./push_swap $ARG | wc -l | sed 's/ //g')
let COUNTER++;
echo -ne $DEFAULT$ARG"\n"

echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT1"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT2"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT3"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT4"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT5"\t"
echo -ne $YELLOW"Status: "$DEFAULT$OUTPUT6"\t\n"


echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT1"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT2"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT3"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT4"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT5"\t"
echo -ne $YELLOW"Moves: "$GREEN$NOUTPUT6"\t\n"

echo
echo -e $DEFAULT"TESTS DONE: $COUNTER"

echo -e $CYAN----------------------------------------------------------------------------------------------
echo -e $CYAN END
echo -e $CYAN----------------------------------------------------------------------------------------------