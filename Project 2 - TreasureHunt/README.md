# TreasureHunt
This game is played through the command line menu. For playing this game yourself scroll to the bottom of this file.

## About this game
Three treasures are placed on a board game (A lines x B columns -> matrix) and four treasure hunters are trying to get first to the treasures. There can be up to 3 winners and up to 4 losers (this last scenario happens when players cannot move and the game ends). All 3 treasures are randomly generated in the matrix, so there are a lot of unique games. All the 4 treasure hunters start from one of the matrix corners and have a unique type of moving towards the treasure. Once a certain number of rounds each player uses his special(s) abilit(y)(ies):

~~~

* Hunter 1 -> makes 2 moves every 4 rounds\
* Hunter 2 -> has a 15% chance to freeze other players position every 4 rounds\
* Hunter 2 -> (probably) moves to an adjacent position to a treasure every 6 rounds\
* Hunter 3 -> has a 30% chance to freeze other players position every 4 rounds\
* Hunter 3 -> (probably) moves to an adjacent position to a treasure every 8 rounds\
* Hunter 4 -> makes 2 moves every 2 rounds\

~~~


### Game pictures and example

#### Compiling and running the source code
![Compiling and running the source code](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_0.png)

#### Board game dimensions
![Board game dimensions](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_1.png)

#### Welcome screen
![Welcome screen](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_2.png)

#### Starting the game
![Starting the game](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_3.png)

#### Map view

Legend
~~~
* Character 0 means the position has not been occupied
* Character 1 means that positions are occupied by treasure hunter number 1
* Character 2 means that positions are occupied by treasure hunter number 2
* Character 3 means that positions are occupied by treasure hunter number 3
* Character 4 means that positions are occupied by treasure hunter number 4
* Character 9 means the position is a treasure

~~~

![Map view](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_4.png)

#### Round 9 - Treasure hunter number 3 found a treasure
![Round 9 - Treasure hunter number 3 found a treasure](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_5.png)

#### Round 15 - Pressing the key "2" shows the map changes
![Round 15 - Pressing the key "2" shows the map changes](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_6.png)

#### Round 49 - Treasure hunter number 2 found a treasure - One more left on the map
![Round 49 - Treasure hunter number 2 found a treasure - One more left on the map](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_8.png)

#### Round 79 - A view of the map
![Round 79 - A view of the map](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_9.png)

#### Round 224 - Another view of the map
![Round 224 - Another view of the map](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_10.png)

#### Round 300 - Game comes close to an end
![Round 300 - Game comes close to an end](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_11.png)

#### Round 314 - Treasure hunter number 4 finds the last treasure -> Treasure hunter number 1 lost the game
![Round 314 - Treasure hunter number 4 finds the last treasure -> Treasure hunter number 1 lost the game](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_12.png)

#### If the matrix size is less than 15x15 game will not start.
![If the matrix size is less than 15x15 game will not start](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_13.png)

#### Pressing a key that is not on the menu pops a message and requires a valid key 
![Pressing a key that is not on the menu pops a message and requires a valid key ](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_7.png)
 
#### If a player wants to not continue a game anymore he can press the key "9" and the game exits.
![If a player wants to not continue a game anymore he can press the key "9" and the game exits](https://github.com/JusticeBringer/OOP/blob/master/Project%202%20-%20TreasureHunt/GamePictures/tr_14.png)

### How to play this game

Step 1 -> Download all the files and put them in a folder\
Step 2 -> Open the terminal in the folder location and enter these 2 commands

```
g++ hunter.cpp hunterOne.cpp hunterTwo.cpp hunterThree.cpp hunterFour.cpp treasureHunt.cpp main.cpp -o a.out

./a.out
```
Step 3 -> Follow the instructions in the game menu


### Programming language used

Just C++

### Author

Arghire Gabriel (me)

