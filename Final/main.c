#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

//This defines what a node is.
typedef struct node {
   char data; //Data we want to store in our linked list. We will store the first letter here.
   char dataTwo; //Store the 2nd, 3rd, and fourth letter of a word.
   char dataThree;
   char dataFour;

   int length; //Store the amount of letters.
   //Note to self: Use sizeof() each four letter word to put into length.
   struct node* next; //Next part in a linked list.
}
node;
//maximum amount of nodes possible in the linkest list
#define maximumNodeCount 100

//Global Variables
const int twoDArraySizeOne = 99;
const int twoDArraySizeTwo = 100;
const char done[]="DONE";
const char searchC[]="SEARCHC";
const char searchI[]="SEARCHI";
const char delet[]="DELETE";
const char add[]="ADD";

//Function to create nodes.
node *createNode(char insertToNode, char insertToNodeTwo, char insertToNodeThree, char insertToNodeFour, int wordLength) {
  static node manyNodes[maximumNodeCount];
  static int  nextNode = 0;
  static char temp;

    if (nextNode >= maximumNodeCount)
    {
        printf("Maximum node count reached.\n");
        return (node *)NULL;
    }

    node *nodeReturn = &(manyNodes[nextNode++]);


    nodeReturn->data = insertToNode; //Data added to node.
    nodeReturn->dataTwo = insertToNodeTwo;
    nodeReturn->dataThree = insertToNodeThree;
    nodeReturn->dataFour = insertToNodeFour;
    nodeReturn->length = wordLength;
    nodeReturn->next = NULL; //The linked list's last node points to NULL.

    return nodeReturn; 
}

//Deletes the entire linked list.
void deleteLinkedList(struct node** head){
  struct node* previousNode = *head;
  struct node* next;
  
  while (*head!=NULL) {
      
      printf("Deleting %d\n", previousNode->data);
      
        *head = (*head)->next;
      
        previousNode=NULL;
        
        previousNode = *head;
    }
  *head=NULL;
}

//Reassign the linked list by putting the new alphabet order into the old linked list.
node alphabetOrderLinkedList(node *alphabetRoot, char array[twoDArraySizeOne][twoDArraySizeTwo], int lengthArray[]){
  node *temporary, *newTemporary;
  int sizeOne, sizeTwo;
  char charUltimate[5];
  int newLength=0;
  int lengthIndexCounter=-1;

  //Puts the 2D array into the old linked list.
  temporary = alphabetRoot;
  for (sizeOne = 0; sizeOne < twoDArraySizeOne; sizeOne++){
    
    if (array[sizeOne][sizeTwo]!='\0'&& iswalpha(array[sizeOne][sizeTwo])){
      strcpy(charUltimate, array[sizeOne]);
      //These if statements check how many letters the word have.
      //Yes, I could use a for loop, but with 4, this felt simpler.
      if (iswalpha(charUltimate[0])){
        newLength+=1;
      }
       if (iswalpha(charUltimate[1])){
        newLength+=1;
      }
       if (iswalpha(charUltimate[2])){
        newLength+=1;
      }
       if (iswalpha(charUltimate[3])){
        newLength+=1;
      }
      //Plug 2D array's alphabet words into the old linked list
      //Complicated if, else if, etc. is to avoid a weird bug.
      if (!iswalpha(charUltimate[1])){
        newTemporary=createNode(charUltimate[0], '\0', '\0', '\0', 1);
        }
      else if (!iswalpha(charUltimate[2])){
          newTemporary=createNode(charUltimate[0], charUltimate[1], '\0', '\0', 2);
        }
      else if (!iswalpha(charUltimate[3])){
          newTemporary=createNode(charUltimate[0], charUltimate[1], charUltimate[2], '\0', 3);
        }
      else{
      newTemporary=createNode(charUltimate[0], charUltimate[1], charUltimate[2], charUltimate[3], lengthArray[lengthIndexCounter]); 
      }
      temporary->next = newTemporary; //Move on to the next node. 

    if (newTemporary) {
    temporary = temporary->next;
                    }
      newLength=0;
     }
    else if (sizeOne!=0) {
     sizeOne=100;
      }
    lengthIndexCounter+=1;
    }

  return *alphabetRoot;
  }

