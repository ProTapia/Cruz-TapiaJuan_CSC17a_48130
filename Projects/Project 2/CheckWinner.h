/* 
 * File:   CheckWinner.h
 * Author: Juan Cruz Tapia
 *
 * Created on December 7, 2014, 8:26 PM
 */

#ifndef CHECKWINNER_H
#define	CHECKWINNER_H

//Class to become template 
class CheckWinner 
{
    private:
        int plPoints;
        int enPoints;
    public:
        CheckWinner()
        {
            plPoints = 0; 
            enPoints = 0;
        }
        CheckWinner(int pl, int en){ plPoints = pl; enPoints = en;}
         
        void setPlPoints(int pl){plPoints = pl;}
        void setEnPoints(int en){enPoints = en;}
        
        void getResult();
};

#endif	/* CHECKWINNER_H */

