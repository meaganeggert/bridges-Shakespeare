//Demo code: https://bridgesuncc.github.io/tutorials/SinglyLinkedList.html
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <unordered_map>
#include <Bridges.h>
#include <SLelement.h>
using namespace std;
using namespace bridges;

struct Word {
        string str; //The word we're counting, like "HAMLET"
        int count = 1; //How many times HAMLET or whatever has appeared

        //Sort greatest to smallest by count
        friend bool operator<(const Word &w1, const Word &w2) {
                //YOU: Make it sort from greatest to smallest by count, or
                // alphabetically if a tie
                if (w1.count == w2.count){
                        return (w1.str > w2.str);

                }
                else {
                        return (w1.count < w2.count);
                }

        }

        //Output a Word like this: "HAMLET: 485"
        friend ostream &operator<<(ostream &outs, const Word &w) {
                outs << w.str << ": " << w.count;
                return outs;
        }
};

int main() {
        const size_t TOP = 30; //Show top 30 words
        //Bridges visualization
        Bridges *bridges =  new Bridges(/*YOURASSIGNMENT#*/, /*"YOURNAMEHERE"*/, /*"YOURNUMHERE"*/);
        bridges->setTitle("Shakespeare Histogram");
        bridges->setDescription("A visualization of the 30 most common words used in a work by Shakespeare");

        //Use a hash table to count words
        unordered_map<string,Word> histogram; //The string is the word like "HAMLET", the Word holds both the string and the count of how many times that word has appeared in the file

        //Histogram all the input files, counting how many times each word appears
        while (true) {
                cout << "Enter the name of a file to open (DONE to be done):\n";
                string filename;
                cin >> filename;
                if (filename == "done" or filename == "DONE") break;
                ifstream ins(filename);
                if (!ins) {
                        cout << "Error opening file.\n";
                        continue;
                }


                while (ins) {
                        string s1;
                        ins >> s1;
                        //cout << "init string: " << s1 << endl;
                        //YOU: Remove any non-letter characters from s. Use isalpha.
                        for (int i = 0; i < s1.size(); i++) {
                                if (!isalpha(s1[i])){
                                        s1.erase(i, 1);
                                        i--;
                                }
                        }
                        //cout << "new string: " << s1 << endl;
                        //Uppercaseify the string
                        for (int i = 0; i < s1.size(); i++) {
                                s1[i] = toupper(s1[i]);
                        }
                        //cout << "newest string: " << s1 << endl;
                        //Throw away the word if the length is less than 4
                        //Add to histogram if it does not exist. If it does exist, add one to its count
                        Word checker;
                        checker.str = s1;

                        if (s1.size() >= 4){

                                if (histogram.contains(s1)){

                                        histogram[s1].count += 1;

                                        //cout << histogram[s1] << endl;

                                }
                                else {

                                        histogram[s1] = checker;
                                        //cout << histogram[s1] << endl;
                                }
                        }


                }
        }



        //YOU: Convert the hash table into a vector of results and sort it by count
        vector<Word> vec;
        for (auto key : histogram) {
                //cout << key.second << endl;
                vec.push_back(key.second);
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());


    //Cout how many elements you're printing
    size_t size = TOP;
    //YOU: If the size of the vector is smaller than TOP, set it to the size of the vector
    if (vec.size() <= TOP){
        size = vec.size();
    }
    cout << size << endl;

    if (!size) return 0;




        //BRIDGES Linked List Data Structure
        //The root holds the first element in the linked list
        SLelement<string> *root = nullptr;

        //This will hold the last element in the linked list
        SLelement<string> *cur = nullptr;

        //Print the top 30 and copy them into bridges array
        for (int i = 0; i < TOP and i < vec.size(); i++) {
                cout << vec.at(i) << endl;
                string str = vec.at(i).str;
                int count = vec.at(i).count;

                //Make a new SLelement<string> *temp
                SLelement<string> *temp = new SLelement<string>(str);
                //Set the label and color as above
                temp->setLabel(str + ": "s + to_string(count)); //Sets the label to "HAMLET: 485"

                //YOU: Color it based on its frequency

                //Top  third (usually 10) get colored red
                if (i <= 10) {
                        temp->setColor("red");
                }
                //Next third (usually 10) get colored yellow
                else if (i <= 20){
                        temp->setColor("yellow");
                }
                //Last third (usually 10) get colored green
                else {
                        temp->setColor("green");
                }
                //temp->setColor("pink");

                //Link up the linked list
                if (!root) {
                        root = temp;
                        cur = root;
                }
                else {
                        //YOU: Set the next of cur to temp, using cur->setNext
                        cur->setNext(temp);
                        //YOU: Set cur = temp
                        cur = temp;
                }

        }
        bridges->setDataStructure(root);
        bridges->visualize();


}
