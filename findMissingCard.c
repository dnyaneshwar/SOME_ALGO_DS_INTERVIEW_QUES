/* Program : Fine one missing card from deck of 51 cards 
 *           
 * Input   : Array of 51 card, one card is missing 
 *
 * Output  : Missing card
 *
 * Convensions : 
 *           Number stored in arrays will represent two things 
 *           number % 10 = rem  :  will repesent type of card 
 *           nunber / 10 = ans  :  will repesent card number
 *          e.g. 0 : for club 
 *               1 : for speard
 *               2 : for heart
 *               3 : for star
 * 
 *               Ekka : 1 ..... Gulam : 11 Queen: 12  King: 13                
 *  
 *            so number in array 122 will represent 122 % 10 = 2 
 *                                                  122 / 10 = 12  
 *                                    Queen of Heart
 * 
 * Contraints : Efficient With Less Memory and in O(n) Time 
 */               

//header file
#include <stdio.h>
#include <malloc.h>


//function prototype
int findMissingCard(int *arrayOfCards);
int initCardArray(int *arrayOfCards);

int main(){

  
  int missingCard;
  int typeOfCard;
  int numberOnCard;
 
  //init the array with 51 cards
   int arrayOfCards[] = {10, 11, 12, 13,
                  20, 21, 22, 23,
  		  30, 31, 32, 33,
                  40, 41, 42, 43,
		  50, 51, 52, 53,
		  60, 61,   63,
		  70, 71, 72, 73,
		  80, 81, 82,  83,
		  90, 91, 92, 93,
		  100, 101, 102, 103,
		  110, 111, 112, 113,
		  120, 121, 122, 123,
		  130, 131, 132, 133
   };

   //initCardArray(arrayOfCards);
  missingCard = findMissingCard(arrayOfCards);
 
  typeOfCard = missingCard % 10;
  numberOnCard = missingCard / 10;
  
  switch(typeOfCard) {

  case 0 : printf(" Missing Card is %d of Club ", numberOnCard );
    break;

  case 1 : printf(" Missing Card is %d of Speard ", numberOnCard );
    break;

  case 2 : printf(" Missing Card is %d of Heart ", numberOnCard );
    break;

  case 3 : printf(" Missing Card is %d of Star ", numberOnCard );
    break;

  }//switch
  return 0;
}//main

int findMissingCard(int *arrayOfCards) {

  int i;
  int arrayToStoreCardTypesWise[4] = {0,0,0,0};
  int typeOfCard;
  int numberOnCard;
  int sumOfAllSameTypeCardNumbers = (13 * 14)/2; 
  
  for(i = 0; i < 51; i++) {

    typeOfCard   = arrayOfCards[i] % 10;
    numberOnCard = arrayOfCards[i] / 10;

    arrayToStoreCardTypesWise[typeOfCard] += numberOnCard;//store the same type of cards sum 

  }//for

  for (typeOfCard = 0; typeOfCard < 4; typeOfCard++) {
    //here we come to know that which type of card is missing, ith type of card is missing
    if(arrayToStoreCardTypesWise[typeOfCard] !=  sumOfAllSameTypeCardNumbers ) {
      //here we get missed card number
        numberOnCard = sumOfAllSameTypeCardNumbers - arrayToStoreCardTypesWise[typeOfCard];
        break;
    }//if
  }
 
  return ((numberOnCard*10)+typeOfCard);


}//findMissingCard


/*
int initCardArray(int *arrayOfCards){

                  
  };
  return 0;
}//initCardArray
*/
