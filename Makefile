CC = gcc
CFLAGS = -Wall -O2

EXEC = greedy backtracking dp
# Listăm testele manual pentru a asigura ordinea 1, 2, 3... 10
TESTS = tests/test1.txt tests/test2.txt tests/test3.txt tests/test4.txt tests/test5.txt \
        tests/test6.txt tests/test7.txt tests/test8.txt tests/test9.txt tests/test10.txt
OUTPUT_DIR = output

.PHONY: all run clean

all: $(EXEC) run

greedy: Greedy.c
	$(CC) $(CFLAGS) Greedy.c -o greedy

backtracking: Backtracking.c
	$(CC) $(CFLAGS) Backtracking.c -o backtracking

dp: PD.c
	$(CC) $(CFLAGS) PD.c -o dp
    
run: $(EXEC)
	@mkdir -p $(OUTPUT_DIR)
	@echo "--- RAPORT COMPLET (TOATE CELE 10 TESTE) ---" > $(OUTPUT_DIR)/raport_total.txt
	
	@for test in $(TESTS); do \
		echo "\n----------------------------------------" >> $(OUTPUT_DIR)/raport_total.txt; \
		echo "PROCESARE: $$test" >> $(OUTPUT_DIR)/raport_total.txt; \
		echo "----------------------------------------" >> $(OUTPUT_DIR)/raport_total.txt; \
		\
		echo -n "Greedy: " >> $(OUTPUT_DIR)/raport_total.txt; \
		./greedy $$test tmp.txt && head -n 1 tmp.txt >> $(OUTPUT_DIR)/raport_total.txt; \
		\
		echo -n "DP (Optim): " >> $(OUTPUT_DIR)/raport_total.txt; \
		./dp $$test tmp.txt && head -n 1 tmp.txt >> $(OUTPUT_DIR)/raport_total.txt; \
		\
		NUM_LINES=$$(wc -l < $$test); \
		if [ $$NUM_LINES -lt 25 ]; then \
			echo -n "Backtracking: " >> $(OUTPUT_DIR)/raport_total.txt; \
			./backtracking $$test tmp.txt && head -n 1 tmp.txt >> $(OUTPUT_DIR)/raport_total.txt; \
		else \
			echo "Backtracking: SARE (Test prea mare, ar dura prea mult)" >> $(OUTPUT_DIR)/raport_total.txt; \
		fi; \
	done
	@rm -f tmp.txt
	@echo "\nGata! Verifica raportul cu: cat output/raport_total.txt"

clean:
	rm -f $(EXEC)
	rm -rf $(OUTPUT_DIR)