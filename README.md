# Objektinis_antras_projektas

***v2.0***


+ Yra įkeltas programos html aplankalas, kurį pasileidus galima apžiūrėti programos sudėtį naudotojui aiškesniu būdu.
+ Faile *test.cpp* yra programos realizuotas unit testingas, kuris realizuotas pridėjus *cath.hpp* biblioteką.
+ Sukurtas automatinis įdiegimo failas.

+ Naudojimosi instrukcija:
  + Parsisiųsti ProgramInstallSetup aplanką.
  + Nukeliatit į programos setup direktoriją. (ProgramInstallSetup\Debug)
  + Pasileisti *setup.exe*
  + Instaliuoti į norimą direktoriją ir tada paleisti programą.

<br />
<br />


***v1.5***


+ Pridėta *zmogus* abstrakti klasė.

<br />
<br />

***v1.2***


+ Patobulinta klasė, kuri turi copy ir move konstrutkroius.  
+ Pridėta friend funcija operatoriui.

<br />
<br />

***v1.1***

+ Atveju su struktūromis (vektoriai) su 100000 ir 1000000 studentų programa užima 376 KB.
+ Atveju su klasėmis (vektoriai) (su o1 flag'u) su 100000 ir 1000000 studentų programa užima 211 KB.
+ Atveju su klasėmis (vektoriai) (su o2 flag'u) su 100000 ir 1000000 studentų programa užima 206 KB.
+ Atveju su klasėmis (vektoriai) (su o3 flag'u) su 100000 ir 1000000 studentų programa užima 217 KB.



struct vector:
|             	| 1000         	| 10 000       	| 100 000      	| 1 000 000   	| 10 000 000  	|
|-------------	|--------------	|--------------	|--------------	|-------------	|-------------	|
| Nuskaitymas 	| 0.008236     	| 0.077006     	| 0.673858     	| 6.63382     	| 69.9389     	|
| Sort'as     	| 0.000654     	| 0.008513     	| 0.09855      	| 1.24026     	| 15.4836     	|
| Grupavimas  	| 0.000182     	| 0.001359     	| 0.014359     	| 0.158501    	| 2.11855     	|
| **Iš viso** 	| **0.009072** 	| **0.001359** 	| **0.786767** 	| **8.03259** 	| **87.5411** 	|


class vector

|             	| 1000         	| 10 000      	| 100 000      	| 1 000 000   	| 10 000 000  	|
|-------------	|--------------	|-------------	|--------------	|-------------	|-------------	|
| Nuskaitymas 	| 0.007831     	| 0.061897    	| 0.5979       	| 5.9219      	| 59.8965     	|
| Sort'as     	| 0.000138     	| 0.001987    	| 0.024868     	| 0.274566    	| 3.4163      	|
| Grupavimas  	| 0            	| 0.000006    	| 0.000103     	| 0.004971    	| 0.043562    	|
| **Iš viso** 	| **0.007969** 	| **0.06389** 	| **0.622871** 	| **6.20143** 	| **63.3564** 	|

Su o1 flag'u

|             	| 1000         	| 10 000       	| 100 000      	| 1 000 000   	| 10 000 000  	|
|-------------	|--------------	|--------------	|--------------	|-------------	|-------------	|
| Nuskaitymas 	| 0.008236     	| 0.077006     	| 0.673858     	| 6.63382     	| 69.9389     	|
| Sort'as     	| 0.000654     	| 0.008513     	| 0.09855      	| 1.24026     	| 15.4836     	|
| Grupavimas  	| 0.000182     	| 0.001359     	| 0.014359     	| 0.158501    	| 2.11855     	|
| **Iš viso** 	| **0.009072** 	| **0.001359** 	| **0.786767** 	| **8.03259** 	| **87.5411** 	|

su o2 flag'u

|             	| 1000         	| 10 000       	| 100 000      	| 1 000 000   	| 10 000 000  	|
|-------------	|--------------	|--------------	|--------------	|-------------	|-------------	|
| Nuskaitymas 	| 0.007175     	| 0.061218     	| 0.592073     	| 5.90062     	| 59.5689     	|
| Sort'as     	| 0.000146     	| 0.002016     	| 0.024561     	| 0.276221    	| 3.46585     	|
| Grupavimas  	| 0.000001     	| 0.000007     	| 0.00009      	| 0.005081    	| 0.046667    	|
| **Iš viso** 	| **0.007322** 	| **0.063241** 	| **0.616724** 	| **6.18192** 	| **63.0815** 	|

su 03 flag'u

|             	| 1000         	| 10 000      	| 100 000      	| 1 000 000   	| 10 000 000  	|
|-------------	|--------------	|-------------	|--------------	|-------------	|-------------	|
| Nuskaitymas 	| 0.007831     	| 0.061897    	| 0.5979       	| 5.9219      	| 59.8965     	|
| Sort'as     	| 0.000138     	| 0.001987    	| 0.024868     	| 0.274566    	| 3.4163      	|
| Grupavimas  	| 0            	| 0.000006    	| 0.000103     	| 0.004971    	| 0.043562    	|
| **Iš viso** 	| **0.007969** 	| **0.06389** 	| **0.622871** 	| **6.20143** 	| **63.3564** 	|

+ **Naudojimosi instrukcija**:
  + Instaliuotis terminilą su *git bash*.
  + Instaliuotis *mingw* bei *make*.
  + Įsijungti *Git bash* ir nueiti su *cd* į projekto folder'į su kodu.
  + Į komandinę eilutę įvesti *make*, po to kad paleisti programą *./main.exe*.



<br />
<br />

***v1.0***

+ Grupavimo trukmė su skirtingomis strategijomis ir konteineriais.

Grupavimas su vector:
|                            	| 1000     	| 10 000   	| 100 000  	| 1 000 000 	| 10 000 000 	|
|----------------------------	|----------	|----------	|----------	|-----------	|------------	|
| 1 strategija               	| 0.000327 	| 0.003722 	| 0.034016 	| 0.348033  	| 3.94183    	|
| 2 strategija               	| 0.022993 	| 2.3102   	| 229.912  	| -         	| -          	|
| 2 strategija (optimizuota) 	| 0.000178 	| 0.001309 	| 0.01441  	| 0.157643  	| 1.95531    	|

Grupavimas su deque:
|                            	| 1000     	| 10 000   	| 100 000  	| 1 000 000 	| 10 000 000 	|
|----------------------------	|----------	|----------	|----------	|-----------	|------------	|
| 1 strategija               	| 0.000671 	| 0.006109 	| 0.065554 	| 0.681644  	| 30.7498    	|
| 2 strategija               	| 0.000397 	| 0.003656 	| 0.04507  	| 0.519973  	| 6.86625    	|
| 2 strategija (optimizuota) 	| 0.00059  	| 0.004427 	| 0.051361 	| 0.571559  	| 25.7473    	|

Grupavimas su list:

|                            	| 1000     	| 10 000   	| 100 000  	| 1 000 000 	| 10 000 000 	|
|----------------------------	|----------	|----------	|----------	|-----------	|------------	|
| 1 strategija               	| 0.001969 	| 0.018113 	| 0.214459 	| 2.52226   	| 26.2256    	|
| 2 strategija               	| 0.001381 	| 0.013322 	| 0.150915 	| 1.65681   	| 18.6315    	|
| 2 strategija (optimizuota) 	| 0.000528 	| 0.007315 	| 0.091193 	| 1.07711   	| 13.6868    	|


+ **Naudojimosi instrukcija**:
  + Instaliuotis terminilą su *git bash*.
  + Instaliuotis *mingw* bei *make*.
  + Įsijungti *Git bash* ir nueiti su *cd* į projekto folder'į su kodu.
  + Į komandinę eilutę įvesti norimą komandą:
    + *make vector* kompiliuoja ir paleidžia kodą su vector tipo konteineriu.
    + *make deque* kompiliuoja ir paleidžia kodą su deque tipo konteineriu.
    + *make list* kompiliuoja ir paleidžia kodą su list tipo konteineriu.

<br />
<br />

***v0.5***
+ Pridėtas kodas, kuris naudoja *deque* tipo konteinerį vietoj *vector*.
+ Pridėtas kodas, kuris naudoja *list* tipo konteinerį vietoj *vector*.
+ Pridėtas įvairių programos procesų veikimo laikas, kuris yra matomas apačioje lenetlės pavidalu su *vector*, *deque*, *list* tipo konteineriais.

Vector:

|             	| 1000     	| 10 000   	| 100 000  	| 1 000 000 	| 10 000 000 	|
|-------------	|----------	|----------	|----------	|-----------	|------------	|
| Nuskaitymas 	| 0.006533 	| 0.056995 	| 0.552395 	| 5.49003   	| 55.3696    	|
| Rūšiavimas  	| 0.000112 	| 0.001073 	| 0.012968 	| 0.172484  	| 2.18111    	|
| Grupavimas  	| 0.000183 	| 0.001625 	| 0.019355 	| 0.210891  	| 2.51844    	|

Deque:

|             	| 1000     	| 10 000   	| 100 000  	| 1 000 000 	| 10 000 000 	|
|-------------	|----------	|----------	|----------	|-----------	|------------	|
| Nuskaitymas 	| 0.00664  	| 0.056811 	| 0.554563 	| 5.50413   	| 58.6558    	|
| Rūšiavimas  	| 0.000476 	| 0.005604 	| 0.076834 	| 1.07119   	| 14.0064    	|
| Grupavimas  	| 0.000426 	| 0.003721 	| 0.041214 	| 0.438361  	| 31.0137    	|

List:

|             	| 1000     	| 10 000   	| 100 000  	| 1 000 000 	| 10 000 000 	|
|-------------	|----------	|----------	|----------	|-----------	|------------	|
| Nuskaitymas 	| 0.008188 	| 0.067202 	| 0.656576 	| 6.51919   	| 66.1506    	|
| Rūšiavimas  	| 0.000094 	| 0.001106 	| 0.016726 	| 0.464297  	| 8.88744    	|
| Grupavimas  	| 0.000752 	| 0.007832 	| 0.122866 	| 1.36547   	| 18.1952    	|

***Sistemos parametrai su kuriais buvo pateikti testavimų duomenys***
+ ***CPU:*** AMD Ryzen 5 3600 6-Core Processor, 3600 Mhz, 6 Core(s), 12 Logical Processor(s)
+ ***RAM:*** 16GB
+ ***SSD:*** Kingston SA2000M8 1TB NVMe, (Read/Write) 2,200/2,000MB/s.


<br />
<br />

***v0.4***
+ Pridėta funkcija *gen_file*, kuri generuoja failą su duomenimis.
+ Pridėta funcija *write_to_file*, kuri surūšiuoja duomenis ir priskiria studentą į ***kietiakai.txt*** arba ***vargsiukai.txt*** pagal studneto vidurkį.
+ Pridėtas įvairių programos procesų veikimo laikas, kuris yra matomas apačioje lenetlės pavidalu.


|                     	| 1000     	| 10 000   	| 100 000  	| 1 000 000 	| 10 000 000 	|
|---------------------	|----------	|----------	|----------	|-----------	|------------	|
| Nuskaitymas         	| 0.007238 	| 0.057681 	| 0.57259  	| 5.60828   	| 56.4872    	|
| Rūšiavimas          	| 0.000335 	| 0.003109 	| 0.029556 	| 0.313585  	| 4.03375    	|
| Spausdinimas (kiet) 	| 0.000357 	| 0.00269  	| 0.026719 	| 0.274681  	| 2.66694    	|
| Spausdinimas (varg) 	| 0.000288 	| 0.002639 	| 0.026852 	| 0.266558  	| 2.68626    	|
| Iš viso             	| 0.008218 	| 0.066119 	| 0.655717 	| 6.4631    	| 65.8742    	|

<br />
<br />

***v0.3***

+ Pridėti exception'ai, kurie patikrina ar skaitomas failas nėra tuščias arba neegzistuojantis.
+ Programoje naudojamos funkcijos yra perkeltos į atskirą .cpp failą.
+ **Mylib.h** yra papildytas naudojamų funkcijų antraštėmis ir struktūra.

<br />
<br />

***v0.2***

+  Pridėta funkcija '*bufer_nusk'*, kuri atidaro pasirinktą failą ir perkelia duomenis į buferį iš kurio nuskaito duomenis į struktūrą, apksaičiuoja*'Galutinis (Vid.)'* bei  studento *'Galutinis (Med.)'* pažymius, kuriuos išveda į kitą failą jau surušiuotus pagal vardus.

<br />
<br />

***v0.1*** (su C stiliaus masyvais ir vektoriais)

Su C stiliaus masyvais:
+  Turi struktūrą '*studentas*'.
+  Funkcijoje *'pild'* suvedami duomenys apie namų darbų ir egzamino pažymius. Šioje funkcijoje atliekami galimų įvedimo klaidų šalinimas.
+  Funkcija *'gal'* apskaičiuoja ir grąžina studento *'Galutinis (Vid.)'* pažymį.
+  Funkcija *'med'* apskaičiuoja ir grąžina studento *'Galutinis (Med.)'* pažymį.
+  Funkcija *'spausd'* išveda duomenis.


Su vektoriais:
+  Turi struktūrą '*studentas*'.
+  Funkcijoje *'pild'* suvedami duomenys apie namų darbų ir egzamino pažymius. Šioje funkcijoje atliekami galimų įvedimo klaidų šalinimas. 
+  Funkcija *'spausd'* apskaičiuoja studento *'Galutinis (Vid.)'* bei apskaičiuoja studento *'Galutinis (Med.)'* pažymius. Taip pat išvedami duomenys.
