//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mRound( 0 )
    {
        // initialize each BoardRow
        for (int i = 1; i <= 6; i++)
        {
            mBoardRow[ i ].setRound( i );
        }
    }
    
    void Board::setCurrentRound( int round )
    {
        // unset the current board row
        if (mRound >= 0 && mRound <= 6)
            mBoardRow[ mRound ].setCurrentRound( false );
        mRound = round;
        // set the current board row
        if (mRound >=0 && mRound <=6)
            mBoardRow[ mRound ].setCurrentRound(true);
    }
    
    void Board::markHumanAsWinner()
    {
        mBoardRow[mRound].setHumanAsWinner(); //makes the human the winner for that round
    }
    
    void Board::markComputerAsWinner()
    {
        mBoardRow[mRound].setComputerAsWinner(); //makes the computer the winner for that round
    }
    
    // stringify the Board
    std::string Board::display( ) const
    {
        std::string s = "\t\t  Bunco Game\n\tHuman\t\t\tComputer\n";
        
        for( int i = 1; i <= 6; i++)
        {
            s += mBoardRow[ i ].display() + "\n";
        }
        
        return( s );
    }
    
    int Board::countUpHumanRoundWins( ) const
    {
        int count = 0;
        for ( int n=1 ; n<7 ; n++) //goes through each element in the array
        {
            if (mBoardRow[n].didHumanWin()) //counts how many times human won
            {
                count++;
            }
        }
        
        return count;
    }
    
    int Board::countUpComputerRoundWins( ) const
    {
        int count = 0;
        for ( int n=1 ; n<7 ; n++) //goes through each element in the array
        {
            if (mBoardRow[n].didComputerWin()) //counts how many times human won
            {
                count++;
            }
        }
        
        return count;
    }

    
}
