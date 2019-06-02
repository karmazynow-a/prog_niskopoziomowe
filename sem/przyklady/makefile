SUBDIRS := ./przyklad1 ./przyklad2 ./przyklad3 ./przyklad4 ./przyklad5
FILES := $(wildcard $(D)/*.cpp $(D)/*.h $(D)/*.c)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

cleanall:
	for dir in $(SUBDIRS); do \
    	$(MAKE) clean -C $$dir; \
    done

clean:
	$(MAKE) clean -C $(D)

run:
	$(MAKE) run -C $(D)

.PHONY: all $(SUBDIRS) cleanall clean