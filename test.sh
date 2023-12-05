#!/bin/bash

make re

for file in tests/AbstractTests/*.avm
do
    echo -e "\e[36;1m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\e[0m"
    ./abstractVM $file &> output

    return_value=$?

    if [ $return_value -eq 84 ]
    then
        head -n 1 $file.expected > tmp
        sed -i 's/Return: //' tmp
        echo $return_value > tmp2
        diff tmp2 tmp &> diff
        if [ $? -eq 0 ]
        then
            echo -e "\e[32m$file: Return OK\e[0m"
            cat output
            echo -e "\e[0m"
        else
            echo -e "\e[31m$file: Return KO\e[0m"
            cat output
            echo -e "\e[0m\nDifferences:\e[0m"
            cat diff
            echo -e "\e[0m"
        fi
        echo -e "\e[36;1m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\e[0m"
        continue
    fi

    echo -e "Return: $return_value\n$(cat output)" > fil
    diff fil $file.expected &> diff

    if [ $? -eq 0 ] && [ $return_value -eq 0 ]
    then
        echo -e "\e[32m$file: Dump OK\e[0m"
        cat output
        echo -e "\e[0m"
    else
        echo -e "\e[31m$file: Dump KO\e[0m"
        cat output
        echo -e "\e[0m\nDifferences:\e[0m"
        cat diff
        echo -e "\e[0m"
    fi
    echo -e "\e[36;1m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\e[0m"
done

rm -f output
rm -f diff
rm -f fil
rm -f tmp
rm -f tmp2