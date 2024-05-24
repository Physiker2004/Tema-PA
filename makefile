build:
	gcc cerinte/cerinta_1.c cerinte/cerinta_2.c cerinte/cerinta_3.c -o lanParty
	./lanParty date/t1/d.in out/out1.out date/t2/d.in out/out2.out date/t3/d.in out/out3.out date/t4/d.in out/out4.out date/t5/d.in out/out5.out date/t6/d.in out/out6.out date/t7/d.in out/out7.out date/t8/d.in out/out8.out date/t9/d.in out/out9.out 
clean:
	rm -f lanParty
