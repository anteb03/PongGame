Project: Pong Game

1. Opis: 

- Pong Game je klasična arkadna igra, slična sportu "Stolni tenis". 
- Cilj ove igre je odbiti lopticu koristeći virtualne "rekete" i spriječiti da loptica dodirne rub ekrana iza igrača. 
- U slučaju da igrač ne uspije odbiti loptu, protivnik dobija bod. 
- U našem slučaju, korisnik igra protiv "CPU".

2. Instalacija i postavljanje projekta: 

2.1. Instalacija Visual Studio-a:
- Posjeti ovu stranicu za preuzimanje Visual Studio-a: https://visualstudio.microsoft.com/downloads/ 
- Preuzmi i instaliraj odgovarajuću verziju za tvoj operativni sustav.
- Kreiraj novi empty project i spremi na odgovarajuce mjesto na racunalu.

2.2. Preuzimanje Raylib biblioteke: (ukoliko imas 64 bitni uređaj, onda netreba preuzimanje jer je ima u ovom repositoryju)
- Posjeti Raylib na GitHub-u: https://github.com/raysan5/raylib/releases/tag/5.0 
- Na dnu stanice, u sekciji "Assets", odaberi raylib-5.0_win32_msvc16.zip ili raylib-5.0_win64_msvc16.zip ovisno o vrsti operativnog sustava koji koristiš
- Preuzmi i raspakiraj zip datoteku.
 
- Sada možeš klonirati projekt (ili pojedine fileove). 

2.3. Postavljanje projekta: 
- Izbrisati Raylib mapu i staviti raspakiranu. (ako je prethodno instliran novi Raylib library)
- Otvoriti kreirani projekt.
- Prilikom pokretanja trebao bi se prikazati prozor Solution Explorer - zatim desna tipka na "Ime projekta" -> Properties
- Zatim stinsuti C/C++ -> General i u polje Additional Include Directories postaviti lokaciju do mape include unutar Raylib mape
- Zatim stisnuti Linker -> General i u polje Additional Library Directories postaviti lokaciju do mape lib unutar Raylib mape
- Zatim stisnuti Linker -> Input i u polje Additional Dependencies staviti raylib.lib i winmm.lib
- Stisnuti apply i izaći.
- Nakon toga promjeniti vrstu debugginga (solution platform) sa x64 na x86.

- Ukoliko neki od postupaka nije jasan možete pogledati ovaj video: https://youtube.com/shorts/q0gxwjBSmX4?si=cYwdccmEoVUiVfuO 

3. Dokumentacija:

3.1. Struktura koda: 
- Korištenje Raylib biblioteke
- Organizacija i podjela koda po datotekama, korištenje header fileova
- Korištenje STL, klasi, nasljeđivanje 

3.1.1. main.cpp: 
- Inicijalizacija prozora i postavki igre
- Glavna petlja igre (game loop) za ažuriranje stanja igre i prikaz na ekranu
- Pozivi funkcija za crtanje objekata, obradu korisničkih ulaza i logiku igre
- Prekid igre pri dostizanju određenog rezultata

3.1.2. ball.cpp i ball.hpp:
- ball.hpp sadrži deklaraciju klase, funkcija, i varijabli(privatne clanovi klase; x i y pozicija loptice, brzina po x i y i smjer kretanja po x i y )
- ball.cpp sadrži implemetaciju deklaracija: funkcija(kretanje, ispisivanje, resetiranje i dobivanje vrijednosti privatnih clanova klase)

3.1.3 players.cpp i players.hpp:
- players.hpp sadrži deklaraciju klasa, funkcija, i varijabli(pozicija plocice po x i y, boja i brzina kretanja); bazna klasa "reket" koju nasljeduju igrač i "CPU"
- players.cpp sadrži implementaciju deklaracija: funkcija(kretanje,ispisivanje,dobivanje vrijednosti protected clanova klase)

3.2. Funkcionalnosti:
- Igrački mehanizam; kontrole, kretanje igrača i "CPU", kretanje lotice, odbijanje od "reketa", računanje rezultata, ispis pobjednika i prekid igre
- GUI; grafički prikaz korisničkog sučelja(igračih konzola, kontroli, informacija)


4. Problemi tijekom izrade: 
- Detekcija sudara; problemi s preciznošću detekcije sudara između loptice i pločica
- "CPU" za protivnika; teškoće u implementaciji pametnog "CPU" protivnika
- Optimizacija performansi; poteškoće u postizanju glatke igre bez trzanja ili usporavanja

5. Moguća poboljšanja: 
- Resetiranje pozicije "reketa" na početnu poziciju
- Dodatne funkcionalnosti za kretanje "CPU" (različiti modovi težine protivnika)
- Grafička poboljšanja; implementacija bolje grafike, animacija ili dodatnih efekata
