# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    casse.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 11:13:46 by gly               #+#    #+#              #
#    Updated: 2018/07/25 15:28:09 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cutable=./init

echo "BRISAGE BEGINS"

echo "\n\n\nıllıllı Test 00 ıllıllı"
echo "Input normal"
echo "EXPECTED RESULT: SOLVE"
$cutable test_map/dab00.txt

echo "\n\n\nıllıllı Test 01 ıllıllı"
echo "Input line shorter than actual map"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab01.txt

echo "\n\n\nıllıllı Test 02 ıllıllı"
echo "Input line longer than actual map"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab02.txt

echo "\n\n\nıllıllı Test 03 ıllıllı"
echo "Map filled with obstacle"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab03.txt

echo "\n\n\nıllıllı Test 04 ıllıllı"
echo "Map with no obstacle"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab04.txt

echo "\n\n\nıllıllı Test 05 ıllıllı"
echo "Map with some holes"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab05.txt

echo "\n\n\nıllıllı Test 06 ıllıllı"
echo "Map with no line"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab06.txt

echo "\n\n\nıllıllı Test 07 ıllıllı"
echo "Empty file"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab07.txt

echo "\n\n\nıllıllı Test 07 bis ıllıllı"
echo "File with only \\\\n"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab07bis.txt

echo "\n\n\nıllıllı Test 08 ıllıllı"
echo "Map with 1 empty square"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab08.txt

echo "\n\n\nıllıllı Test 09 ıllıllı"
echo "Map with 1 obs square"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab09.txt

echo "\n\n\nıllıllı Test 10 ıllıllı"
echo "Map with 1 fill square"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab10.txt

echo "\n\n\nıllıllı Test 11 ıllıllı"
echo "Map with varying line length"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab11.txt

echo "\n\n\nıllıllı Test 12 ıllıllı"
echo "Map erroneous first line n1"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab12.txt

echo "\n\n\nıllıllı Test 13 ıllıllı"
echo "Map erroneous first line n2"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab13.txt

echo "\n\n\nıllıllı Test 14 ıllıllı"
echo "Map erroneous first line n3"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab14.txt

echo "\n\n\nıllıllı Test 15 ıllıllı"
echo "Map erroneous first line n4"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab15.txt

echo "\n\n\nıllıllı Test 16 ıllıllı"
echo "Map erroneous first line n5"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab16.txt

echo "\n\n\nıllıllı Test 17 ıllıllı"
echo "Map with a square already"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab17.txt

echo "\n\n\nıllıllı Test 18 ıllıllı"
echo "Map with 0 column"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab18.txt

echo "\n\n\nıllıllı Test 19 ıllıllı"
echo "Map with other characters"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab19.txt

echo "\n\n\nıllıllı Test 20 ıllıllı"
echo "Map with same character for obs and empty"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab20.txt

echo "\n\n\nıllıllı Test 21 ıllıllı"
echo "Map with same character for obs and fill"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab21.txt

echo "\n\n\nıllıllı Test 22 ıllıllı"
echo "Map with same character for fill and empty"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab22.txt

echo "\n\n\nıllıllı Test 23 ıllıllı"
echo "Map with numbers as character"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab23.txt

echo "\n\n\nıllıllı Test 24 ıllıllı"
echo "Map with 1 column"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab24.txt

echo "\n\n\nıllıllı Test 25 ıllıllı"
echo "Map with 1 row"
echo "EXPECTED RESULT: SOLVED"
$cutable test_map/dab25.txt

echo "\n\n\nıllıllı Test 26 ıllıllı"
echo "Map with two \\\\n at the end"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab26.txt

echo "\n\n\nıllıllı Test 27 ıllıllı"
echo "Map with a \\\\0"
echo "EXPECTED RESULT: MAP ERROR"
$cutable test_map/dab27.txt

echo "\n\n\nıllıllı Test 28 ıllıllı"
echo "Two valid maps"
echo "EXPECTED RESULT: SOLVED && SOLVED"
$cutable test_map/dab00.txt test_map/dab23.txt

echo "\n\n\nıllıllı Test 29 ıllıllı"
echo "A valid map then an invalid map"
echo "EXPECTED RESULT: SOLVED && MAP ERROR"
$cutable test_map/dab23.txt test_map/dab17.txt

echo "\n\n\nıllıllı Test 30 ıllıllı"
echo "An invalid map then a valid map"
echo "EXPECTED RESULT: MAP ERROR && SOLVED"
$cutable test_map/dab17.txt test_map/dab23.txt

