exec:
	@make pulse_exec

pulse_exec: pulse.c
	@gcc -std=c99 -lm -o pulse pulse.c
