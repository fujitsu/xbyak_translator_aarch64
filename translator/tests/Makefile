#TP_PATTERNS=$(shell find pattern -name "*.cpp")
TP_PATTERNS=pattern/mov/mov000.cpp
TP_RESULTS=$(TP_PATTERNS:.cpp=.result)
USER_NAME=$(shell whoami)
FILE_REGRESSION="regression_result.txt"

.SUFFIXES: .cpp .check .result

all:all_result

.cpp.check:
	# Generate "(pattern_name).jit_x86_64.exec_x86_64.(user_name).check.log" in "/tmp" directory
	./test4.sh -x -X -E $<
	# Generate "(pattern_name).jit_aarch64.exec_aarch64.(user_name).check.log" in "/tmp" directory
	./test4.sh -a -A -E $<
	$(eval TP_TMP_NAME := $(basename $(notdir $<)))
	# Note:Intermediate result file is automatically removed by make.
	diff -y -W 300 /tmp/$(TP_TMP_NAME).jit_x86_64.exec_x86_64.$(USER_NAME).check.log /tmp/$(TP_TMP_NAME).jit_aarch64.exec_aarch64.$(USER_NAME).check.log > $@

.check.result:
	$(eval TP_TMP_NAME := $(basename $(notdir $<)))
	$(eval LINE_NUM := $(shell wc -l $< | cut -f 1 -d " "))
	$(eval DIFF_LINE_NUM := $(shell grep "|" $< | wc -l | cut -f 1 -d " "))
	if [ "$(LINE_NUM)" = 80 -a "$(DIFF_LINE_NUM)" = 0 ] ; then echo "$(TP_TMP_NAME):OK" > $@ ; else echo "$TP_TMP_NAME):NG" > $@ ; fi

all_result:$(TP_RESULTS)
	grep OK $(TP_RESULTS) > $(FILE_REGRESSION)
	grep NG $(TP_RESULTS) >> $(FILE_REGRESSION)
	sort $(FILE_REGRESSION) $(FILE_REGRESSION).tmp
	mv $(FILE_REGRESSION).tmp $(FILE_REGRESSION)

clean_check:
	find pattern -name "*.check" -exec rm {} \;

clean_result:
	find pattern -name "*.result" -exec rm {} \;

clean:
	rm *.log *.bin *.asm
