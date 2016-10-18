#!/usr/bin/bash

usage()
{
    echo "usage: $0"
    exit 1
}


if [ $# -ne 0 ]
then
    usage
else
    cat passwd | grep -v /bin/bash | grep -E ^[aeiouy]
fi
