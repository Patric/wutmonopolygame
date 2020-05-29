# wutmonopolygame

ETAP 2
----------------------------------------------------------------------------------------------
Etap 2 projektu PJC to gałąź PJC-projekt-prototyp-aplikacji

Aby uruchomić program bez otwierania projektu w Visual Studio należy pobrać spakowany plik executable.zip i wypakować go. W środku znajduje się plik wykonawczy .exe oraz katalogi z zasobami. Program nie potrzebuje dodatkowych bibliotek. (a przynajmniej u mnie nie potrzebował).

Aby projekt uruchomić w Visual studio należy plik z biblioteką SFML o nazwie  	SFML-2.5.1-windows-vc15-32-bit.zip wypakować do katalogu o 1 wyżej niż plik main.cpp. Linker, Precprocessor powinien być skonfigurowany w pliku z projektem.
Dopiero zaczynam z git'em, więc przepraszam z góry za wszelkie niejasności i nieporządek w komentarzach.



Jeśli chodzi o diagram klas to w dużej mierze zmieniłem go w porównaniu do etapu 1, gdyż dopiero na etapie implementacji faktycznie zrozumiałem obiektowość i przeszukałem internet w celu opracowania skutecznej mechaniki do gry. Jestem świadomy, 
że opracowana przeze mnie mechanikajest nieco zbyt skomplikowana jak na taką grę, ale znalazłem świetny poradnik do gier RPG i 
również dzięki niemu zrozumiałem projektowanie obiektowe.

W projekcie jeszcze wiele należy zrobić, aby to była w pełni funkcjonalna gra. Narazie działa tylko New Game -> Roll Dice, 
po czym należy kliknąć End turn, aby kolejka przeszła na innego gracza. Ręcznie dodanych jest dwóch graczy. W przyszłości ma to
odbywać się poprzez lobby, którego hostem będzie jeden z graczy. Pola testowe są to pola Property, czyli w przyszłości
będzie możliwość kupna takiego pola(już jest, ale nie ma jeszcze przycisku, bo gui niestety zabiera najwięcej czasu). Przy zmianie pola
uruchamia się funkcja pola i zabiera graczowi pieniądze z portfela.(bo gracz nie może jeszcze kupić tego pola).

Gra nie ma jeszcze komponentu sieciowego, jednak planuję załatwić to poprzez protokół TCP/IP, co już testowałem. Planuję updatować
poszczególne czynności wykonywane przez graczy w czasie rzeczywistym i przesyłać do wszystkich innych graczy. Gracz będzie
przesyłał, który z graczych na wspólnej liście ma otrzymać kolejkę(gdy this->you równa się graczowi, który aktualnie ma ruch
to gracz, otrzymuje możliwość ruchu. Następnie wysyła innym graczom komunikat o zakończonej swojej turze, i o tym kto teraz ma ruch.
this->you będzie definiowane na początku, w gameState. Oprócz tego należy dodać Menu akcji gracza w jego kolejce, a w menu czynności
takie jak kup pole/sprzedaj pole/ulepsz pole. 

Plik config/windows.ini zawiera konfigurację.
WuT Monopoly in building... //Tytuł okna
1920 1080                   //Rozdzielczość - starałem się, aby aplikacja była skalowalna(biblioteka SFML ma taką opcję, 
                            //ale nie zauważyłem tego i dalej wszystko robiłem ręcznie.
0                           //Tryb pełnoekranowy
120                         //FPS w razie, gdybym chciał dodać animacje
0                           //Dodatkowe parametry takie jak antyalisaing i inne, których raczej nie użyję w tym przedmiocie.
0
