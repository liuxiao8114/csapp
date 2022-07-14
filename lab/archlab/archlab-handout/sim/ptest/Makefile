SIM=../pipe/psim
TFLAGS=

ISADIR = ../misc
YAS=$(ISADIR)/yas

.SUFFIXES: .ys .yo

.ys.yo:
	$(YAS) $*.ys

test:
	perl ./optest.pl -s $(SIM) $(TFLAGS)
	perl ./jtest.pl -s $(SIM) $(TFLAGS)
	perl ./ctest.pl -s $(SIM) $(TFLAGS)
	perl ./htest.pl -s $(SIM) $(TFLAGS)

clean:
	rm -f *.o *~ *.yo *.ys
