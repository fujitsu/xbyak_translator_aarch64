TP_PATTERNS=$(shell find pattern -name "*.cpp")
TP_RESULTS=$(TP_PATTERNS:.cpp=.result)
USER_NAME=$(shell whoami)


.SUFFIXES: .cpp .result

all:all_result

.cpp.result:
	# Generate "(pattern_name).jit_x86_64.exec_x86_64.(user_name).check.log" in "/tmp" directory
	./test2.sh -x -X -E $<
	# Generate "(pattern_name).jit_aarch64.exec_aarch64.(user_name).check.log" in "/tmp" directory
	./test2.sh -a -A -E $<

	diff -y -W 300 /tmp/$(basename $(notdir $<)).jit_x86_64.exec_x86_64.$(USER_NAME).check.log /tmp/$(basename $(notdir $<)).jit_aarch64.exec_aarch64.$(USER_NAME).check.log > $@
	# IF return value of diff is 0, then append text "OK congratulation" to $@, else, append text "NG it seems to have a little difference." to $@

all_result:$(TP_RESULTS)
	# Summrize $(TP_RESULTS)
	# grep OK ${TP_RESULTS) > regression_result.txt

clean_result:
	find pattern -name "*.result" -exec rm {} \;

clean:
	rm *.log *.bin *.asm
