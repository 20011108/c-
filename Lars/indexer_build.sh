#!/bin/bash

INDEX=/home/itheima/.indexer_files

echo "please make sure you are in your project dir"
read -n 1 -p "only (Y/y) means sure:  " sure
echo ""
case ${sure} in
    y|Y) ;;

    *) exit ;;
esac

echo "building..."

path=$(pwd)
prj=$(basename ${path})

$(grep ${prj} ${INDEX} -q)
if [ $? -eq 0 ]
then
    echo "already added in ${INDEX}"
else
    echo "" >> ${INDEX}
    echo "[${prj}]">> ${INDEX}
    echo ${path} >> ${INDEX}
fi
