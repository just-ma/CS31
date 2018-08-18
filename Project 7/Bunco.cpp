//
//  Bunco.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Bunco.h"
#include <iostream>

namespace cs31
{
    Bunco::Bunco() : mRound( 0 )
    {
        
    }
    
    // stringify the game by stringifying the board
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Bunco!\n";
            }
        }
        return( s );
    }
    
    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round );
        mHuman.setRound(round);
        mComputer.setRound(round);
    }

    int Bunco::humanPlay( int amount ) //rolls dice for human
    {
        int amountrolled = mHuman.roll(amount); //if amount is 0, it randomly generates a number
        
        return( amountrolled ); //amount rolled is returned
    }

    int Bunco::computerPlay( int amount )
    {
        int amountrolled = mComputer.roll(amount); //if amount is 0, it randomly generates a number

        return( amountrolled ); //amount rolled is returned
    }

    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome( ) 
    {
        ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED; //default state is NOTDECIDED
        if (mHuman.getScore() > mComputer.getScore()) //if the human's score is greater than the computer score, human wins
        {
            result = ROUNDOUTCOME::HUMANWON;
            mBoard.markHumanAsWinner(); //sets human as the winner for that round
        }
        else if (mComputer.getScore() > mHuman.getScore()) //if the computer's score is greater than the computer score, computer wins
        {
            result = ROUNDOUTCOME::COMPUTERWON;
            mBoard.markComputerAsWinner(); //sets computer as the winner for that round
        }
        
        return( result ); //return result
    }
    
    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER; //default state is GAMENOTOVER
        
        if (mBoard.countUpComputerRoundWins() + mBoard.countUpHumanRoundWins() == 6) //when all round are determined...
        {
            if (mBoard.countUpHumanRoundWins() > mBoard.countUpComputerRoundWins()) // if the number of rounds human won is greater than the number of rounds computer won...
            {
                result = GAMEOUTCOME::HUMANWONGAME; //human wins the game
            }
            else if (mBoard.countUpHumanRoundWins() < mBoard.countUpComputerRoundWins()) // if the number of rounds human won is less than the number of rounds computer won...
            {
                result = GAMEOUTCOME::COMPUTERWONGAME; //computer wins the game
            }
            else if (mBoard.countUpHumanRoundWins() == mBoard.countUpComputerRoundWins()) // if the number of rounds human won is equal to the number of rounds computer won...
            {
                result = GAMEOUTCOME::TIEDGAME; //the game is tied
            }
        }
        
        return( result );
    }
    
    // is the game over?
    bool Bunco::gameIsOver() const
    {
        GAMEOUTCOME result = determineGameOutcome();
        return( result != GAMENOTOVER );
    }

}
