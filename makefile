build:
	gcc cerinte/cerinta_1.c -o lanParty
	./lanParty d.in out/out1.out
clean:
	rm -f lanParty
