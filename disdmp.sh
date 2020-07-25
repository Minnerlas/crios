#!/bin/sh

objdump -b binary --adjust-vma=$1 -m i386:x86-64 -D *.dmp | less
