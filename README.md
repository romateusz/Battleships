# Battleships

30.04.2024
WINDOWS version
-------------------
## Autor
Mateusz Roman
-----------------
## Kompilacja gry statki
Grę należy kompilować w standardzie conajmniej -std=c++20.

W folderze z plikami gry wpisać następujące polecenie do terminala:
>> g++ -o bs.exe battleship.cpp terminal.cpp

Grę można uruchomić za pomocą polecenia:
>> ./bs.exe

Od Autora:
Podczas grania w grę postępuj zgodnie z podpowiedziami przedstawionymi na ekranie!
---------------------
## Gra
Gra rozpoczyna się od podania nickname'u gracza.
Następnie należy podać rozmiar kwadratowej planszy o krawędzi o wymiarze od 6 do 16.
Wygenerują się wówczas dwie plansze. Po lewej stronie znajduje się plansza gracza, a po prawej stronie plansza AI.

Rozpocznie się faza gry: "Ustawiania statków".
Poniżej zobaczyć można następujący napis.
>> Podaj po spacji współrzędne statku o rozmiarze 6 oraz jego orientację (g,d,l,p) np.: A 2 d,
gdzie A to pierwsza współrzędna, 2 to druga współrzędna tak jak oznaczono na planszy.
W grze ustawiamy kolejno statki o rozmiarze od największego do najmniejszego, czyli (6,5,4,3,2)

Drugra faza gry to Faza strzałów, która jest podzielona na tury.
Rozpocząć należy poprzez wpsianie do konsoli napisu start lub START. Po wpisaniu rozpocznie się odliczanie.

Pojawią się wtedy ponownie plansze i będzie można oddawać strzały. Na ekranie zostanie wyświetlony napis:
>> Podaj współrzędne twojego strzału w tej rundzie np.(A 1):
Aby oddać strzał wpisujemy np. A 1 lub A1. W ten wykonujemy ruch, a od razu potem losuje ruch komputer (ruch jest zupełnie losowy spośród pozostałych współrzędnych niewykorzystanych).
Gra może zakończyć się przez gracza wygraną, remisem lub przegraną, w zależności od tego która ze stron pierwsza uzyska 20 trafień.

Po zakończeniu rozgrywki pojawia się komunikat o tym kto zwyciężył oraz pojawia się możliwość wyjścia lub ponownego rozegrania rozgrywki.
---------------------

Powodzenia!
Miłej rozgrywki!