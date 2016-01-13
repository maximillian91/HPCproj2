# !/bin/sh
#PBS -q hpcintro
#PBS -l walltime=1.00.00


GRIDN="10 20 30 40 50 100 200 300"
/bin/rm -f logs/gridtime.data

for n in $GRIDN; do
	/bin/rm -f logs/matrix-${n}.data
	program $n >> logs/matrix-${n}.data
done
echo time>>logs.time
