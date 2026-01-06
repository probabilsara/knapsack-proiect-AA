# knapsack-proiect-AA

Testul 1: Verificarea Corectitudinii (Sanity Check)
Scop: Verificarea logicii pe o instanță mică.
Rezultat așteptat: Valoare 90. (Se aleg obiectele cu indicii 2 și 4).

Testul 2: Capacitate Insuficientă (Edge Case)
Scop: Verificarea rucsacului în care nu încape nimic. 
Rezultat așteptat: Valoare 0. (Niciun obiect nu poate fi ales).

Testul 3: Capacitate Excedentară (Edge Case)
Scop: Verificarea rucsacului în care încap toate obiectele.
Rezultat așteptat: Valoare 280. (Se aleg toate obiectele).

Testul 4: Capcana Greedy (Euristică vs Exact)
Scop: Testarea unui caz unde raportul valoare/greutate mare induce în eroare algoritmii simpli. 
Rezultat așteptat: Valoare 60. (Se aleg obiectele 2 și 3. Algoritmul Greedy simplu l-ar alege doar pe primul, obținând doar 40).

Testul 5: Obiecte Identice
Scop: Verificarea comportamentului când obiectele au aceleași valori.
Rezultat așteptat: Valoare 20. (Se aleg oricare două obiecte).