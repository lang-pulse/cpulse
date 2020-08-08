exec:
	@make pulse_exec

pulse_exec: src/global_helpers.c pulse.c
	@gcc -std=c99 -lm -o pulse src/global_helpers.c pulse.c
