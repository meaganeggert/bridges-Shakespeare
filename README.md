### Visualizing Shakespeare's word counts using Bridges
Practice using Bridges to visualize the counts of words in a hashmap.
These are the instructions we were given for the assignment

---

For this assignment, you will learn how to histogram a file. Histogramming
means counting each thing in it, and producing a list of all the things and
their count. We sometimes do it with letters. Here, we're going to do it with
words to see what words Shakespeare likes to use in his plays.

We're going to use bridges to visualize the counts of the top 30 most common
words, using a linked list with the nodes colored based on their rank.

The top 10 words will be in red, the next 10 most common in yellow, and the
last 10 most common in green. If there are less than 30 unique words in the
input, then instead of 10 you will use the top 1/3 as red, the middle 1/3 as
yellow, and the last 1/3 as green.

Step 1. Read through the file given, and filter out bad words. I don't mean
bad words (because we're leaving four letter words in ironically), but I mean
words that don't meet our criteria. First, >> from the file into a string.
Second, remove all non-alphas from it. You should use the isalpha() function
to do this. Third, check the size of the word. If it is 4 or greater, then add
it to our histogram (see next step). If it is smaller than 4 characters,
ignore it and move on.

Step 2. Histogram it. So, how does one histogram? My recommended approach is
to make an unordered_map<string,Word> hist. See if the string is in the map already
by using hist.count(s) and if it is not, write it in like this: hist[s] =
word; If it is in there, then update the count like this: hist[s].count++; But
don't let me dictate how you want to do it. It just seems like the fastest
method to me.

Step 3. Sort the histogram by count. You can't use a hash table
(unordered_map) for this, so I recommend copying all of the elements out of
the hash table and into a vector, and then sorting the vector by count.

Cout the size of the histogram (how many valid words were read in).

Step 4. Cout the top 30 Words (or less, if there are less than 30 words). I
have given you a Word class that is just a string and its count, and I've
given you a << operator for it that is how I want the results printed. You
will need to write a function that will allow Words to be sorted by count from
greatest to smallest count.

Step 5. BRIDGES visualize it. I have provided you with the most important
BRIDGES code. You will need to write code that will change the color of the
output boxes based on their counwrite code that will change the color of the
output boxes based on their count. Here are the rules for that:
Top third of the words: Red
Middle third: Yellow
Bottom third: Green

Remember to punch in your BRIDGES API key and username to get it to work. When
you have it working, run the program passing in these files:
Hamlet
Coriolanus
The Tempest
Henry VIII

(All the works of Shakespeare are in the /public/shakespeare directory)

Link your visualization on Canvas, which is worth 3 points.