////MAIN STARTS HERE////
int main(void) {
  
//Variables for the linked list creation.
char sentence[100]; //This creates the string for the sentence.
int wordLength;
int index;  
node *newTemporary, *root, *temporary; 
char inputLetterOne[2], inputLetterTwo[2], inputLetterThree[2], inputLetterFour[2];
int indexOnce=0;
int indexTwoTimes=0;
int indexThreeTimes=0;
int indexFourTimes=0;

//Stores the original length of words to transfer from first linked list to alphabet sorted linked list.
int originalWordLength[100];
int alphabetWordLength[100];
int originalWLCounter=0;
int alphabetWLCounter=0;
char charTracker[5];

//Variables for alphabet sorting.
int jindex=0; 
int kindex=0;
int lindex=0;
int counter=0; //Counting the amount of words in a linked list.
char alphabetSortingTwoDArray[100][100], alphabetInputArray[5];
char wordStorage[100];

//Varables to handle further user commands after creating the alphabet ordered linked list.
char command[8];
char input[5];
char nodeToCheck[5];
int matchingWordBoolean=0;
char wordToAdd[46]; //pneumonoultramicroscopicsilicovolcanoconiosis
int wordToAddLength=0;

root = createNode(0, 0, 0, 0, 0); //Make the first root node (i.e. the head of the linked list).
temporary= root; //Make the temporary node the root.

//Prompt the user to input text.
printf("Enter your sentence: \n");

//Save the sentence.
fgets(sentence, sizeof(sentence), stdin);

for (index = 0; index < maximumNodeCount; index+=1) { 

    //Because there's a very weird bug that occurs after the sentence linked list creation is done, I put this if statement here. Without these few lines, the linked list will save characters and symbols that were never in the input prompt.
if (!iswalpha(sentence[index]) && !iswalpha(sentence[index+1]) && !iswalpha(sentence[index+2]) && !iswalpha(sentence[index+3]) ) {
  index=maximumNodeCount;
}

  //Reset wordLength variable to 0 so that each word counts back at 0.
  wordLength=0;

  //Check for non-appropriate characters for the first index of the sentence.
  if (sentence[index]!=' ' && sentence[index]!= '\0' && sentence[index]!= '.' && sentence[index]!= '!' && sentence[index]!= '?' && sentence[index]!= '-' && sentence[index]!= ';' && sentence[index]!= ':' && sentence[index]!= ',') {
    inputLetterOne[1]=sentence[index];
    wordLength+=1;

    /////////////////////////////////FIRST NEST/////////////////////////////////////////
    //Check for non-appropriate characters for the second index of the sentence.
    if (sentence[index+1]!=' ' && sentence[index+1]!= '\0' && sentence[index+1]!= '.' && sentence[index+1]!= '!' && sentence[index+1]!= '?' && sentence[index+1]!= '-' && sentence[index+1]!= ';' && sentence[index+1]!= ':' && sentence[index+1]!= ','&& iswalpha(sentence[index+1])) {
      inputLetterTwo[1]=sentence[index+1];
      wordLength+=1;
      

      /////////////////////////////SECOND NEST//////////////////////////////////////
      //Check for non-appropriate characters for the third index of the sentence.
      if (sentence[index+2]!=' ' && sentence[index+2]!= '\0' && sentence[index+2]!= '.' && sentence[index+2]!= '!' && sentence[index+2]!= '?' && sentence[index+2]!= '-' && sentence[index+2]!= ';' && sentence[index+2]!= ':' && sentence[index+2]!= ',' && iswalpha(sentence[index+2])) {
        inputLetterThree[1]=sentence[index+2];
        wordLength+=1;

        
        /////////////////////////////THIRD NEST//////////////////////////////////////
        //Check for non-appropriate characters for the fourth index of the sentence.
        if (sentence[index+3]!=' ' && sentence[index+3]!= '\0' && sentence[index+3]!= '.' && sentence[index+3]!= '!' && sentence[index+3]!= '?' && sentence[index+3]!= '-' && sentence[index+3]!= ';' && sentence[index+3]!= ':' && sentence[index+3]!= ',' && iswalpha(sentence[index+3])) {
          inputLetterFour[1]=sentence[index+3];
          indexFourTimes=1;
          wordLength+=1;
          
          //Skip the rest of words with more than 4 letters.
          while (sentence[index+4]!=' ' && sentence[index+4]!= '\0' && sentence[index+4]!= '.' && sentence[index+4]!= '!' && sentence[index+4]!= '?' && sentence[index+4]!= '-' && sentence[index+4]!= ';' && sentence[index+4]!= ':' && sentence[index+4]!= ',' && iswalpha(sentence[index+4])){
            index+=1;
            wordLength+=1;
          }
                                                                         }
  else {
    indexThreeTimes=1;
    inputLetterFour[1]='\0';
  }
  //For three letter words, make the last data in the node blank.
  if (sentence[index+3]==' ' || sentence[index+3]=='!'|| sentence[index+3]=='?' || sentence[index+3]=='-' || sentence[index+3]==';' || sentence[index+3]==':' || sentence[index+3]=='.'){
    inputLetterFour[1]='\0';
    indexThreeTimes=1;
    }
  else if(sentence[index+3]==','){
     indexThreeTimes=1;
     }
                                                                     }
      else {
        inputLetterThree[1]='\0';
        indexTwoTimes=1;
        
  }
      //For two letter words, make the rest of the two datas in the node blank.
      if (sentence[index+2]==' '|| sentence[index+2]=='!'|| sentence[index+2]=='?' || sentence[index+2]=='-' || sentence[index+2]==';' || sentence[index+2]==':'|| sentence[index+2]=='.'){
        inputLetterThree[1]='\0';
        inputLetterFour[1]='\0';
        indexTwoTimes=1;
        
    }
    else if(sentence[index+2]==','){
      inputLetterFour[1]='\0';
      indexOnce=1;
    }
                                                            }
    else {
      inputLetterTwo[1]='\0';
      indexOnce=1;
      
  }
    //For one letter words, make the rest of the three datas in the node blank.
    if (sentence[index+1]==' '|| sentence[index+1]=='!'|| sentence[index+1]=='?' || sentence[index+1]=='-' || sentence[index+1]==';' || sentence[index+1]==':' || sentence[index+1]=='.'){
      inputLetterTwo[1]='\0';
      inputLetterThree[1]='\0';
      inputLetterFour[1]='\0';
      indexOnce=1;
    }
    else if(sentence[index+1]==','){
      inputLetterThree[1]='\0';
      inputLetterFour[1]='\0';
      indexOnce=1;
    }
                                        }
    //If the first index is blank, start the whole process again at the next index.
  else {
    continue;
    }
  
  newTemporary=createNode(inputLetterOne[1], inputLetterTwo[1], inputLetterThree[1], inputLetterFour[1], wordLength); //Make a new node.
  temporary->next = newTemporary; //Move on to the next node. 

  if (newTemporary) {
    temporary = temporary->next;
                    }

  //Four four letter words or longer, increase the index here.
  if (indexFourTimes==1){
    index+=4;
  }
  //Four three letter words, increase the index here.
  if (indexThreeTimes==1){
    index+=3;
  }
  if (indexTwoTimes==1){
    index+=2;
  }
  if (indexOnce==1){
    index+=1;
  }
  
  //Reset these char arrays. Otherwise, extra letters that we don't want will be saved in nodes.
      inputLetterOne[1]='\0';
      inputLetterTwo[1]='\0';
      inputLetterThree[1]='\0';
      inputLetterFour[1]='\0';
  //Reset the index counters to 0.
      indexThreeTimes=0;
      indexFourTimes=0;
      indexOnce=0;
      indexTwoTimes=0;
//Reset wordLength variable to 0 so that each word counts back at 0.
      wordLength=0;
                                                                          
                                                       }

printf("\nInitial Linked List Creation:\n");
//The for loop prints the letters in the linked list.
for (temporary = root; temporary != NULL; temporary = temporary->next){
  if (temporary->data!=0 || temporary->dataTwo!=0 || temporary->dataThree!=0 || temporary->dataFour!=0 || temporary->length!=0){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf(" ("); 
    printf("%d", temporary->length);
    printf(")"); 
    printf("\n");
    }
  
    //Keeps the length of words from the linked list to put in the alphabet sorter later.
    originalWordLength[originalWLCounter]=temporary->length;
    originalWLCounter+=1;

    //Stores words from the linked list to alphabet sort later.
    alphabetInputArray[0]=temporary->data;
    alphabetInputArray[1]=temporary->dataTwo;
    alphabetInputArray[2]=temporary->dataThree; 
    alphabetInputArray[3]=temporary->dataFour;
    strcpy(alphabetSortingTwoDArray[lindex], alphabetInputArray);
    
    counter+=1;
    lindex=lindex+1;
  }

  //These for loops alphabetically sort the word in the linked list.
   for(jindex=0;jindex<counter;jindex++){
      for(kindex=jindex+1;kindex<counter;kindex++){
         if(strcasecmp(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex])>0){
            strcpy(&wordStorage[0], alphabetSortingTwoDArray[jindex]);
            strcpy(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex]);
            strcpy(alphabetSortingTwoDArray[kindex], &wordStorage[0]);
         }
      }
   }

  //Compare alphabet 2D array and original linked list to store the original lengths into an int array.
   for(jindex=0;jindex<counter;jindex++){
     strcpy(charTracker, alphabetSortingTwoDArray[jindex]);
   temporary=root;
     
  for(temporary=root; temporary != NULL; temporary = temporary->next){
    //Skip root node.
    if (temporary->data==0 && temporary->dataTwo==0 &&temporary->dataThree==0 && temporary->dataFour==0 && temporary->length==0){
     temporary = temporary->next;
    }
    
    //Checking for letters in 2Darray and that letters in 2Darray match linked list's letters in their nodes.
      if (temporary->length==1){
        if(charTracker[0]==temporary->data&&iswalpha(charTracker[0])){
          alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root;
          break;
        }
      }
      else if (temporary->length==2){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo &&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root; 
          break;
            }
      }
      else if (temporary->length==3){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root;
          break;
            }
      }
      else if(temporary->length>=4){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&charTracker[3]==temporary->dataFour&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])&&iswalpha(charTracker[3])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root; 
          break;
            }
      }
      }
   }

  //Important function call to sort the linked list alphabetically.
  alphabetOrderLinkedList(root, alphabetSortingTwoDArray, alphabetWordLength);

  //The for loop prints the letters in the linked list.
