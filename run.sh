#!/bin/bash
set -e
while true
do
service xcp-rrdd-gpumon start >> run.log 2>&1
a=`pidof xcp-rrdd-gpumon`
#echo $a
strace -q -tt -T -f -p $a >> run.log 2>&1 &
sleep ${RANDOM:0:1}
service xcp-rrdd-gpumon stop >> run.log 2>&1
done

