build:
	gcc cerinte/cerinta_1.c cerinte/cerinta_2.c -o lanParty
	./lanParty date/t1/d.in out/out1.out date/t2/d.in out/out2.out date/t3/d.in out/out3.out
clean:
	rm -f lanParty
