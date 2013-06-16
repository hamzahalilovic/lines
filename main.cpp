#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
   {
map<string, int> wordCounts; // Map of wordCounts and their frequencies
map<string, int>::const_iterator iter;
map<string, int>::const_iterator iter2;
int line;


    string word;           // Used to hold input word.

    ifstream input("file.txt");
	if(input.fail())
	{
		cout << "Error opening file.";
		return -1;
	}


    for ( line = 1; input; line++ )
    {
        char buf[ 255 ];
        input.getline( buf, 128 );


        for ( char *p = buf;
              *p != '\0';
              p++ )
        {
            if ( !isalpha( *p ) )
                *p = ' ';
        }

        istringstream i( buf );

        while ( i )
        {
            i >> word;
            if ( word != "" )
            {
                wordCounts.insert( pair<const string,int>( word, line ) );
            }
        }
    }




input.close();

    for (iter=wordCounts.begin(); iter != wordCounts.end(); ) {
     iter2 = wordCounts.upper_bound( (*iter).first );

        cout << "the word: " << (*iter).first << " is on line(s): ";

        for ( ; iter != iter2; iter++ )
        {
            cout << (*iter).second << " ";
        }
        cout << endl;
    }

    cout << endl << "There are " << wordCounts.size() << " words in the file";
    return 0;

}
