# knapsack-proiect-AA

Setul de teste a fost creat pentru a acoperi toate ramificațiile logice ale programării dinamice aplicate pe problema rucsacului:
Cazuri la marginea domeniului (T1, T2): Asigură stabilitatea codului la date de intrare "nule".
Teste de Logică 0/1 (T5, T7): Demonstrează că algoritmul nu poate fi păcălit de euristici simple (Greedy).
Teste de Structură (T4, T6, T8): Verifică modul în care algoritmul prioritizează obiectele când una dintre variabile (greutate sau valoare) este constantă.


Test 1: Capacitate Zero (Corner Case)
Scop: Verifică dacă programul returnează 0 când rucsacul este inexistent.
Rezultat: 0

Test 2: Obiecte prea grele (Corner Case)
Scop: Niciun obiect nu încape în rucsac
Rezultat: 0

Test 3: Toate obiectele încap (Caz Trivial)
Scop: Verifică dacă programul face suma totală corect.
Rezultat: 300

Test 4: Obiecte cu greutăți identice (Criteriul Valorii)
Scop: Forțează algoritmul să aleagă obiectul cu valoarea maximă dintr-o listă cu greutăți egale.
Rezultat: 40

Test 5: Anti-Greedy (Corectitudine 0/1)
Scop: Cel mai valoros obiect per unitate de greutate (primul) este prea mare. Optimul este ignorarea lui.
Rezultat: 40 (obiectele 2 și 3), nu 30.

Test 6: Obiecte cu valori identice (Criteriul Greutății)
Scop: Verifică dacă algoritmul alege obiectele cele mai ușoare pentru a maximiza profitul în spațiu limitat.
Rezultat: 150 (obiectele 2, 3 și 4).

Test 7: Un singur obiect dominant
Scop: Un singur obiect are o valoare imensă și ocupă tot rucsacul.
Rezultat: 1000

Test 8: Obiecte cu greutate 1 (Test de acumulare)
Scop: Verifică dacă algoritmul poate procesa multe obiecte mici care umplu rucsacul unitate cu unitate.
Rezultat: 30

Test 9: Capacitate Mare, Obiecte Puține (Eficiență Memorie)
Scop: Verifică dacă matricea DP este alocată corect pentru o capacitate mai mare.
Rezultat: 300

Test 10: Test Complex (Verificare finală)
Scop: Combinație mixtă de greutăți și valori pentru a simula un caz real.
Rezultat corect: 70

Test #,Rezultat Corect,Timp Execuție,Memorie (estimată)
T1,0,0.0001s,< 1 MB
T2,0,0.0001s,< 1 MB
T3,300,0.0001s,< 1 MB
T5,40,0.0002s,< 1 MB
T9,300,0.0015s,~4 MB
T10,70,0.0005s,< 1 MB