# SpellChecker
_____
## Task: 
![изображение](https://user-images.githubusercontent.com/81780915/163655001-d5dd3f05-e8c0-4248-8272-6dc75912f42d.png)

## Examples:
![изображение](https://user-images.githubusercontent.com/81780915/163655047-1ceb5dab-df9a-40c3-ad7f-b7216c3ac497.png)

## Solution
### 1. Idea
For beginning, I have created a class which is named as Dictionory. I decided to create hash-table powered by "Chain method" in the class. 
 
![изображение](https://user-images.githubusercontent.com/81780915/163655415-a97f0b21-d585-4afa-99f7-a63f515e1606.png)


### 2. Process of searching

In this step I remembered about Levenshtein distance.
**Levenshtein distance** — *is a string metric for measuring the difference between two sequences. Informally, the Levenshtein distance between two words is the minimum number of single-character edits (insertions, deletions or substitutions) required to change one word into the other.* (c) Wiki

![изображение](https://user-images.githubusercontent.com/81780915/163739948-f208f4f6-df3c-4bc5-a486-c8bc397ca89f.png)


With Levenshtein distance I can implement Search method. Besides, the method involves multithreading because of dictionary and text size might be big enough and might add the performance issues.

![изображение](https://user-images.githubusercontent.com/81780915/163742137-4769d00d-80b8-414e-8e40-74cb38ed40ac.png)

## Result:

### First block: words for dictionary;
===
### Second block: wrong text;
===
### Third block: result;

![изображение](https://user-images.githubusercontent.com/81780915/165657791-b538c5fa-bd9a-4aa7-83d3-ef448bf03382.png)


## P.S. 
I deliberately hadn't used templates because some companies hate the metaprogramming. I chose neutral side. I know what is templates and even variadic templates. 



