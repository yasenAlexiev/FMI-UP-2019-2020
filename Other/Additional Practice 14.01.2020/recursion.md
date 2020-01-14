# Recursion coding tasks

## Easy

#### Задача 1.
Напишете рекурсивна функция ```int factorial(int n)```, която пресмята **n!**, където n е число по-голямо или равно на **0**.

#### Задача 2.
Имаме триъгълник изграден от блокчета. Най-горния ред има 1 блокче, следващия ред има 2 блокчета и т.н. Напишете рекурсивна функция
```int triangleBlocks(int rowsCount)```, която намира броя на блокчетата в даден триъгълник, пресместнат чрез броя на редовете.
```javascript
triangleBlocks(0) --> 0
triangleBlocks(1) --> 1
triangleBlocks(2) --> 3
triangleBlocks(5) --> 15
```

## Normal

#### Задача 1. 
Напишете рекурсивна функция ```int fibonacci(int n)```, която намира **n-тия** подред член на редицата на Фибоначи. Считаме,
че ```fibonnacci(0) = 0``` и ```fibonnacci(1) = 1```.

#### Задача 2.
Напишете рекурсивна функция ```int power(int base, int power)```, която намира стойността на ```base``` вдигната на ```power``` степен.

#### Задача 3.
Напишете рекурсивна функция ```void removeX(char * source, char * destination)```, която премахва всички срещания на ```X``` в ```source``` 
и запазва резултата в ```destionation```. След изпълнението на функцията ```source``` не трябва да бъде променен.
```javascript
removeX("EXCALIBUR",destination) --> destination = ECALIBUR
removeX("xXx_CringyName_xXx", destination) --> destination = xx_CrigngyName_xx
```

#### Задача 4.
Напишете рекурсивна функция ```void cleanText(char * text)```, която **изчиства** ```text```. **Изчистването** се състои в това да се 
премахнат всички последователни повторения на дадена буква.
```javascript
cleanText("abcc") --> abc
cleanText("acBcc") --> acBc
```

## Hard

#### Задача 1.
Напишете рекурсивна функция ```moveX(char * text)```, която премества всички срещания на ```x``` в края на ```text```.
```javascript
moveX("xxab") --> abxx
moveX("xax") --> axx
```

#### Задача 2.
Напишете рекурсивна функция ```int countPairs(char * text)```, която намира броя на **двойките** в ```text```. **Двойка** наричаме
даден символ разделен от трети такъв, например ```АxA``` е една такава двойна на символа ```A```. Също така ```AxAxA``` има общо 3 двойки
- 2 двойки от ```A``` и една двойка от ```x``` в ```xAx```.
```javascript
countPairs("axa") --> 1
countPairs("axax") --> 2
countPairs("axbx") --> 1
countPairs("axaxaxa") --> 5
```

#### Задача 3.
Напишете рекурсивна функция ```bool nestedParenthesis(char * text)```, която проверява дали скобите в ```text``` са правилно вложени.
```javascript
nestedParenthesis("()") --> true
nestedParenthesis("(())") --> true
nestedParenthesis("((x))") --> true
nestedParenthesis("((x)") --> false
nestedParenthesis("(xy))") --> false
```

## Sequence 00 - Eesy

#### Задача 1.
Имаме зайчета. Всяко зайче има **две** меки ушички. Напишете рекурсивна функция ```int bunnyEars(int bunnyCount)```, която пресмята 
броя на ушичките на зайчетата.

#### Задача 2.
Отново имаме зайчета, този път те са наредени в редица и има хибридни зайчета измежду тях. Всяко нечетно зайче има по **три** ушички.
Напишете рекурсивна функция ```int hybridBunnyEars(int bunnyCount)```, която пресмята броя на ушичките на зайчетата в редицата.

## Sequence 01 - Normal 

#### Задача 1.
Напишете рекурсивна функция ```int digitSum(int number)```, която намира сумата на цифрите на ```number```.

#### Задача 2.
Напишете функция ```int countSeven(int number)```, която намира броя **седмиците** измежду цифрите на ```number```.

