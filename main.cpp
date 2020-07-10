#include <iostream>
#include<string>
using namespace std;

//class Song
class Song{
private:
    int songID;
    string title;
    string artist;
    string album;
    int year;

public:

    Song(); //default constructor, set string variables to "" and set integer variables to 0

    Song(int aID, string aTitle, string anArtist, string anAlbum, int aYear); //parametrized constructor

    int getSongID()const; // return value song ID
    string getTitle()const; // return value title
    string getArtist()const; // return value artist
    string getAlbum()const; // return value album
    int getYearReleased()const; // return value year
    void setSongID(int newSongID); //set the songID to newSongID
    void setTitle(string newTitle); //set the title to newTitle
    void setArtist(string newArtist); //set the artist to newArtist
    void setAlbum(string newAlbum); //set album to newAlbum
    void setYear(int newYear); //set year to newYear

};

struct node{
    Song song;
    node *next;

};

//insert your code for all the constructs and member functions of Song class here
//For example, this is the code (incomplete) for the default constructor of the class
Song::Song()
{
    songID = 0;
    //insert code here
    title = "";
    artist = "";
    album = "";
    year = 0;
}

Song::Song(int aID, string aTitle, string anArtist, string anAlbum, int aYear){ //parametrized constructor
    songID = aID;
    title = aTitle;
    artist = anArtist;
    album = anAlbum;
    year = aYear;
}

int Song :: getSongID() const{ // return value song ID
    return songID;

}
string Song :: getTitle() const{ // return value title
    return title;
}
string Song :: getArtist()const { // return value artist
    return artist;
}
string Song :: getAlbum()const{ // return value album
    return album;
}
int Song :: getYearReleased()const{ // return value year
    return year;
}
void Song :: setSongID(int newSongID){ //set the songID to newSongID
    songID = newSongID;
}
void Song :: setTitle(string newTitle){ //set the title to newTitle
    title = newTitle;
}
void Song :: setArtist(string newArtist){ //set the artist to newArtist
    artist = newArtist;
}
void Song :: setAlbum(string newAlbum){ //set album to newAlbum
    album = newAlbum;
}
void Song :: setYear(int newYear){ //set year to newYear
    year = newYear;
}

//Complete the code for the following functions
void displayList(node** head);
void displaySong(node** head, int ID);
void insertNewSong(node** head,Song newSong);


int main(int argc, const char * argv[]) {

    int choice;
    struct node *list = NULL;

    int newSongID;
    string newTitle;
    string newArtist;
    string newAlbum;
    int newYear;
    int id;

    do
    {
        cout << endl
        << "***** My Song List *****" << endl
        << " 1 - Display List" << endl
        << " 2 - Display a Song" << endl
        << " 3 - Insert new Song" << endl
        << " 4 - Exit." << endl
        << " Enter your choice and press return: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                //call the function displayList to display the song that appears in the list
                displayList(&list);
                break;

            case 2:
            {
                cout << endl
                << "Enter the ID of the song that you would like to display!" << endl;
                cin >> id;
                //call displaySong functioin to display the name of the song based on ID match
                displaySong(&list, id);
            }

                break;

            case 3:
            {
                Song newSong;
                cout << endl << "Enter information for your new song!" << endl;
                cout << "Song ID : " ;
                cin.ignore();
                cin >> newSongID;
                newSong.setSongID(newSongID);
                cout << "Title : " ;
                cin.ignore();
                getline(cin, newTitle);
                newSong.setTitle(newTitle);
                cout << "Artist : " ;
                getline(cin, newArtist);
                newSong.setArtist(newArtist);
                cout << "Album : " ;
                getline(cin,newAlbum);
                newSong.setAlbum(newAlbum);
                cout << "Year : " ;
                cin >> newYear;
                newSong.setYear(newYear);
                //call insertNewSong function to insert a new song to the list
                //the new song should be added to the FRONT of the list
                //Song newSong(newSongID, newTitle, newArtist, newAlbum, newYear);
                insertNewSong(&list,newSong);
                cout << "New song is added!!!" << endl;
            }
                break;

            case 4:
                cout << "End of Program.\n";

            default:
                cout << "Not a Valid Choice. \n"
                << "Choose again.\n";
                break;
        }

    }while (choice !=4);
    return 0;
}

void insertNewSong(node** head, Song newSong){
    //add your code here
    struct node *temp;
    temp = new node;
    temp->song = newSong;
    temp->next = *head;
    *head = temp;
}

void displayList(node ** head){
    //add your code here}
    struct node *temp = *head;
    if(temp==NULL)
    {
        cout<<endl<<"List is Empty."<<endl;
        return;
    }
    while(temp!=NULL){
        cout<<endl<<"Title: "<<temp->song.getTitle();
        cout<<endl<<"Artist: "<<temp->song.getArtist();
        cout<<endl<<"Album: "<<temp->song.getAlbum();
        cout<<endl<<"Year: "<<temp->song.getYearReleased();
        temp = temp->next;
    }
}

void displaySong(node** head, int ID){
    //add your code here
    struct node *temp = *head;
    if(temp==NULL)
    {
        cout<<endl<<"List is Empty."<<endl;
        return;
    }
    while(temp!=NULL){
        if(temp->song.getSongID() == ID){
            cout<<endl<<"Title: "<<temp->song.getTitle();
            cout<<endl<<"Artist: "<<temp->song.getArtist();
            cout<<endl<<"Album: "<<temp->song.getAlbum();
            cout<<endl<<"Year: "<<temp->song.getYearReleased();
        }
        temp = temp->next;
    }
    if(temp->next == NULL){
        cout<<endl<<"Song not Found."<<endl;
    }
}
