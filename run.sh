while true
do
service xcp-rrdd-gpumon start
[ $? -ne 0 ] && exit $?
sleep 2
#perl -e 'select(undef,undef,undef,.3)'
service xcp-rrdd-gpumon stop
[ $? -ne 0 ] && exit $?
perl -e 'select(undef,undef,undef,.3)'
done