printf("\nLinked List with Alphabet Order:\n");
for (temporary = root; temporary != NULL; temporary = temporary->next){
    if (temporary->data!=0 || temporary->dataTwo!=0 || temporary->dataThree!=0 || temporary->dataFour!=0 || temporary->length!=0){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf(" ("); 
    printf("%d", temporary->length);
    printf(")"); 
    printf("\n");
    }
  }

//The loop will continue until DONE is typed in.
while (strcmp(command, done)){
  matchingWordBoolean=0;
  //Prompts users for commands after making the linked list and sorting it in alphabetical order.
printf("\nType DELETE to delete the entire linked list.\nType SEARCHC to search for a word with case sensitivity turned on.\nType SEARCHI to search for a word regardless of case sensitivity.\nType ADD to add a word to the linked list.\nType DONE to finish the program.\n");
  
  scanf("%s", command);
  if (!strcmp(command, done)){
    break;
    
  }
  //Search case insensitive mode
    if (!strcmp(command, searchI)){
    printf("\nWhat is the word you are searching for?\nIf it's more than four letters, just type the first four letters.\n");
      scanf("%s", input);
    printf("\n");
    for (temporary = root; temporary != NULL; temporary = temporary->next){
      nodeToCheck[0]=temporary->data;
      nodeToCheck[1]=temporary->dataTwo;
      nodeToCheck[2]=temporary->dataThree;
      nodeToCheck[3]=temporary->dataFour;
      if (!strcasecmp(nodeToCheck, input)){
        printf("There is a word that matches: ");
        printf("%c", temporary->data); 
        printf("%c", temporary->dataTwo); 
        printf("%c", temporary->dataThree); 
        printf("%c", temporary->dataFour);
        printf("\n");
        matchingWordBoolean=1;
      }
    }
    //Reset the input char array. Going back to root is probably unnecessary but just in case.
    if (matchingWordBoolean==0){
      printf("No matching words.");
      printf("\n");
    }
      
    temporary=root;
    input[0]='\0';
    input[1]='\0';
    input[2]='\0';
    input[3]='\0';
      
  }
  //Search case sensitive mode
  if (!strcmp(command, searchC)){
    printf("\nWhat is the word you are searching for?\nIf it's more than four letters, just type the first four letters.\n");
    scanf("%s", input);
    printf("\n");
    for (temporary = root; temporary != NULL; temporary = temporary->next){
     
      if (temporary->data==input[0]&&temporary->dataTwo==input[1]&&temporary->dataThree==input[2]&&temporary->dataFour==input[3]){
        printf("There is a word that matches: ");
        printf("%c", temporary->data); 
        printf("%c", temporary->dataTwo); 
        printf("%c", temporary->dataThree); 
        printf("%c", temporary->dataFour);
        printf("\n");
        matchingWordBoolean=1;
      }
      
    }
    
    if (matchingWordBoolean==0){
      printf("No matching words.");
      printf("\n");
    }
    
    //Reset the input char array. Going back to root is probably unnecessary but just in case.
    temporary=root;
    input[0]='\0';
    input[1]='\0';
    input[2]='\0';
    input[3]='\0';
  }
  
  //Delete the linked list and end the program.
  if (!strcmp(command, delet)){
    printf("\n");
    deleteLinkedList(&root);
    //The for loop prints the letters in the linked list.
    for (temporary = root; temporary != NULL; temporary = temporary->next){
      printf("%c", temporary->data); 
      printf("%c", temporary->dataTwo); 
      printf("%c", temporary->dataThree); 
      printf("%c", temporary->dataFour);
      printf("%d", temporary->length);
      printf("\n");
      }
  
    printf("Deletion complete.");
    break;
    
  }
  if (!strcmp(command, add)){
    //Reset this value and array in case of reuse of the add function.
    wordToAddLength=0;
    memset(wordToAdd, 0, sizeof wordToAdd);
    
    printf("\nEnter your word to add to the linkest list: \n");
    //Without this line, the program will skip fgets.
    while ((getchar()) != '\n');

    //Get the word to add from the user.
    fgets(wordToAdd, sizeof(wordToAdd), stdin); 
    printf("\nWord to Add: ");
    printf("%s", wordToAdd);
    printf("\n");

    //Count the length of the word.
    for (int index = 0; index<sizeof(wordToAdd); ++index) {
    if(iswalpha(wordToAdd[index])!=0){
      wordToAddLength+=1;
      }
      else if(iswalpha(wordToAdd[index])==0) {
        wordToAdd[index]='\0';
      }
    }

    //Add the added word to the end of the linked list for now.
    
    for (temporary = root; temporary != NULL; temporary = temporary->next){
      if (temporary->next==NULL){
       
      newTemporary=createNode(wordToAdd[0], wordToAdd[1], wordToAdd[2], wordToAdd[3], wordToAddLength);
        temporary->next=newTemporary;
        if(newTemporary){
          temporary = temporary->next;
        }
        }
  }

    //Reset the arrays and variables just in case.
    memset(originalWordLength, 0, sizeof originalWordLength);
    memset(alphabetWordLength, 0, sizeof alphabetWordLength);
    memset(alphabetInputArray, 0, sizeof alphabetInputArray);
    memset(alphabetSortingTwoDArray, 0, sizeof alphabetSortingTwoDArray);
    memset(charTracker, 0, sizeof charTracker);
    memset(wordStorage, 0, sizeof wordStorage);
    counter=0;
    lindex=0;
    originalWLCounter=0;
    alphabetWLCounter=0;
    
    for (temporary = root; temporary != NULL; temporary = temporary->next){

    //Keeps the length of words from the linked list to put in the alphabet sorter later.
    originalWordLength[originalWLCounter]=temporary->length;
    originalWLCounter+=1;

    //Stores words from the linked list to alphabet sort later.
    alphabetInputArray[0]=temporary->data;
    alphabetInputArray[1]=temporary->dataTwo;
    alphabetInputArray[2]=temporary->dataThree; 
    alphabetInputArray[3]=temporary->dataFour;
    strcpy(alphabetSortingTwoDArray[lindex], alphabetInputArray);
    counter+=1;
    lindex+=1;
        }
    
    //These for loops alphabetically sort the word in the linked list.
    for(jindex=0;jindex<counter;jindex++){
      for(kindex=jindex+1;kindex<counter;kindex++){
         if(strcasecmp(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex])>0){
            strcpy(&wordStorage[0], alphabetSortingTwoDArray[jindex]);
            strcpy(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex]);
            strcpy(alphabetSortingTwoDArray[kindex], &wordStorage[0]);
            }
         }
      }

    //Count all of the letters for the words in the linked list.