```javascript
countSeven(123) --> 0
countSeven(007) --> 1
countSeven(777) --> 3
```

#### Задача 3.
Напишете рекурсивна функция ```int countEight(int number)```, която намира броя на **осмиците** измежду цифрите на ```number```.
В случая, че има в ляво на една осмица има друга осмица, считаме осмицата за 2, вместо за 1.

```javascript
countEight(1) --> 0
countEight(8) --> 1
countEight(88) --> 3
countEight(888) --> 5
countEight(8818) --> 4
```

### Sequence 02 - Normal

#### Задача 1. 
Напишете рекурсивна функция ```int countX(char * text)```, която намира броя на na срещанията на символа ```x``` в ```text```.
```javascript
countX("test") --> 0
countX("xxx") --> 3
countX("xxxDestroyerxXx") --> 5
```

#### Задача 2.
Напишете рекурсивна функция ```int countHi(char * text)```, която намира броя на срещанията на ```hi``` в ```text```.
```javascript
countHi("hello") --> 0
countHi("hi") --> 1
countHi("hihih") --> 2
countHi("Hihihi") --> 2
```

#### Задача 3.
Напишете рекурсивна функция ```void changeXY(char * source, char * destination)```, която замества всички срещания на ```x``` със ```y```,
като не променя ```source```, резултатът трябва да се запази в ```destination```. (Може да решите по-лесния вариант като първо заменяте директно в ```source```
).
```javascript
changeXY("xenovia") --> yenovia
changeXY("xuck") --> yuck
changeXY("xxx") --> yyy
```

#### Задача 4.
Напишете рекурсивна функция ``` void changePi(char * source, char * destination)```, която замества всички срещания на ```Pi``` със ```3.14```.
```javascript
changePi("xxPixx") --> xx3.14xx
changePi("Pipi") --> 3.14pi
changePi("Po Pi Morqka") --> Po 3.14 Morqka
```
### Sequence 03 - Easy

#### Задача 1. 
Напишете рекурсивна функция ```bool contains6(int numbers[], int index)```, която проверява дали числото 6 съществува в масива от даден 
индекс ```index``` нататък(включително).
```javascript
contains6([1, 2, 3, 4, 5, 6], 0) --> true
contains6([1, 2, 3, 4, 5, 6, 7], 5) --> true
contains6([1, 2, 3, 4, 5, 6, 7], 6) --> false
```

#### Задача 2.
Напишете рекурсивна функция ```int count6(int numbers[], int index)```, която намира броя на срещанията на числото ```6``` в масива
```numbers```.
```javascript
count6([1, 2, 3, 4, 5, 6], 0) --> 1
count6([1, 2, 3, 4, 5, 6, 7], 5) --> 1
count6([1, 2, 3, 4, 5, 6, 7], 6) --> 0
count6([6, 6, 6], 0) --> 3
```

### Задача 3.
Напишете рекурсивна функция ```bool contains10Multiples(int numbers[], int index)```, която проверява дали в масива се съдържа стойност, 
последвана от тази стойност умножена по 10 някъде надясно в масива.
```javascript
contains10Multiples([1, 2, 20], 0) → true
contains10Multiples([3, ,10, 30], 0) → true
contains10Multiples([3], 0) → false
```

### Sequence 04 - Normal

#### Задача 1. 
Напишете рекурсивна функция ```void allStar(char * text)```, която слага ```*``` между всеки два символа в ```text```.
```javascript
allStar("test") --> t*e*s*t
allStar("aa") --> a*a
```

#### Задача 2. 
Напишете функция ```void pairStar(char * text)```, която слага ```*``` между всеки два еднакви символа в ```text```.
```javascript
pairStar("test") --> test
pairStar("hello") --> hel*lo
pairStar("abbba") --> ab*b*ba
```

### Sequence 05 - Slightly Harder

#### Задача 1.
Напишете рекурсивна функция ```int strCount(char * string, char * substring)```, която намира броя на срещанията на ```substring``` в ```string```.
```javascript
strCount("catdogcat","cat") --> 2
strCount("aaa","a") --> 3
strCount("aaa", "aa") --> 2
```


