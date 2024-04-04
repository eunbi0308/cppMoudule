#!/bin/bash

PURPLE='\033[38;2;200;160;255m'
GREEN='\033[1;32m'
NC='\033[0m'

###########################################
echo -e "${GREEN}- BASIC TESTS -${NC}"

echo -e "${PURPLE}input: 0${NC}"
./convert 0
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 42.0f${NC}"
./convert 42.0f
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 0.0000000${NC}"
./convert 0.00000000
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 10.0${NC}"
./convert 10.0
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 1000${NC}"
./convert 1000
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -42.0${NC}"
./convert -42.0
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 12.3456789123456${NC}"
./convert 12.3456789123456
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -12.3456789123456${NC}"
./convert -12.3456789123456
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 11111111${NC}"
./convert 11111111
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 111111${NC}"
./convert 111111
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -0${NC}"
./convert -0
echo ""

read -p "Press enter to continue"

###########################################
echo -e "${GREEN}- SINGLE CHARACTER -${NC}"

echo -e "${PURPLE}input: *${NC}"
./convert '*'
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: a${NC}"
./convert a
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -${NC}"
./convert '-'
echo ""

read -p "Press enter to continue"

###########################################
echo -e "${GREEN}- MAX/MIN INTEGER -${NC}"

echo -e "${PURPLE}input: 2147483647${NC}"
./convert 2147483647
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -2147483648${NC}"
./convert -2147483648
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 2147483647.000000${NC}"
./convert 2147483647
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -2147483648.000000${NC}"
./convert -2147483648
echo ""

read -p "Press enter to continue"

###########################################
echo -e "${GREEN}- OUT OF RANGE -${NC}"

echo -e "${PURPLE}input: 1111111111111${NC}"
./convert 1111111111111
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 111111111111111111111111111111111111111111111111111111111${NC}"
./convert 11111111111111111111111111111111111111111111111111111111
echo ""

read -p "Press enter to continue"

###########################################
echo -e "${GREEN}- INVALID INPUT -${NC}"

echo -e "${PURPLE}input: f${NC}"
./convert f
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 42.0fq${NC}"
./convert 42.0fq
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: test${NC}"
./convert test
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: 10.ewrewrf${NC}"
./convert 10.ewrewrf
echo ""

read -p "Press enter to continue"

###########################################
echo -e "${GREEN}- PSEUDO LITERALS -${NC}"

echo -e "${PURPLE}input: nan${NC}"
./convert nan
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: nanf${NC}"
./convert nanf
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: inf${NC}"
./convert inf
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: +inf${NC}"
./convert +inf
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -inf${NC}"
./convert -inf
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: inff${NC}"
./convert inff
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: +inff${NC}"
./convert +inff
echo ""

read -p "Press enter to continue"

echo -e "${PURPLE}input: -inff${NC}"
./convert -inff
echo ""