for(jindex=0;jindex<counter;jindex++){
     strcpy(charTracker, alphabetSortingTwoDArray[jindex]);
   temporary=root;
     
  for(temporary=root; temporary != NULL; temporary = temporary->next){
    //Skip root node.
    if (temporary->data==0 && temporary->dataTwo==0 &&temporary->dataThree==0 && temporary->dataFour==0 && temporary->length==0){
     temporary = temporary->next;
    }
    
    //Checking for letters in 2Darray and that letters in 2Darray match linked list's letters in their nodes.
      if (temporary->length==1){
        if(charTracker[0]==temporary->data&&iswalpha(charTracker[0])){
          alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root;
          break;
        }
      }
      else if (temporary->length==2){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo &&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root; 
          break;
            }
      }
      else if (temporary->length==3){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root;
          break;
            }
      }
      else if(temporary->length>=4){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&charTracker[3]==temporary->dataFour&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])&&iswalpha(charTracker[3])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
          temporary=root; 
          break;
            }
      }
      }
   }

    //Important function call to sort the linked list alphabetically.
  alphabetOrderLinkedList(root, alphabetSortingTwoDArray, alphabetWordLength);

  //The for loop prints the letters in the linked list.
  printf("New Linked List with Alphabet Order:\n");
  for (temporary = root; temporary != NULL; temporary = temporary->next){
    if (temporary->data!=0 || temporary->dataTwo!=0 || temporary->dataThree!=0 || temporary->dataFour!=0 || temporary->length!=0){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf(" ("); 
    printf("%d", temporary->length);
    printf(")"); 
    printf("\n");
                       }
          }
    }
  
  }
  
return  0;
}

/* 
Test cases:
I smell it.
Wrap it up.
Feed the baby.
I like it.
We party hard.
We sell sea shells.
I love you.
Eat the ice cream. 
Why not?
How am I smart?
I like it, sir.
I ran, and I won.
I am good, but I eat.
I am happy!
I would like a taco.
I like rice; give me one.
I bought: mangos, cheese, and John Wick.
I like to eat.
Good night, I love you.
Jay was born.
I did not check.
I like beans, and I hate pineapples, but Jim Carrey was ok, or the Sonic movie writers were nuts.
I like cheese.
I make pasta.
I ate it.
I like potato.
I like Bob.
I ran very far away.
Was it a car or a cat I saw?
Donkeys cry bacon. (Add apple, then add chicken, then add breakfast, then add yogurt)
I ordered it.
How are you?
Drop it.
Hmm, that is good.
*/
